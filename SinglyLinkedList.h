#include "LinkNode.h"

class SinglyLinkedList
{
private:
   int _count;
   LinkNode* _start;
   LinkNode* _end;

public:
    SinglyLinkedList(/* args */);
    ~SinglyLinkedList();

    //getters and setters
    int getCount();
    LinkNode* getStart();
    LinkNode* getEnd();

    void addCurrency(Currency* newItem); //not sure where it should be added to.
    void removeCurrency();//Not sure where it should remove from
    void removeCurrency(); //Overloaded version
    int findCurrency(Currency* searchItem);//should returns the index?
    LinkNode* getCurrency(int index);
    void printList();
    bool isListEmpty();
    int countCurrency(); //Not sure what this does

};


int SinglyLinkedList::getCount(){return _count;}
LinkNode* SinglyLinkedList::getStart(){return _start;}
LinkNode* SinglyLinkedList::getEnd(){return _end;}

void SinglyLinkedList::addCurrency(Currency* newItem){ //TODO
    
}
void SinglyLinkedList::removeCurrency(){ //TODO

}
int SinglyLinkedList::findCurrency(Currency* searchItem){ //TODO
   
}

LinkNode* SinglyLinkedList::getCurrency(int index){ //TODO

}
void SinglyLinkedList::printList(){ //TODO

}
bool SinglyLinkedList::isListEmpty(){ //TODO

}
int SinglyLinkedList::countCurrency(){ //TODO

} 


SinglyLinkedList::SinglyLinkedList(/* args */) //TODO
{
}

SinglyLinkedList::~SinglyLinkedList() //TODO
{
}
