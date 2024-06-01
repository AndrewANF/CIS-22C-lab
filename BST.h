// Lab 4 - 6 June 2024
// BST.h
// Linhnam Le & Andrew Forsberg
// This assignment demonstrates binary search trees

#pragma once

// Binary search tree implementation
// This code is designed for Dollar objects

class BST {
public:
	BST() {
		_root = nullptr;
	}
	~BST();

	// four traversal methods
	void breadthFirst();
	void inOrder();
	void preOrder();
	void postOrder();

	BSTNode* search(double target);	// Search for node w/ matching value
	BSTNode* insert(double target); // Insert a node of this value
	BSTNode* remove(double target); // Remove node w/ matching value
	void empty();					// Empty da whole thang
	bool isEmpty() const;			// Check if tree is empty
	int count() const;				// Count nodes in tree
	void print() const;				// Print

private:
	BSTNode* _root;
};