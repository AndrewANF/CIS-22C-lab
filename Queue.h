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
