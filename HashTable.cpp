#include "HashTable.h"


HashTable::HashTable(int size) : _table(size , nullptr), _currentSize(0) , _collisions(0) {}

HashTable::~HashTable() {}

int HashTable::hashFunc(double amount) {return 0;} //TODO

int HashTable::findPosition(Currency& targetCurr) {return 0;} //TODO

bool HashTable::insert(Currency& newCurr) { std::cout << "Testing insert" << std::endl ; return false;} //TODO

Currency getValue(int index); // TODO

int HashTable::search(Currency& searchValue) {return 0;} //TODO

bool HashTable::remove(Currency& targetCurr) {return false;} //TODO

void HashTable::display() {} //TODO



