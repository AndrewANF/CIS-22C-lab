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
	void breadth(BSTNode* node) const;
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

BST::~BST() {
	std::cout << "Destructor called" << std::endl;
}

void BST::breadth() const {
	if (isEmpty()) {
		std::cout << "breadth called but list empty" << std::endl;
		return;
	}
	breadth(_root);
}

void BST::breadth(BSTNode* node) const {
	if (node) {
		// something with vectors
	}
}

void BST::inOrder() const {
	if (isEmpty()) {
		std::cout << "inOrder called but list empty" << std::endl;
		return;
	}
	inOrder(_root);
}

void BST::inOrder(BSTNode* node) const {
	if (node) {
		inOrder(node->left());
		node->data()->print();
		inOrder(node->right());
	}

}

void BST::preOrder() const {
	if (isEmpty()) {
		std::cout << "preOrder called but list empty" << std::endl;
		return;
	}
	preOrder(_root);
}

void BST::preOrder(BSTNode* node) const {
	if (node) {
		node->data()->print();
		preOrder(node->left());
		preOrder(node->right());
	}
}

void BST::postOrder() const {
	if (isEmpty()) {
		std::cout << "postOrder called but list empty" << std::endl;
		return;
	}
	postOrder(_root);
}

void BST::postOrder(BSTNode* node) const {
	if (node) {
		postOrder(node->left());
		postOrder(node->right());
		node->data()->print();
	}
}

BSTNode* BST::search(Currency* target) const {
	return search(_root, target);
}

BSTNode* BST::search(BSTNode* node, Currency* target) const {
	if (node) {
		if (node->data()->isEqual(*target)) {
			return node;
		}
		else if (node->data()->isGreater(*target)) {
			return search(node->left(), target);
		}
		else {
			return search(node->right(), target);
		}
	}
	return nullptr;
}

// Iterative insert method
void BST::insert(Currency* target) {
	_root = insert(_root, target);
}

BSTNode* BST::insert(BSTNode* node, Currency* target) {
	if (!node) {
		return new BSTNode(target);
	}
	if (node->data()->isGreater(*target)) {
		node->setLeft(insert(node->left(), target));
	}
	else if (!(node->data()->isGreater(*target))) {
		node->setRight(insert(node->right(), target));
	}
	return node;
}

void BST::remove(Currency* target) {
	remove(_root, target);
}

BSTNode* BST::remove(BSTNode* node, Currency* target) {
	if (node == nullptr) {
		return nullptr;
	}



}

void BST::empty() {
	if (isEmpty()) { return; }
	empty(_root);
	_root = nullptr;
}

void BST::empty(BSTNode* node) {
	if (node != nullptr) {
		empty(node->left());
		empty(node->right());
		delete node;
	}

}

bool BST::isEmpty() const {
	return _root == nullptr;
}

int BST::count() const {
	return count(_root);
}

int BST::count(BSTNode* node) const {
	if (!node) { return 0; }
	return 1 + count(node->left()) + count(node->right());
}

void BST::print() const {

}

#endif
