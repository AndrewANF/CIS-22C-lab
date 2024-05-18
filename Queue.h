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
}

Queue::~Queue()
{
}



void Queue::enqueue(Currency* newItem){ //TODO

}

Currency* Queue::dequeue(){ //TODO

}

Currency* Queue::peekFront(){ //TODO

}

Currency* Queue::peekRear(){ //TODO

}

void Queue::printQueue(){ //TODO

}

