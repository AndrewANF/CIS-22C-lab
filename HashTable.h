#ifndef HASHTABLE
#define HASHTABLE


#include <vector>
#include "Currency.h"

class HashTable{

  public:

// Constructor to init hash table to size
    HashTable(int size = 29);
    
    // Hash table Destuctor
    ~HashTable();
    
    // 
    Currency getValue(int index);

    int search(Currency& searchValue);

    bool insert(Currency& newCurr);

    bool remove(Currency& targetCurr);

    int getCollisions() { return _collisions ;}

    double loadFactor() { return static_cast<double>(_currentSize) / _table.size(); }

    void display();

  private:

    int _currentSize;

    int _collisions;

    std::vector<Currency*> _table;

    int hashFunc(double amount);

    int findPosition(Currency& targetCurr);
    
};








#endif //CURRENCY
