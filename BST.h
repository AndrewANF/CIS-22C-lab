// Lab 4 - 1 June 2024
// BST.h
// Linhnam Le & Andrew Forsberg
// This assignment demonstrates binary search trees

#ifndef BST_H
#define BST_H

#include "Dollar.h"
#include <queue>

class BSTNode {
public:
	BSTNode() : _data(0), _left(nullptr), _right(nullptr) {};
	BSTNode(Currency* obj) : _data(obj), _left(nullptr), _right(nullptr) {};
	~BSTNode() = default;

	void setLeft(BSTNode* left) { _left = left; }
	void setRight(BSTNode* right) { _right = right; }
	void setData(Currency* data) { _data = data; }
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
	BST(BSTNode* root) : _root(root) {};
	~BST() { empty(); };

	// In this design, some methods are called by the user with no arguments
	// These methods below will call private overload methods which are recursive
	// The recursive implementation passes the "next" node on which to operate
	// This keeps the public-facing interface clean

	void breadth() const;
	void inOrder() const;
	void preOrder() const;
	void postOrder() const;

	BSTNode* search(Currency* target) const;	// Search for node w/ matching value
	void remove(Currency* target);		// Remove node w/ matching value
	void empty();						// Empty da whole thang
	int count() const;					// Count nodes in tree
	void insert(Currency* target);		// Insert a node of this value
	bool isEmpty() const;				// Check if tree is empty
	void print() const;					// Print

private:
	// Following internal methods are recursive:

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

#endif
