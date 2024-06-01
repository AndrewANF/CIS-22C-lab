// Lab 4 - 6 June 2024
// lab4.cpp
// Linhnam Le & Andrew Forsberg
// This assignment demonstrates binary search trees

#include <iostream>
#include "Currency.h"
#include "Dollar.h"
#include <vector>

using namespace std;

int main()
{
	std::cout << "Hello World!\n";
	BST* tree = new BST();
	tree->inOrder();

	vector<Currency*> currencies;
	for (int i = 0; i < SIZE; i++) {
		currencies.push_back(new Dollar(TEST_VALS[i]));
	}

	for (int i = 0; i < SIZE; i++) {
		tree->insert(currencies.at(i));
	}
	tree->inOrder();

	cout << "Count: " << tree->count() << endl;

	tree->empty();

	cout << "isEmpty: " << tree->isEmpty() << endl;

	cout << "loading things" << endl;


	return 0;
}
