*******************************
*                             *
*     Things to remember:     *
*                             *
*******************************

    Create exactly four code files - one each for the Currency, Dollar and Pound classes and one for the main. For C++ students, code your class declarations and definitions in the same file.
    The files should be named 'currency.xxx', 'dollar.xxx', 'pound.xxx' and 'lab2main.xxx' with the appropriate extension in place of xxx.
    ✅ Your 3 currency classes should have pre/post documentation for the methods that are not constructors / destructors. For the setters/getters, you can combine the pre/post into one for all the setters and one for all the getters. See Design Tools and Documentation.pdf 

Download Design Tools and Documentation.pdf for documentation help.
No pseudocode is needed for any class or main.
✅ Also, remember to include name blocks in all the code files.
For the submission, name your zip file as 'lab2.zip'.
Your zip file should only contain 4 code files and as many screenshots as needed to clearly demonstrate the above sample in an easy to read magnification. For any additional file or folders (when unzipped on a windows machine) or non-specified file types, submission related deductions will be made.

***************************************************
*                                                 *
*     Programming problem: Currency Simulator     *
*                                                 *
***************************************************

  A. ✅ Create an abstract base class called Currency with two integer attributes, both of which are non-public (Python programmers - it is understood that there is nothing private in Python but try to not access the attributes directly from outside the classes). The int attributes will represent whole part (or currency note value) and fractional part (or currency coin value) such that 100 fractional parts equals 1 whole part. 

  B. ✅ Create two derived classes - Dollar and Pound - with one additional non-public string attribute which will contain the name of the currency (Dollar or Pound) respectively. DO NOT add this attribute to the base Currency class.I ju

  C. In your base Currency class, add public methods for the following, where appropriate (C++ students are allowed to use friend methods as overloads only, i.e. the corresponding class method needs to be defined first):
w
    ✅ Default Construction (i.e. no parameters passed).
    ✅ Construction based on one single input of type double - create logical objects only, i.e. no negative value objects allowed.
    ✅ Copy Constructor and/or Assignment (i.e. the input is an object of the same class), as applicable to your programming language of choice.
    ✅ Destructor, as applicable to your programming language of choice.
    ✅ Setters and Getters for all attributes, as may be necessary.
    ✅ A method called add for adding an input object of the same currency.
    ✅ A method called subtract for subtracting an input object of the same currency - the result should be logical, i.e. negative results are not allowed.
    ✅ A method called isEqual for comparing an input object of the same currency for equality/inequality.
    ✅ A method called isGreater for comparing an input object of the same currency to identify which object is larger or smaller.
    ✅ A method called print to print the name and value of a currency object in the form "xx.yy" followed by the derived currency name, e.g. 1.23 Dollar or 2.46 Pound.
    - All of the above should be instance methods and not static.
    ⚠️ The add and subtract as specified should manipulate the object on which they are invoked. It is allowed to have overloaded methods that create and return new objects .

  D.✅ In your derived Dollar and Pound classes, add new methods or override inherited methods as necessary, taking care that code should not be duplicated or duplication minimized. Think modular and reusable code.

  E. Remember -

    - Only the print method(s) in the classes should print anything to console, besides the main below.
    - Throw String (or equivalent) exceptions from within the classes to ensure that invalid objects cannot be created.
    - In all methods, ensure that you are not mixing objects of different currencies.

  F. In your main:

    - Declare a primitive array of 2 Currency references (for C++ programmers, array of 2 Currency pointers).
    - Set the first reference in the array to a Pound object and the second reference to a Dollar object, both of zero value.
    - Then perform the sequence of operations as in the sample input/output below, understanding that your program will be tested with a different sequence of operations using the same patterns.
    - All operations in the main should be performed on Currency objects demonstrating polymorphism. 
    - Remember to handle exceptions appropriately.
    - Sample input / output for your main - remember my test program will follow the same pattern but not the same sequence:

  EVENT SEQUENCE |   SAMPLE INPUT   |  SAMPLE OUTPUT
  ---------------|------------------|-------------------------
  Program start  |                  |  0.00 Pound 0.00 Dollar
  Add pound obj  | a p 1.11 pound   |  1.11 Pound 0.00 Dollar
  Add dollar obj | a d 12.12 dollar |  1.11 Pound 12.12 Dollar
  
  Add pound obj  | a d 3.45 pound   |  Invalid addition
                 |                  |  1.11 Pound 12.12 Dollar
  _
  Add dollar obj | a d 0.13 dollar  |  1.11 Pound 12.25 Dollar
  Sub dollar obj | s d 10 dollar    |  1.11 Pound 2.25 Dollar
  
  Sub dollar obj | s d 2.5 dollar   |  Invalid subtraction
                 |                  |  1.11 Pound 2.25 Dollar
  _
  Sub pound obj  | s p 0.11 pound   |  1.00 Pound 2.25 Dollar
  End program    | q                |

