#pragma once

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <cmath>

// abstract base class called Currency with two integer attributes -- whole
// ... and fractional parts wherein 100 fractional parts = 1 whole part
class Currency {
public:
    Currency(); // default constructor, set int values to 0
    Currency(double &amount);

    Currency(const Currency &other);           // copy constructor
    Currency &operator=(const Currency &rhs);  // copy assign
    ~Currency();                               // destructor

    // setters, getters follow
    int wholePart() const { return _wholePart; }
    int fractPart() const { return _fractPart; }

    // This getter grabs _name, a string native to subclasses Pound & Dollar
    virtual std::string name() const = 0;

    void setWholePart(const int &part) { _wholePart = part; }
    void setFractPart(const int &part) { _fractPart = part; }

    // internal methods follow
    double round100th(const double& amt) const;
    void add(const Currency &other);
    void subtract(const Currency &other); // result should be logical: no negatives
    bool isEqual(const Currency &other) const;
    bool isGreater(const Currency &other) const;
    bool typeCheck(const Currency &other) const;
    void print() const;

private:
    int _wholePart;
    int _fractPart;
};

// Constructors below
Currency::Currency() : _wholePart(0) , _fractPart(0) {} //SHOULD THIS BE SET TO ZERO??

Currency::Currency(double &amount) {
    if (amount < 0) { amount *= -1; } // discards negative sign if necessary

    _wholePart = static_cast<int>(amount);
    _fractPart = static_cast<int>(round100th(amount) * 100) % 100;
}

// Destructor
Currency::~Currency(){
    // nothing to delete at the moment
}

// Copy constructor
Currency::Currency(const Currency &other) {
    _wholePart = other.wholePart();
    _fractPart = other.fractPart();
}

// Copy assignment
Currency &Currency::operator=(const Currency &rhs) {
    // if (this == &rhs) return *this; // bail on self-assignment. TODO: test for exception
    _wholePart = rhs.wholePart();
    _fractPart = rhs.fractPart();
    return *this;
}

/* This method is a quick bug-fix for a precision error. Testing revealed
   some decimal values may be incorrectly interpreted (n.01 - n.08)
   This rounds a passed value to the nearest hundredth by use of <cmath>
     Pre: amt - reference to a double value
    Post: round the passed double value to its nearest hundredth
          e.g. 2.49999999998 -> 2.5
  Return: rounded double
*/
double Currency::round100th(const double& amt) const {
    return (floor(amt*100+0.5)/100);
}

/* This method adds together two Currency objects of same subtype (Dollar, Pound)
     Pre: other - reference to another Currency object
    Post: if other object has a different type than *this, throw exception
          add fractional parts & overflow when > 100
          add whole parts together
  Return: void
*/
void Currency::add(const Currency &other) {
    if (!typeCheck(other)) {
        throw std::invalid_argument("Invalid addition");
    }
    // this->print();
    // other.print();
    int totalFractPart = _fractPart + other.fractPart();
    _wholePart += totalFractPart / 100;  // Carry over to the whole part
    _fractPart = totalFractPart % 100;   // Update fractional part

    _wholePart += other.wholePart();
}

/* This method subtracts (from receiver) a Currency object of same subtype
     Pre: other - reference to another Currency object
    Post: if other object has a different type than *this, throw exception
          subtract whole parts w/ any overflow from fractional parts
          subtract fractional parts while wrapping around 0-100 range
  Return: void
*/
void Currency::subtract(const Currency& other) {
    
    if (!typeCheck(other) || !this->isGreater(other)) {
        throw std::invalid_argument("Invalid subtraction ");
    }
    
    _wholePart -= other.wholePart() - (_fractPart < other.fractPart()); 
    _fractPart = (_fractPart - other.fractPart()) % 100;
}

/* This method evaluates whether two objects are equal in value
     Pre: other - reference to another Currency object
    Post: if other object has a different type than *this, throw exception
          compare both fractional parts
          compare both whole parts
          Return true if both above statements evaluate to true
  Return: true or false
*/
bool Currency::isEqual(const Currency& other) const {
    if (!typeCheck(other)) {
        throw std::invalid_argument("Invalid equality");
    }
    
    return _fractPart == other.fractPart() && _wholePart == other.wholePart();
}

// dollar1.isGreater(dollar2) <-- "is dollar1 greater than dollar1?"
// Returns true if dollar1 is greater, false if dollar1 is not greater

/* This method evaluates whether the receiver is greater than the passed obj
     Pre: other - reference to another Currency object
    Post: if other object has a different type than *this, throw exception
          convert each obj's data to an integer value representing cents
          compare cents value, then return result
  Return: true or false
*/
bool Currency::isGreater(const Currency& other) const {
    if (!typeCheck(other)) {
        throw std::invalid_argument("Invalid comparison");
    }
    
    int thisVal = _wholePart*100 + _fractPart;
    int otherVal = other.wholePart()*100 + other.fractPart();

    return thisVal > otherVal;
}

// JYN: this function handles checking the we are operating on the same
// ... currency types. As it is, it calls the subclass's _name getter and
// ... returns true or false. *** TODO: throw exceptions properly ***

/* This method evaluates the subtypes of a receiver and passed obj
     Pre: other - reference to another Currency object
    Post: 
  Return: true or false
*/
bool Currency::typeCheck(const Currency &other) const {
    return this->name() == other.name();
}

void Currency::print() const {
        std::cout << _wholePart << "." <<
            std::setfill('0') << std::setw(2) << _fractPart <<
            ' ' << name() << std::endl;
}


