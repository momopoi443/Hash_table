
#ifndef LAB2_2_LINKEDLIST_H
#define LAB2_2_LINKEDLIST_H


#include "../include/Data.h"

#include <iostream>


class HashNode {

public:

    long long key;
    Data data;
    HashNode* next;

    HashNode(long long key, Data& data);

    ~HashNode() = default;
};

class LinkedList {

private:

    HashNode* head;
    HashNode* tail;

    int currSize;

public:

    //constructor
    LinkedList();


    void pushBack(long long key, Data& data);


    Data popFront();


    long long getKey(int pos);

    void setByKey(long long key, Data value);


    Data* findByKey(long long key);

    int removeByKey(long long key);

    void clear();

    int size();
};


#endif