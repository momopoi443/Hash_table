
#ifndef LAB2_2_HASHTAB_H
#define LAB2_2_HASHTAB_H

#include "LinkedList.h"
#include "Data.h"


#define EXTENTION_COEF 2.5


class HashTable {

private:

    int capacity;

    int currSize;

    LinkedList* arr;


    void memRealloc(int newCapacity);

    int hash(long long key);

public:

    HashTable(int capacity = 5);

    ~HashTable();


    void insert(long long key, Data value);

    Data* find(long long key);

    void erase(long long key);

    int size();
};


#endif
