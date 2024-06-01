// Lab 4 - 1 June 2024
// lab4.cpp
// Linhnam Le & Andrew Forsberg
// This assignment demonstrates binary search trees

#include <iostream>
#include <vector>
#include "BST.h"

using namespace std;

const int SIZE = 20;
const double TEST_VALS[SIZE] = {
	57.12, 23.44, 87.43, 68.99, 111.22, 44.55, 77.77, 18.36, 543.21, 20.21,
	345.67, 36.18, 48.48, 101.00, 11.00, 21.00, 51.00, 1.00, 251.00, 151.00
};

int main()
{
	std::cout << "Hello World!\n";
	BST* tree = new BST();
	tree->inOrder();

	vector<Currency*> currencies;
	//for (int i = 0; i < SIZE; i++) {
	//	currencies.push_back(new Dollar(TEST_VALS[i]));
	//}

	//for (int i = 0; i < SIZE; i++) {
	//	tree->insert(currencies.at(i));
	//}
	tree->inOrder();

	cout << "Count: " << tree->count() << endl;

	tree->empty();

	cout << "isEmpty: " << tree->isEmpty() << endl;

	cout << "loading things" << endl;

	return 0;
}


