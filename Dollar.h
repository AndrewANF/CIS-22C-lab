#ifndef DOLLAR
#define DOLLAR

#include "Currency.h"

// United States Dollar
class Dollar : public Currency {
public:
    Dollar();
    Dollar(double amount);

    /* Inline getter for private variable _name
         Pre: n/a
        Post: n/a
      Return: string _name native to Dollar subclass
    */
    std::string name() const override { return _name; }

private:
    std::string _name = "Dollar";
};

// default constructor
inline Dollar::Dollar() : Currency() {};

// constructor given monetary value
inline Dollar::Dollar(double amount) : Currency(amount) {};

#endif //DOLLAR
