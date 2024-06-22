// Lab 5 - 16 June 2024
// HashTable.h
// Linhnam Le & Andrew Nunez Forsberg
// This assignment demonstrates a Hashtable 

#ifndef HASHTABLE
#define HASHTABLE

#include <vector>
#include "Currency.h"

class HashTable {

public:
    HashTable(int size);
    ~HashTable();

    Currency getValue(int index);       // TODO: returns a Currency object
    int search(Currency& searchValue);  // Searches for a matching object and returns index
    bool insert(Currency& newCurr);     // Return true on success
    bool remove(Currency& targetCurr);  // Return true on success
    void display(); // Prints hash table with indexes

    // Getters follow
    int getCollisions() { return _collisions; }
    double loadFactor() { return static_cast<double>(_currentSize) / _table.size(); }


        void resize();


private:
    // hash and find are kept private. See hashFunc() for hash algorithm
    int hashFunc(double amount);
    int findPosition(Currency& targetCurr); // TODO


    int _currentSize;
    int _collisions;

    std::vector<Currency*> _table;
};








#endif //CURRENCY
