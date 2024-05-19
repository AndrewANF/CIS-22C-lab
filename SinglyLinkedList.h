#pragma once
#include <iostream>
#include "LinkNode.h"

class SinglyLinkedList {
private:
	int _count;
	LinkNode* _start;
	LinkNode* _end;

public:
	SinglyLinkedList(); // by default, inits with dummy node
	~SinglyLinkedList();

	// getters and setters; const for good luck
	int getCount() const { return _count; }
	LinkNode* getStart() const { return _start; }
	LinkNode* getEnd() const { return _end; }

	void setCount(int count) { _count = count; }
	void setStart(LinkNode* start) { _start = start; }
	void setEnd(LinkNode* end) { _end = end; }

	void addCurrency(Currency& newItem, int index);		// adds object at position "index"
	int findCurrency(const Currency& target) const;			// Returns index
	int countCurrency() const;							// Count of all nodes
	Currency* removeCurrency(const Currency& target);	// Removes item if found
	Currency* removeCurrency(int index);				// Removes item at index

	// I think this is supposed to return the Currency obj, not the node
	Currency* getCurrency(int index) const;

	// "string of all the Currency objects in the list in the order of index, tab spaced."
	std::ostringstream printList() const;

	bool isListEmpty() const;
	// student-defined methods are allowed here per instructor

	void indexCheck(int index) const;
};

//     PRE: n/a
//    POST: n/a
//  RETURN: n/a
//  INTENT: Constructor. Creates dummy node to sit at start of list.
SinglyLinkedList::SinglyLinkedList() {
	_start = new LinkNode();
	_end = _start;
	_count = 0;
}

//     PRE: n/a
//    POST: n/a
//  RETURN: n/a
//  INTENT: Destructor. Loops to call each node's destructor.
SinglyLinkedList::~SinglyLinkedList() {
//	LinkNode* node = _start;
//	while (node) {
//		delete node;
//	}
}

//     PRE: newItem - reference to a Currency obj
//    POST: create new LinkNode() with address of newItem
//			insert newNode at specified index
//			increments _count of nodes stored
//  RETURN: n/a
//  INTENT: Adds an object into the linked-list at a given position
void SinglyLinkedList::addCurrency(Currency& newItem, int index) {
	LinkNode* curNode = _start;
	for (int i = 0; i < index; i++) {
		curNode = curNode->_next;
	}
	// creating newNode with address of newItem, whose _next points to the next list-node
	LinkNode* newNode = new LinkNode(&newItem, curNode->_next);
	curNode->_next = newNode;
	if (index == _count-1) { _end = newNode; }
	_count++;
}

//     PRE: target - reference to a Currency obj
//    POST: compare each node in linked-list for a match
//  RETURN: int - index of matching object; sentinel of -1 if not found
//  INTENT: Search linked-list for a Currency object of matching value
int SinglyLinkedList::findCurrency(const Currency& target) const {
	int index = 0;
	LinkNode* node = _start->_next; // Skipping "dummy" node
	while (node) {
		if (target.isEqual(*node->_data)) {
			return index;
		}
		node = node->_next;
		index++;
	}
	return -1; // Return sentinel if matching object not found
}

//     PRE: target - reference to a Currency obj
//    POST: call removeCurrency(int index) to remove a matching obj if found
//  INTENT: Remove a Currency obj from the linked-list (if present)
Currency* SinglyLinkedList::removeCurrency(const Currency& target) {
	int index = findCurrency(target);
	if (index == -1) {
		return nullptr; // Return null if matching object not found
	}
	return removeCurrency(index);
}

//     PRE: index - the index of an object to remove
//    POST: throw exception if argument is invalid
//			search list and remove the first matching obj
//			delete that object's LinkNode
//			decrement _count of nodes stored
//  RETURN: Currency* - data, a ptr to the removed Currency obj
//  INTENT: Remove a Currency obj from the linked-list (if present)
Currency* SinglyLinkedList::removeCurrency(int index) { //TODO
	indexCheck(index);

	LinkNode* curNode = _start->_next; // Skip "dummy" node
	LinkNode* prevNode = _start;
	for (int i = 0; i < index; i++) {
		prevNode = curNode;
		curNode = curNode->_next;
	}
	prevNode->_next = curNode->_next;
	if (index == _count - 1) { _end = prevNode; }
	_count--;
	return curNode->_data;
	// ⚠️ TO-DO: Return copy of object and delete its host list-node
}

//     PRE: int index - index of an object to grab
//    POST: n/a
//  RETURN: Currency* - ptr to the obj at the given index
//  INTENT: Get the pointer to a Currency object at an index
Currency* SinglyLinkedList::getCurrency(int index) const {
	LinkNode* node = _start->_next;
	for (int i = 0; i < index; i++) {
		node = node->_next;
	}
	return node->_data;
}

//     PRE: n/a
//    POST: n/a
//  RETURN: ostringstream - see below
//  INTENT: "Returns a string of all the Currency objects in the list in the order of index, tab spaced."
std::ostringstream SinglyLinkedList::printList() const {
	std::ostringstream output;
	for (int i = 0; i < _count; i++) {
		Currency* target = getCurrency(i);
		output << target->wholePart() << "." << std::setfill('0') << std::setw(2)
			<< target->fractPart() << ' ' << target->name() << '\t';
		// EX: 57.12 dollar    23.44 dollar    87.43 dollar    68.99 dollar    ...
		// ⚠️ TO-DO: (maybe) pluralize Currency name where applicable
	}
	return output;
}

//     PRE: n/a
//    POST: n/a
//  RETURN: bool, true or false
//  INTENT: Method determines if list is empty by checking if _count is 0
bool SinglyLinkedList::isListEmpty() const {
	return _count == 0;
}
// return _start->_next == nullptr && _end->_next == nullptr

//     PRE: n/a
//    POST: n/a
//  RETURN: int - essentially a getter for _count
//  INTENT: 
int SinglyLinkedList::countCurrency() const {
	return _count;
}
/*
	int count = 0;
	LinkNode* node = _start;

	while (node) {
		count++;
		node = node->_next;
	}

	return count;
*/

//     PRE: int index - an integer to check
//    POST: throw exception if index is outside of acceptable bounds
//  RETURN: n/a
//  INTENT: Verify that an input index is within the bounds of this linked-list
//			or if the list is empty
void SinglyLinkedList::indexCheck(int index) const {
	if (isListEmpty()) {
		throw std::invalid_argument("List is empty");
	}

	if (0 > index || index >= _count) {
		throw std::invalid_argument("Index out-of-bounds");
	}
}