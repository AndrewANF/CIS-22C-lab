// Lab 4 - 1 June 2024
// BST.h
// Linhnam Le & Andrew Forsberg
// This assignment demonstrates binary search trees

#ifndef BST_H
#define BST_H

#include "Dollar.h"

class BSTNode {
public:
	BSTNode() : _data(0), _left(nullptr), _right(nullptr) {};
	BSTNode(Currency* obj) : _data(obj), _left(nullptr), _right(nullptr) {};
	~BSTNode() {};

	void setLeft(BSTNode* left) { _left = left; }
	void setRight(BSTNode* right) { _right = right; }
	BSTNode* left() const { return _left; }
	BSTNode* right() const { return _right; }
	Currency* data() const { return _data; }

private:
	Currency* _data;
	BSTNode* _left = nullptr;
	BSTNode* _right = nullptr;
};

class BST {
public:
	BST() : _root(nullptr) {};
	~BST();

	// Traversal methods: in this design, the user will call these methods
	// with no arguments. These methods below will call the private over-
	// load methods because the recursive implementation passes the "next"
	// node on which to operate; this keeps the public-facing interface clean.
	void breadth() const;
	void inOrder() const;
	void preOrder() const;
	void postOrder() const;

	void remove(Currency* target);	// Remove node w/ matching value
	BSTNode* search(Currency* target) const;	// Search for node w/ matching value
	void empty();						// Empty da whole thang
	int count() const;					// Count nodes in tree
	void insert(Currency* target);		// Insert a node of this value
	bool isEmpty() const;				// Check if tree is empty
	void print() const;					// Print

private:
	// Following internal methods are recursive:
	void breadth(BSTNode* node) const; //TODO: REMOVE 
 	void inOrder(BSTNode* node) const;
	void preOrder(BSTNode* node) const;
	void postOrder(BSTNode* node) const;

	BSTNode* remove(BSTNode* node, Currency* target);
	BSTNode* search(BSTNode* node, Currency* target) const;
	void empty(BSTNode* node);
	int count(BSTNode* node) const;
	BSTNode* insert(BSTNode* node, Currency* target);

	BSTNode* _root;
};

// move this out to BST.cpp later

#endif
