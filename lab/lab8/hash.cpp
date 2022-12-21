#include <iostream>
#include "hash.h"

HashTable::HashTable(int c) {
    int size = getPrime(c);
    this->capacity = size;
    table = new std::list<int>[capacity];
}

int HashTable::checkPrime(int n) {
    if (n == 1 || n == 0){
        return 0;
    }
    for (int i = 2; i < n / 2; i++){
        if (n % i == 0){
            return 0;
        }
    }
    return 1;
}
void HashTable::insertItem(int key, int data) {
    int index = hashFunction(key);
    table[index].push_back(data); 
}
void HashTable::deleteItem(int key) {
    int index = hashFunction(key);
    std::list<int>::iterator i;
    for (i = table[index].begin(); i != table[index].end(); i++) {
        if (*i == key) {
            break; 
        }
        if (i != table[index].end()) table[index].erase(i);

    }
}
void HashTable::displayHash() {
    for (int i = 0; i < capacity; i++){
        std::cout << "table[" << i << "]";
        for (auto x : table[i]) std::cout << "--> " << x << std::endl;;
    }
    std::cout << std::endl;
}
int HashTable::getPrime(int n) {
    if (n % 2 == 0){
        n++;
    }
    while (!checkPrime(n)){
        n += 2;
    }
    return n;
}
