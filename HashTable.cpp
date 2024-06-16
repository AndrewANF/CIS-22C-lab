#include "HashTable.h"
#include <cmath>
#include <iostream>


HashTable::HashTable(int size) : _table(size , nullptr), _currentSize(0) , _collisions(0) {}

HashTable::~HashTable() {}

int HashTable::hashFunc(double amount) {
  
  int m = 2;
  int n = 3;
  int w = static_cast<int>(amount);

  double integerPart;
  double fractionalPart = std::modf(amount, &integerPart) * 100;

  int f = static_cast<int>(std::round(fractionalPart));

  return (m*w + n*f) % _table.size();
} 

int HashTable::findPosition(Currency& targetCurr) {return 0;} //TODO

bool HashTable::insert(Currency& newCurr) { std::cout << "Testing insert" << std::endl ; return false;} //TODO

Currency getValue(int index); // TODO

int HashTable::search(Currency& searchValue) {return 0;} //TODO

bool HashTable::remove(Currency& targetCurr) {return false;} //TODO

void HashTable::display() {} //TODO



