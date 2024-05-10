#include "Currency.h"

// British Pound sterling
class Pound : public Currency {
public:
    Pound();
    Pound(double amount);

    /* Inline getter for private variable _name
         Pre: n/a
        Post: n/a
      Return: string _name native to Pound subclass
    */
    std::string name() const override { return _name; }

private:
    std::string _name = "pound"; // TODO change back to "Pound"
};

// default constructor
Pound::Pound() : Currency() {};

// constructor given monetary value
Pound::Pound(double amount) : Currency(amount) {};