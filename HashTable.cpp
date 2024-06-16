#include "HashTable.h"
#include "Currency.h"
#include <cmath>
#include <iostream>
#include <ostream>


HashTable::HashTable(int size) : _table(size , nullptr), _currentSize(0) , _collisions(0) {}

HashTable::~HashTable() {}

int HashTable::hashFunc(double amount) {
  
  int m = 2;
  int n = 3;
  int w = static_cast<int>(amount);

  double integerPart;
  double fractionalPart = std::modf(amount, &integerPart) * 100;

  int f = static_cast<int>(std::round(fractionalPart));

  return (m*w + n*f);
} 

int HashTable::findPosition(Currency& targetCurr) {return 0;} //TODO

bool HashTable::insert(Currency& newCurr){

  int i = 0;
  int bucketsProbed = 0;
  double currValue = (newCurr.wholePart() + (newCurr.fractPart() / 100.0));

  int bucket = hashFunc(currValue) % _table.size();

  while (bucketsProbed < _table.size()) {
 
     // std::cout << currValue<< " : " << bucket << "-----";
    if (_table[bucket] == nullptr) {
      _table[bucket] = &newCurr;
      _currentSize++;
      return true;
    }

    //increment i by 1
    _collisions += 1;
    i += 1;
    bucket = ( hashFunc(currValue)  + (1*i) + (1*i*i) ) % _table.size();
    //std::cout << bucket << "|" << std::endl;
  }

  return false;
} //TODO

Currency getValue(int index); // TODO

int HashTable::search(Currency& searchValue) {  


  std::cout << "test1";
  int index = -1;
  int i = 0;
  int bucketsProbed = 0;
  double currValue = (searchValue.wholePart() + (searchValue.fractPart() / 100.0));

  std::cout << "test2";
  int bucket = hashFunc(currValue) % _table.size();

  while (bucketsProbed <= _table.size()) {
 
    if (_table[bucket]->isEqual(searchValue)) {
      index = bucket;
      break;
    } else if (_table[bucket] == nullptr) {
      break;
    }
    std::cout << "test3";
    //increment i by 1
    i += 1;
    bucketsProbed += 1;
    bucket = ( hashFunc(currValue)  + (1*i) + (1*i*i) ) % _table.size();

    std::cout << bucketsProbed << " ";

  }

  return index;
} //TODO

bool HashTable::remove(Currency& targetCurr) {return false;} //TODO

void HashTable::display() {

  
  for (int bucket = 0; bucket < _table.size(); bucket++) {
  
    std::cout << bucket << ": ";
    if (_table[bucket] == nullptr) {
      std::cout << "Empty" << std::endl;
    }else {
      std::cout << _table[bucket]->wholePart() << "." << _table[bucket]->fractPart() << std::endl;
    } 
  }

  std::cout << "Data Items Loaded: " << _currentSize << std::endl;
  std::cout << "Load Factor: " << loadFactor() << std::endl;
  std::cout << "Number Of Collisions: " << _collisions << std::endl;
}

 
