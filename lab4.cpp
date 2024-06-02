// Lab 4 - 1 June 2024
// lab4.cpp
// Linhnam Le & Andrew Forsberg
// This assignment demonstrates binary search trees

#include <iostream>
#include <vector>
#include "BST.h"
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

	// Four traversal methods. TODO: write to output log

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

	/*********************************************/

	string line;
	do {
		cout << "Commands: add, remove, search, exit" << endl;
		cout << "For add/remove/search, enter a currency value, e.g. \"add 12.44\"" << endl;

		getline(cin, line);
		stringstream ss(line);

		string operation;
		string value;

		ss >> operation >> value;

	} while (1);

	return 0;
}


