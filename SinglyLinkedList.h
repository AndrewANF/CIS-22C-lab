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

	void addCurrency(Currency* newItem, int index);		// adds object at position "index"
	int findCurrency(Currency* target) const;			// Returns index
	int countCurrency() const;							// Count of all nodes
	Currency* removeCurrency(const Currency& other);	// Removes item if found
	Currency* removeCurrency(int index);				// Removes item at index

	// I think this is supposed to return the Currency obj, not the node
	Currency* getCurrency(int index) const;

	// "string of all the Currency objects in the list in the order of index, tab spaced."
	void printList() const;

	bool isListEmpty() const;
		// student-defined methods are allowed here per instructor
};


SinglyLinkedList::SinglyLinkedList() {
	_start = new LinkNode();
	_end = _start;
	_count = 0;
}

// Call each node's destructor
SinglyLinkedList::~SinglyLinkedList() {
	LinkNode* node = _start;
	while (node) {
		delete node;
	}
}

// ingests the reference to an object, passes its pointer into the list
// requires "index" to add Currency at
// Because of the dummy node, this is effectively an InsertAfter function
void SinglyLinkedList::addCurrency(Currency* newItem, int index) { //TODO
	LinkNode* curNode = _start;
	for (int i = 0; i < index; i++) {
		curNode = curNode->_next;
	}
	// creating new node whose data points to newItem, whose next points to the next listnode
	LinkNode* newNode = new LinkNode(newItem, curNode->_next);
	curNode->_next = newNode;
}

int SinglyLinkedList::findCurrency(Currency* target) const {
	int index = 0;
	LinkNode* node = _start;
	while (node) {
		if (target->isEqual(*node->_data)) {
			return index;
		}
		index++;
		node = node->_next;
	}
	return -1; // Sentinel indicating target obj not found
}

Currency* SinglyLinkedList::removeCurrency(const Currency& other) { //TODO
	LinkNode* curNode = _start;
	LinkNode* prevNode = nullptr;
	while (curNode ) {
		prevNode = curNode;
		curNode = curNode->_next;
	}
	return nullptr;
}

Currency* SinglyLinkedList::removeCurrency(int index) { //TODO
	return nullptr;
}

Currency* SinglyLinkedList::getCurrency(int index) const { //TODO
	return nullptr;
}

void SinglyLinkedList::printList() const { //TODO

}

// true indicates empty list
bool SinglyLinkedList::isListEmpty() const { //TODO
	return _start == nullptr && _end == nullptr;
}

int SinglyLinkedList::countCurrency() const { //TODO
	int count = 0;
	LinkNode* node = _start;

	while (node) {
		count++;
		node = node->_next;
	}

	return count;
}
