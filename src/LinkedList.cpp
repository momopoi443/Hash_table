
#include "../include/LinkedList.h"


//HashDone constructor
HashNode::HashNode(long long key, Data &data)  {

    this->key = key;
    this->data = data;
    this->next = nullptr;
}


//list constructor
LinkedList::LinkedList() {

    this->head = nullptr;

    this->tail = nullptr;

    this->currSize = 0;
}


//back/front methods
void LinkedList::pushBack(long long key, Data &data) {

    auto* newNode = new HashNode(key, data);

    if (this->currSize == 0) {

        this->head = newNode;

        this->tail = newNode;

        this->currSize++;

        return;
    }

    this->tail->next = newNode;

    this->tail = newNode;

    currSize++;
}

Data LinkedList::popFront() {

    if (this->currSize == 0) {

        std::cout << "list empty" << std::endl;

        return Data();
    }

    HashNode* buffer = this->head->next;

    Data toReturn = this->head->data;


    delete this->head;

    head = buffer;

    this->currSize--;


    return toReturn;
}


//getters/setters
long long LinkedList::getKey(int pos) {

    if (pos < 0 || pos >= this->currSize) {

        std::cout << "out of scope" << std::endl;

        return -1;
    }

    HashNode* buffer = this->head;

    for (int i = 0; i < pos; ++i) {

        buffer = buffer->next;
    }

    return buffer->key;
}

void LinkedList::setByKey(long long key, Data value) {

    HashNode* buffer = this->head;


    while(buffer->key != key) {

        buffer = buffer->next;
    }


    buffer->data = value;
}


//other
Data *LinkedList::findByKey(const long long key) {

    HashNode* buffer = this->head;

    while (buffer) {

        if (buffer->key == key) {

            return & (buffer->data);
        }

        buffer = buffer->next;
    }

    return nullptr;
}

int LinkedList::removeByKey(long long key) {

    HashNode* toDel = this->head;

    HashNode* prev = nullptr;

    while (toDel) {

        if (toDel->key == key) {

            if (prev) {

                prev->next = toDel->next;
            } else {

                this->head = toDel->next;
            }

            delete toDel;

            this->currSize--;

            return 1;
        }

        prev = toDel;

        toDel = toDel->next;
    }

    return -1;
}

void LinkedList::clear() {

    while(this->head) {

        HashNode* ToDel = this->head;

        this->head = ToDel->next;

        delete ToDel;
    }

    this->tail = nullptr;

    this->currSize = 0;
}

int LinkedList::size() {

    return this->currSize;
}