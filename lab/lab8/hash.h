#include<iostream>
#include<list>


class HashTable {
private:
	unsigned int capacity;
	std::list<int>* table; 
public:
	HashTable(int V);
	void insertItem(int key, int data);
	void deleteItem(int key);
	void displayHash();
	int checkPrime(int);
	int getPrime(int);
	int hashFunction(int key) { return key % capacity; }

};