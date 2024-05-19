#include "SinglyLinkedList.h"

class Stack : public SinglyLinkedList {
public:
    Stack();

    void push(Currency& newItem);
    Currency* pop();
    Currency* peek();
    std::ostringstream printStack();
};

//     PRE: n/a
//    POST: n/a
//  RETURN: n/a
//  INTENT: 
Stack::Stack() {
    SinglyLinkedList();
}

//     PRE: n/a
//    POST: n/a
//  RETURN: n/a
//  INTENT: 


//     PRE: n/a
//    POST: n/a
//  RETURN: n/a
//  INTENT: 
void Stack::push(Currency& newItem) {  //TODO
    addCurrency(newItem, 0);
}

//     PRE: n/a
//    POST: n/a
//  RETURN: n/a
//  INTENT: 
Currency* Stack::pop() { //TODO
    Currency* target = getCurrency(0);
    removeCurrency(0);
    return target;
}

//     PRE: n/a
//    POST: n/a
//  RETURN: n/a
//  INTENT: 
Currency* Stack::peek() {
    return getCurrency(0);
}

//     PRE: n/a
//    POST: n/a
//  RETURN: n/a
//  INTENT: 
std::ostringstream Stack::printStack() { //TODO
    return printList();
}
