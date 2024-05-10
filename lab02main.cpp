// Sp24 CIS22C 61Z
// Lab 2
// Linhnam Le & Andrew Forsberg
// "Currency simulator" demonstrating inheritance, polymorphism, and object manipulation


#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include "Currency.h"
#include "Dollar.h"
#include "Pound.h"

// Global variables
const int CURRENCY_REF_COUNT = 2;

// For comparing two currency objects names 
bool caseInsensitiveStringCompare(const std::string& str1, const std::string& str2) {
    std::string str1Upper = str1;
    std::string str2Upper = str2;

    // Convert both strings to uppercase
    std::transform(str1Upper.begin(), str1Upper.end(), str1Upper.begin(), ::toupper);
    std::transform(str2Upper.begin(), str2Upper.end(), str2Upper.begin(), ::toupper);

    // Compare the uppercase strings
    return str1Upper == str2Upper;
}

// will return the correct currency type based on tokens
Currency* makeCurrency(const std::vector<std::string> tokens){

    try{

      if (tokens[1] == "d"){
        return new Dollar(std::stod(tokens[2]));
      }
      else if(tokens[1] == "p"){
        return new Pound(std::stod(tokens[2]));
      }
      else{
        throw std::invalid_argument("Invalid Currency Type");
      }
      
    }catch(...){ // TODO put proper error
      std::cout << "error";
      return nullptr;
    }
}

// will retrurn a pointer to a currency object that matches string if not in list will return nullptr
Currency* getTarget(std::string searchString , Currency* currencylist[] ) {

  for (int i = 0; i < CURRENCY_REF_COUNT; i++){
    if ( caseInsensitiveStringCompare(currencylist[i]->name(), searchString) ){
      return currencylist[i];
    }
  }

  std::cout << "Currency not found" << std::endl;
  return nullptr;
  
}



int main() {

  
  Currency* currenciesArray[CURRENCY_REF_COUNT];
  
  currenciesArray[0] = new Pound(0.0);
  currenciesArray[1] = new Dollar(0.0);

  

  //TODO ADD ERROR CHECKING
  while(true){

    //Get input
    std::string input = "";
    std::cout << "Enter a command: ";
    std::getline(std::cin, input);
    
    //Tokenize the input
    std::istringstream iss(input);
    std::vector<std::string> tokens;
    std::string token;
    
    while(iss >> token){
      tokens.push_back(token);
    }

  
    if (tokens[0] == "q"){return 0;} //quit program if q is entered

    //currency to add or sub to correct currencyarray Currency
    try {
      Currency* currency = makeCurrency(tokens); 
      Currency* target = getTarget(tokens[3], currenciesArray); //target is a pointer to the correct currency in currencies
      
      if (tokens[0] == "a"){
        target->add(*currency);
      }else if (tokens[0] == "s") {
          target->subtract(*currency);
      }


      
    }catch(std::invalid_argument e){
      std::cout << e.what() << std::endl;
      
    }catch(...){
      std::cout << "error in main" << std::endl;
      
    }

    //prints the results
    
    currenciesArray[0]->print();
    currenciesArray[1]->print();
  }


  /* From the given outputs table:

      "a d 12.12 dollar"
  
    - The first character is 'a' or 's' representing an instruction to either
    add or subtract currency values.
    -The first character can also be 'q' for quit.
    
    - The second character 'p' or 'd' indicates either pound or dollar.

    - Then, a double value is given. I think we should do input validation
    here against negative values.
    
    - input strings "pound" and "dollar" follow, not yet sure what they do
    However, it MUST match "p" or "d" respectively in the second char pos,
    otherwise the program returns "Invalid addition/subtraction"
      - i think this specifies data type of the double value previously given
      i.e. 12.12 dollars, or 3.45 pounds given to existing obj
  */
  return 0;
  
}