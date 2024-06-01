// Lab 4 - 6 June 2024
// BSTNode.h
// Linhnam Le & Andrew Forsberg
// This assignment demonstrates binary search trees

#pragma once

// BSTNode ADT
// This code is templatized for any datatype

//template <typename T>
class BSTNode {
public:
	BSTNode() : _data(0), _left(nullptr), _right(nullptr) {};
	~BSTNode() {};

	void setLeft(BSTNode* left) { _left = left; }
	void setRight(BSTNode* right) { _right = right; }
	BSTNode* left() const { return _left; }
	BSTNode* right() const { return _right; }
	Dollar* data() const { return _data; }

private:
	Dollar* _data;
	BSTNode* _left;
	BSTNode* _right;
};