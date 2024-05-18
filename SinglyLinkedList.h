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

SinglyLinkedList::SinglyLinkedList(/* args */)
{
}

SinglyLinkedList::~SinglyLinkedList()
{
}
