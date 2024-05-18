#include "SinglyLinkedList.h"

class Stack : public SinglyLinkedList{

public:

    Stack();
    ~Stack();

    void push(Currency* newItem);
    Currency* pop();
    Currency* peek();
    void printStack();

};