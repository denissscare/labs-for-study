static int hashword(uint32 c)
{
   uint32 a,b;
   a = b = 0x9e3779b9;
   a -= b; a -= c; a ^= (c>>13);
   b -= c; b -= a; b ^= (a<<8);
   c -= a; c -= b; c ^= (b>>13);
   a -= b; a -= c; a ^= (c>>12);
   b -= c; b -= a; b ^= (a<<16);
   c -= a; c -= b; c ^= (b>>5);
   a -= b; a -= c; a ^= (c>>3);
   b -= c; b -= a; b ^= (a<<10);
   c -= a; c -= b; c ^= (b>>15);
   return c;
}

#define KEY_NULL 0
#define KEY_DELETED 1

typedef struct
{
   uint32 key, value;
} Item;

typedef struct
{
   int mask;
   Item *data;
   int has_key[2];
   uint32 value[2];
   int data_len;
   int population, deletes;
   int grow_size, shrink_size, delete_size; 
   void *free_ptr;
} Hash;

#define OVERAGE 1


void *hashCreate(int size)
{
   Hash *h = malloc(sizeof(*h));
   if (size < 8) size = 8;
   assert(nongreater_power_of_two(size) == size);
   h->data_len = size;
   h->mask = size-1; 
   h->population = h->deletes = 0;
   h->has_key[0] = h->has_key[1] = 0;
   h->grow_size = (int) (size * hash_table_max_full) - 1;
   if (h->grow_size < 2) h->grow_size = 2;
   h->shrink_size = (int) (size * hash_table_empty);
   if (h->data_len == 8) h->shrink_size = 0;
   h->delete_size = (int) (size * hash_delete_rehash) - 1;
   h->data = calloc(sizeof(h->data[0]), size+OVERAGE*2);
   h->free_ptr = h->data;
   h->data += OVERAGE;
   return h;
}

void hashFree(void *h)
{
   free(((Hash *) h)->free_ptr);
   free(h);
}

uint32 *hashFind(void *hash, uint32 key)
{
   Hash *d = (Hash *) hash;
   Item *z = d->data;
   uint32 mask = d->mask;

   uint32 h = hashword(key);
   uint32 p = h & mask;
   uint32 s;

   if (key <= KEY_DELETED) {
      if (d->has_key[key]) return &d->value[key];
      return NULL;
   }

   if (z[p].key == key) return &z[p].value;
   if (z[p].key == KEY_NULL) return NULL;

   s = (((h >> 16) | (h << 16)) & mask) | 1;
   assert(d->population + d->deletes != d->data_len);
   do {
      p = (p + s) & mask;
      if (z[p].key == key) return &z[p].value;
   } while (z[p].key != KEY_NULL);

   return NULL;
}

static void rehash(Hash *h, int len)
{
   Hash *d = hashCreate(len);
   int i;
   
   ++rehashes;

   for (i=0; i < h->data_len; ++i) {
      if (h->data[i].key > KEY_DELETED) {
         uint32 *p = hashInsert(d, h->data[i].key);
         assert(p != NULL);
         *p = h->data[i].value;
      }
   }
   assert(h->population == d->population);

   free(h->free_ptr);
   for (i=0; i < 2; ++i)
      d->has_key[i] = h->has_key[i],
      d->value[i] = h->value[i];
   memcpy(h, d, sizeof(*h));
   free(d);
}

uint32 *hashInsert(void *hash, uint32 key)
{
   Hash *d = (Hash *) hash;
   Item *z = d->data;
   uint32 mask = d->mask;
   int f = -1;

   uint32 h = hashword(key);
   uint32 p = h & mask;
   uint32 s;

   if (key <= KEY_DELETED) {
      d->has_key[key] = 1;
      return &d->value[key];
   }

   if (z[p].key == key) return &z[p].value;
   if (z[p].key == KEY_DELETED) f = p;
   if (z[p].key > KEY_NULL) {
      s = (((h >> 16) | (h << 16)) & mask) | 1;
      assert(d->population + d->deletes != d->data_len);
      do {
         p = (p + s) & mask;
         if (z[p].key == key) return &z[p].value;
         if (z[p].key == KEY_DELETED && f == -1) f = p;
      } while (z[p].key > KEY_NULL);
   }

   if (z[p].key == KEY_NULL && d->population >= d->grow_size) {
      rehash(d, d->data_len * 2);
      return hashInsert(hash, key);
   } else if (d->population + d->deletes > d->delete_size) {
      rehash(d, d->data_len);
      return hashInsert(hash, key);
   } else {
      if (f >= 0) p = f;
      if (z[p].key == KEY_DELETED) --d->deletes;
      z[p].key = key;
      ++d->population;
      return &z[p].value;
   }
}

int hashDelete(void *hash, uint32 key)
{
   Hash *h = (Hash *) hash;
   Item *p;
   uint32 *value = hashFind(hash, key);
   if (value == NULL) return 0;
   if (key <= KEY_DELETED) {
      h->has_key[key] = 0;
      return 1;
   }
   p = (Item *) (value-1);
   p->key = KEY_DELETED;
   --h->population;
   ++h->deletes;
   if (h->population < h->shrink_size)
      rehash(h, h->data_len >> 1);
   else if (h->population + h->deletes >= h->delete_size)
      rehash(h, h->data_len);
   return 1;
}

int hashCount(void *hash)
{
   Hash *h = hash;
   return h->population + h->has_key[KEY_NULL] + h->has_key[KEY_DELETED];
}

int hashMem(void *hash)
{ 
    return sizeof(Hash) + sizeof(Item) * ((Hash *) hash)->data_len;
}
