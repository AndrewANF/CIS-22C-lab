#pragma once
#include "SinglyLinkedList.h"

class Queue : public SinglyLinkedList
{
public:
    Queue();
    ~Queue();

    void enqueue(Currency* newItem);
    Currency* dequeue();
    Currency* peekFront();
    Currency* peekRear();
    void printQueue();


};

Queue::Queue()
{
    SinglyLinkedList();
}

Queue::~Queue()
{
    ~SinglyLinkedList();
}



void Queue::enqueue(Currency* newItem) { //TODO
    int endex = count == 0 ? 0 : count - 1;
    addCurrency(newItem, endex);
}

Currency* Queue::dequeue() { //TODO
    Currency* target = getCurrency(0);
    removeCurrency(0);
    return target;
}

Currency* Queue::peekFront() { //TODO
    
}

Currency* Queue::peekRear() { //TODO

}

void Queue::printQueue() { //TODO

}
