// Lab 5 - 16 June 2024
// lab5.cpp
// Linhnam Le & Andrew Nunez Forsberg
// This assignment demonstrates a Hashtable



#include "Dollar.h"
#include "HashTable.h"
#include <vector>


using namespace std;




const int SIZE = 20;
const double TEST_VALS[SIZE] = {
	57.12, 23.44, 87.43, 68.99, 111.22, 44.55, 77.77, 18.36, 543.21, 20.21,
	345.67, 36.18, 48.48, 101.00, 11.00, 21.00, 51.00, 1.00, 251.00, 151.00
};

int main()
{

  //create hash table
  HashTable table(29);

	// Data seeding 
  
  for (double num : TEST_VALS) {

    Dollar* insertedDollar = new Dollar(num);
    table.insert(*insertedDollar); 
    
  }
  
  table.display();


  while(true){

    //Get input
    std::string input = "";
    cout << "\n\nCommands: search, quit" << endl;
	  cout << "For search enter a currency value, e.g. \"search 12.44\"" << endl;
    std::getline(std::cin, input);
    
    //Tokenize the input
    std::istringstream iss(input);
    std::vector<std::string> tokens;
    std::string token;


    while(iss >> token){
      tokens.push_back(token);
    }

    if (tokens[0] == "q" || tokens[0] == "quit"){return 0;} //quit program if q is entered
    
    if( tokens[0] == "search"){
      
      cout << "seaching TODO" << endl;//TODO

      Dollar seachCurr(stod(tokens[1]));
      table.search(seachCurr);


    }

  }


  return 0;
}
