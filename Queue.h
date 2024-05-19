#pragma once
#include "SinglyLinkedList.h"

class Queue : public SinglyLinkedList
{
public:
    Queue();

    void enqueue(Currency& newItem);
    Currency* dequeue();
    Currency* peekFront();
    Currency* peekRear();
    std::ostringstream printQueue();


};

Queue::Queue()
{
    SinglyLinkedList();
}

void Queue::enqueue(Currency& newItem) { //TODO
    int endex = countCurrency() == 0 ? 0 : countCurrency() - 1;
    addCurrency(newItem, endex);
}

Currency* Queue::dequeue() { //TODO
    Currency* target = getCurrency(0);
    removeCurrency(0);
    return target;
}

Currency* Queue::peekFront() { //TODO
    return getCurrency(0);
}

Currency* Queue::peekRear() { //TODO
    int endex = countCurrency() == 0 ? 0 : countCurrency() - 1;
    return getCurrency(endex);
}

std::ostringstream Queue::printQueue() { //TODO
    return SinglyLinkedList::printList();
}
