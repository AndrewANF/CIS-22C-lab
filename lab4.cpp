// Lab 4 - 1 June 2024
// lab4.cpp
// Linhnam Le & Andrew Forsberg
// This assignment demonstrates binary search trees

#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include "BST.h"
#include "Dollar.h"
#include <sstream>
#include <fstream>

using namespace std;




void clearfile(){
	    std::ofstream ofs("output.txt", std::ios::trunc);
    
    // Check if the file was opened successfully
    if (!ofs) {
        std::cout << "error opening file" << std::endl;
    }

    // Close the file
    ofs.close();
}

void appendAndClose(std::string messege) {

	std::ofstream outfile("output.txt" , std::ios_base::app);

    
    if (outfile.is_open()) {
        
        outfile << messege << std::endl;

        
        outfile.close();
    } else {
        
        std::cerr << "Unable to open file for writing." << std::endl;
    }


}

void appendAndClose(std::string messege , string additionalInfo) {

	std::ofstream outfile("output.txt" , std::ios_base::app);

    
    if (outfile.is_open()) {
        
        outfile << messege << additionalInfo << std::endl;

        
        outfile.close();
    } else {
        
        std::cerr << "Unable to open file for writing." << std::endl;
    }


}

//valid is any number thats not negitive 
bool valid(string currencyValue){

  try {
    if (stod(currencyValue) < 0) {
    return false;
  }
  } catch (...) {

   return false;
  
  }
  return true;
}

void traverse(BST* tree){

  appendAndClose("\nBFS");
	cout << "\nBreadth follows:" << endl;
	tree->breadth();

	appendAndClose("\ninOrder");
	cout << "\ninOrder follows:" << endl;
	tree->inOrder();

	appendAndClose("\npreOrder");
	cout << "\npreOrder follows:" << endl;
	tree->preOrder();
	
	appendAndClose("\npostOrder");
	cout << "\npostOrder follows:" << endl;
	tree->postOrder();

  appendAndClose("-------------------------------------------------");

}

const int SIZE = 20;
const double TEST_VALS[SIZE] = {
	57.12, 23.44, 87.43, 68.99, 111.22, 44.55, 77.77, 18.36, 543.21, 20.21,
	345.67, 36.18, 48.48, 101.00, 11.00, 21.00, 51.00, 1.00, 251.00, 151.00
};

int main()
{
	//clears file 
	clearfile();


	// Data seeding

	BST* tree = new BST();
	tree->inOrder();

	vector<Currency*> currencies;
	for (int i = 0; i < SIZE; i++) {
		currencies.push_back(new Dollar(TEST_VALS[i]));
	}

	for (int i = 0; i < SIZE; i++) {
		tree->insert(currencies.at(i));
	}

	/*********************************************/

	// Four traversal methods. 

  traverse(tree);
	/*********************************************/



  while(true){

    //Get input
    std::string input = "";
    cout << "\nCommands: add, remove, search, quit" << endl;
	  cout << "For add/remove/search, enter a currency value, e.g. \"add 12.44\"" << endl;
    std::getline(std::cin, input);
    
    //Tokenize the input
    std::istringstream iss(input);
    std::vector<std::string> tokens;
    std::string token;


    while(iss >> token){
      tokens.push_back(token);
    }

    if (tokens[0] == "q" || tokens[0] == "quit"){return 0;} //quit program if q is entered

    
    if (tokens[0] == "add") {

      for (int i = 1; i < tokens.size(); i++) {
        if (valid(tokens[i])) {
          //write to screen and output
          cout << "Inserting value : " << tokens[i] << endl;
          appendAndClose("\ninserting value : " , tokens[i]);

          //perform op
          Dollar* newNode = new Dollar(std::stof(tokens[i]));
          tree->insert(newNode);
        }else {
          //if invalid value enterd
          cout << "Invalid Value entered : " << tokens[i] << endl;
          appendAndClose("\nInvalid Value entered : " , tokens[i]);
        } 
      }
      
      traverse(tree);
    }

    if (tokens[0] == "remove") {
      for (int i = 1; i < tokens.size(); i++) {
        if (valid(tokens[i])) {


          Dollar* newNode = new Dollar(std::stof(tokens[i]));
          stringstream ss;
          ss << newNode->wholePart() << "." << newNode->fractPart(); 

          if (!(tree->search(newNode) == nullptr)) {
            //write to screen and output
            cout << "removeing node : " << tokens[i] << endl;
            appendAndClose("\nremoveing node : " , tokens[i]);

            //perform op
            
            tree->remove(newNode);
          }else {
            //if invalid value entered
            cout << "Unable to remove node. Node not found : " << ss.str() << endl;
            appendAndClose("\nUnable to remove node. Node not found :" , ss.str());
          } 
        }else {
          cout << "Invalid Value entered : " << tokens[i] << endl;
          appendAndClose("\nInvalid Value entered : " , tokens[i]);
        }
      }
      traverse(tree);
    }
  
      if (tokens[0] == "search") {



      for (int i = 1; i < tokens.size(); i++) {
        if (valid(tokens[i])) {
          Dollar* newNode = new Dollar(std::stof(tokens[i]));

          stringstream ss;
          ss << "\n" << newNode->wholePart() << "." << newNode->fractPart(); 

          if ((tree->search(newNode)) != nullptr){
            cout << ss.str() << ": Found";
            appendAndClose(ss.str(), ": Found");
          }else {
            cout << ss.str() << ": Not Found";
            appendAndClose(ss.str(), ": Not Found");

          }
        }else {
          //if invalid value enterd
          cout << "Invalid Value entered : " << tokens[i] << endl;
          appendAndClose("\nInvalid Value entered : " , tokens[i]);
        }
      }
    }
  }
  return 0;
}
