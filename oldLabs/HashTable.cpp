// Lab 5 - 16 June 2024
// HashTable.cpp
// Linhnam Le & Andrew Nunez Forsberg
// This assignment demonstrates a Hashtable

#include "HashTable.h"
#include "Currency.h"
#include <cmath>
#include <iostream>
#include <ostream>

HashTable::HashTable(int size) : _table(size, nullptr), _currentSize(0), _collisions(0) {}
HashTable::~HashTable() {}

// Hash algorithm as given by lab instructions:
// (m * w + n * f) % size
//    where size = 29
//          m = 2
//          n = 3
//          w = whole value
//          f = fractional value.

int HashTable::hashFunc(double amount) {
    int m = 2;
    int n = 3;
    int w = static_cast<int>(amount);

    double integerPart;
    double fractionalPart = std::modf(amount, &integerPart) * 100;

    int f = static_cast<int>(std::round(fractionalPart));

    return (m * w + n * f);
}


bool isPrime(int n){

    if (n <= 1) return false;
    if (n <= 3) return true;

    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}




int nextPrime(int n){

    if (n <= 1) return 2;

    int prime = n;
    while (!isPrime(prime)) {
        prime++;
    }

    return prime;

}




int HashTable::findPosition(Currency& targetCurr) { return 0; } // TODO

// Collision resolution: use quadratic probing in the same direction always
// Remember to circle around to the start of the array if needed.
bool HashTable::insert(Currency& newCurr) {
    int i = 0;
    int bucketsProbed = 0;
    double currValue = (newCurr.wholePart() + (newCurr.fractPart() / 100.0));

    int bucket = hashFunc(currValue) % _table.capacity();

 
    while (bucketsProbed < _table.capacity()) {

        // std::cout << currValue<< " : " << bucket << "-----";
        if (_table[bucket] == nullptr) {
            _table[bucket] = &newCurr;
            _currentSize++;

            if (loadFactor() > .6 ) {

                std::cout << "Load Factor Exceeds .6 ! \nresizing.\nReseting collision count " << std::endl;
                resize();
                }



            return true;
        }

        // increment i by 1
        _collisions += 1;
        i += 1;
        bucket = (hashFunc(currValue) + (1 * i) + (1 * i * i)) % _table.capacity();
        //std::cout << bucket << "|" << std::endl;
    }

    return false;
}

Currency getValue(int index); // TODO

int HashTable::search(Currency& searchValue) {

    // std::cout << "Entering HashTable::search()..." << std::endl;
    int index = -1;
    int i = 0;
    int bucketsProbed = 0;
    double currValue = (searchValue.wholePart() + (searchValue.fractPart() / 100.0));

    // std::cout << "Initializing..." << std::endl;
    int bucket = hashFunc(currValue) % _table.size();

    // loop and probe thru buckets
    while (bucketsProbed <= _table.size()) {
        // std::cout << "Accessing table at index " << bucket << std::endl;

        // JYN: This conditional will "catch" an empty bucket, otherwise search() will
        // try to call isEqual() on a nullptr. Returns -1 and goes back to main
        // The order is important!
        if (_table[bucket] == nullptr) {
            break;
        }
        else if (_table[bucket]->isEqual(searchValue)) {
            index = bucket;
            break;
        }
        // std::cout << "Entering while loop..." << std::endl;
        //increment i by 1
        i += 1;
        bucketsProbed += 1;
        bucket = (hashFunc(currValue) + (1 * i) + (1 * i * i)) % _table.size();

        // std::cout << bucketsProbed << " ";
        // std::cout << "Probe success..." << std::endl;
    }

    return index;
}

bool HashTable::remove(Currency& targetCurr) { return false; } // TODO

void HashTable::display() {
    for (int bucket = 0; bucket < _table.size(); bucket++) {
        std::cout << bucket << ": ";

        if (_table[bucket] == nullptr) {
            std::cout << "Empty" << std::endl;
        }
        else {
            std::cout << _table[bucket]->wholePart() << "." << _table[bucket]->fractPart() << std::endl;
        }
    }

    std::cout << "Data Items Loaded: " << _currentSize << std::endl;
    std::cout << "Load Factor: " << loadFactor() << std::endl;
    std::cout << "Number Of Collisions: " << _collisions << std::endl;
}

void HashTable::resize(){

  int newSize = nextPrime(_table.size()*2);
  std::vector<Currency*> temp = _table;

  _table.resize(newSize);
  _currentSize = 0;
  _collisions = 0;

  for (int i = 0; i < newSize ; i++) {
    _table[i] = nullptr;
  }

  for (Currency* i  : temp) {
    if (!(i == nullptr)) {
      insert(*i);
    } 
  }
}

