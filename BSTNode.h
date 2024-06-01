// Lab 4 - 6 June 2024
// BST.h
// Linhnam Le & Andrew Forsberg
// This assignment demonstrates binary search trees


// Binary search tree implementation
#include "Currency.h"

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
