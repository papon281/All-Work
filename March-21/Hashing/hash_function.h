#ifndef HASH_FUNCTION_H
#define HASH_FUNCTION_H
#include <set>

using namespace std;
class Hash{
    int* linearHashTable;
    int* quadraticHashTable;
    int* doubleHashTable;
    set<int> distinct;
    int tableSize;
    int prime;

public:
    Hash(int _size);
    void getKey(double factor);
    int hash_fct(int k, int m);
    void linearInsert(int key);
    int linearSearch(int key);
    void quadraticInsert(int key);
    int quadraticSearch(int key);
    int _hash(int k);
    void doubleInsert(int key);
    int doubleSearch(int key);
    void rehash();
};

#endif
