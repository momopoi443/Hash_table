
#include "../include/HashTab.h"


//private methods
void HashTable::memRealloc(int newCapacity) {

    LinkedList* oldArr = this->arr;

    this->arr = new LinkedList[newCapacity];

    int oldCapacity = this->capacity;

    this->capacity = newCapacity;


    int elCounter = 0;

    for (int i = 0; i < oldCapacity && elCounter <= this->currSize; ++i) {

        int buffSize = oldArr[i].size();

        for (int j = 0; j < buffSize; ++j) {

            long long buffKey = oldArr[i].getKey(0);

            int newPos = this->hash(buffKey);

            Data buffer = oldArr[i].popFront();

            arr[newPos].pushBack(buffKey, buffer);

            elCounter++;
        }
    }

    delete[] oldArr;
}

int HashTable::hash(long long key) {

    return ((7 * key + 17) % 9149658775000477) % this->capacity;
}


//constructor/destructor
HashTable::HashTable(int capacity) {

    this->capacity = capacity;

    this->currSize = 0;

    this->arr = new LinkedList [capacity];
}

HashTable::~HashTable() {

    for (int i = 0; i < capacity; ++i) {

        this->arr[i].clear();
    }

    delete[] arr;
}


//public methods
void HashTable::insert(long long key, Data value) {

    if ((double) this->currSize / this->capacity > 1.5) {

        this->memRealloc(capacity * EXTENTION_COEF);
    }


    int pos = this->hash(key);


    if (this->find(key) != nullptr) {

        this->arr[pos].setByKey(key, value);

        return;
    }


    this->arr[pos].pushBack(key, value);

    this->currSize++;
}

Data* HashTable::find(long long key) {

    int pos = this->hash(key);

    return this->arr[pos].findByKey(key);
}

void HashTable::erase(long long key) {

    if ((double) this->currSize / this->capacity < 0.3) {

        this->memRealloc(capacity / EXTENTION_COEF);
    }

    int pos = this->hash(key);

    if (arr[pos].removeByKey(key) == 1) {

        currSize--;
    }
}

int HashTable::size() {

    return this->currSize;
}


