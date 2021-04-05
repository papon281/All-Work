#include <iostream>
#include <stdlib.h>
#include <set>
#include <time.h>
#include <stdio.h>
#include "hash_function.h"

using namespace std;

//Constructor for initialize table size and hash array
Hash :: Hash(int _size)
{
    tableSize = _size;
    linearHashTable = new int[_size];
    quadraticHashTable = new int[_size];
    doubleHashTable = new int[_size];
    //get prime number for double hashing
    prime = 7;

    for (int i = 0; i < tableSize; i++)
    {
        linearHashTable[i] = -1;
        quadraticHashTable[i] = -1;
        doubleHashTable[i] = -1;
    }
}

// function to generate key
void Hash :: getKey()
{
    int cnt = 0,x = 0;
    //if x is less than 1000, then continue generate distinct keys
    while(x < 1000)
    {
        cnt += 100;
        srand(cnt);
        // Load factor calculated
        double loadFactor = (double)(distinct.size()) / (double) (tableSize);

        // If the load factor is > 0.50, rehashing is done
        if(loadFactor > 0.5)
        {
            rehash();
        }

        //generate distinct random value
        int key = rand() % 999999999 + 1;
        if(distinct.find(key)== distinct.end())
        {
            distinct.insert(key);
            linearInsert(key);
            quadraticInsert(key);
            doubleInsert(key);
            x++;
        }
    }
}
// function to calculate first hash
int Hash :: hash_fct(int k, int m)
{
    return (k % m);
}
// function to calculate second hash for double hashing
int Hash :: _hash(int key)
{
    return (prime - (key % prime));
}

// function to insert key into hash table
void Hash :: linearInsert(int key)
{
    int index = hash_fct(key, tableSize);
    // if  collision occurs
    while(linearHashTable[index] != -1)
    {
        index++;

        // get newIndex
        index = index % tableSize;
    }
    // if no collision occurs, store the key
    linearHashTable[index] = key;
}

// function to search key in hash table
int Hash :: linearSearch(int key)
{
    int index = hash_fct(key, tableSize);

    // if  collision occurs
    while(linearHashTable[index] != -1)
    {
        if(linearHashTable[index] == key)
        {
            return linearHashTable[index];
            break;
        }
        index++;
        index = index % tableSize;
    }
    return -1;
}

// function to quadratic insert key into hash table
void Hash :: quadraticInsert(int key)
{
    int index = hash_fct(key, tableSize);
    int i = 1;
    while(quadraticHashTable[index] != -1)
    {
        index = index + (i * i);
        index = index % tableSize;
        i++;
    }
    quadraticHashTable[index] = key;
}

// function to quadratic search key in hash table
int Hash :: quadraticSearch(int key)
{
    int index = hash_fct(key, tableSize);
    int i = 1;
    while(quadraticHashTable[index] != -1)
    {
        if(quadraticHashTable[index] == key)
        {
            return quadraticHashTable[index];
            break;
        }
        index = (index + (i * i)) % tableSize;
        i++;
    }
    return -1;
}

// function to insert key into hash table
void Hash :: doubleInsert(int key)
{
    // get index from first hash
    int index = hash_fct(key, tableSize);

    // get index from second hash
    int index1 = _hash(key);
    int i = 1;

    // if collision occurs
    while(doubleHashTable[index] != -1)
    {
        // get newIndex
        index = (index + (i * index1)) % tableSize;
        i++;
    }

    // if no collision occurs
    doubleHashTable[index] = key;
}

// function to search key in hash table
int Hash :: doubleSearch(int key)
{

    int index = hash_fct(key, tableSize);
    int index1 = _hash(key);
    int i = 1;

    while(doubleHashTable[index] != -1)
    {
        if(doubleHashTable[index] == key)
        {
            return doubleHashTable[index];

        }
        index = (index + (i * index)) % tableSize;
        i++;
    }

    return -1;
}

// function to re-hashing
void Hash :: rehash()
{
    //store current table size
    int oldSize = tableSize;

    //declare new table size
    tableSize = (tableSize * 2) + 1;
    //declare new hash table
    int* newLinearTable = new int[tableSize];
    int* newQuadraticTable = new int[tableSize];
    int* newDoubleTable = new int[tableSize];
    //initialize new hash table
    for(int i = 0 ; i < tableSize ; i++)
    {
        newLinearTable[i] = -1;
        newQuadraticTable[i] = -1;
        newDoubleTable[i] = -1;
    }

// In rehash insert linearHash.
    for(int i = 0; i < oldSize; i++)
    {
        if(linearHashTable[i] != -1)
        {
            int index = hash_fct(linearHashTable[i], tableSize);
            while(newLinearTable[index] != -1)
            {
                index++;
                index = index % tableSize;
            }
            newLinearTable[index] = linearHashTable[i];
        }
    }

    //delete the memory of old table
    delete[] linearHashTable;
    //copy the new table data into current table
    linearHashTable = newLinearTable;

    // In rehash insert QuadraticHash.
    for(int i = 0; i < oldSize; i++)
    {
        if(quadraticHashTable[i] != -1)
        {
            int index = hash_fct(quadraticHashTable[i], tableSize);
            int j = 1;
            while(newQuadraticTable[index] != -1)
            {
                index = (index + (j * j)) % tableSize;
                j++;
            }
            newQuadraticTable[index] = quadraticHashTable[i];
        }
    }

     //delete the memory of old table
    delete[] quadraticHashTable;
    //copy the new table data into current table
    quadraticHashTable = newQuadraticTable;

    // In rehash insert doubleHash.
    for(int i = 0; i < oldSize; i++)
    {
        if(doubleHashTable[i] != -1)
        {
            int index = hash_fct(doubleHashTable[i], tableSize);
            int index1 = _hash(doubleHashTable[i]);
            int j = 1;
            while(newDoubleTable[index] != -1)
            {

                index = (index + (j * index1)) % tableSize;
                j++;
            }
            newDoubleTable[index] = doubleHashTable[i];
        }
    }
     //delete the memory of old table
    delete[] doubleHashTable;
    //copy the new table data into current table
    doubleHashTable = newDoubleTable;
}
