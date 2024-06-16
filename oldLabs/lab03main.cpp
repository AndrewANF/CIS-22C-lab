#include <iostream>
#include <vector>
#include <sstream>
#include "Currency.h"
#include "Dollar.h"
#include "SinglyLinkedList.h"
#include "LinkNode.h"
#include "Stack.h"
#include "Queue.h"

const int SIZE = 20;
const double TEST_VALS[SIZE] = {
	57.12, 23.44, 87.43, 68.99, 111.22, 44.55, 77.77, 18.36, 543.21, 20.21,
	345.67, 36.18, 48.48, 101.00, 11.00, 21.00, 51.00, 1.00, 251.00, 151.00
};

using namespace std;

int main()
{
	std::cout << "Lab 3 written by Linhnam Le & Andrew Forsberg ...\n";

	Currency* currencies[SIZE] = { 0 };
	for (int i = 0; i < SIZE; i++) {
		currencies[i] = new Dollar(TEST_VALS[i]);
	}

	SinglyLinkedList list;
	for (int i = 0; i < 7; i++) {
		list.addCurrency(*currencies[i], 0);
	}

	// Search for $87.43
	Dollar target1(87.43);
	int key = list.findCurrency(target1);
	if (key == -1) {
		cout << "Searching for 87.43: No matching object found (-1)" << endl;
	}
	else {
		cout << "Searching for 87.43: Matching object found at index " << key << endl;
	}

	// Search for $44.566

	Dollar target2(44.56);
	key = list.findCurrency(target2);
	if (key == -1) {
		cout << "Searching for 44.56: No matching object found (-1)" << endl;
	}
	else {
		cout << "Searching for 44.56: Matching object found at index " << key << endl;
	}

	// Remove $111.22, then index 2, then print
	Dollar target3(111.22);
	list.removeCurrency(target3);
	list.removeCurrency(2);
	cout << list.printList().str() << endl;

	// Add 4 objects, from 9-12
	for (int i = 9; i <= 12; i++) {
		list.addCurrency(*currencies[i], i % 5);
	}

	// Remove 2 objects & print
	list.removeCurrency(list.countCurrency() % 6);
	list.removeCurrency(list.countCurrency() / 7);
	cout << list.printList().str() << endl;

	Stack stack;

	// Add 7 objects from 13-20
	for (int i = 7; i <= 20; i++) {
		stack.push(*currencies[i]);
	}

	cout << "Peeking stack: ";

	return 0;
}
