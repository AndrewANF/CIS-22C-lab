// Lab 4 - 1 June 2024
// BST.cpp
// Linhnam Le & Andrew Forsberg
// This assignment demonstrates binary search trees
#pragma once
#include "BST.h"
#include <queue>
#include <fstream>

//this saves and prints the node that is given to a file 
void printValue(BSTNode* node) { //TODO 

	node->data()->print();
	std::cout << " TESTING saveing to file DELETE ME WHEN DONE" << std::endl; //DELETE TESTING ONLY

}

// BFS or level order traversal will use a queue to traverse though the tree
// It will print out each element and save to a file.
// breadth()
/*
 if (root = nullptr):
   return

  create queue = q
  q.enque root

  while q.isEmpty == false

	//prints current node
	new node = q.front
	print node
	save node to file
	q.pop()

	//enques next node
	if node.left != nullptr
	  q.enque(node.left)

	if node.right != nullptr
	  q.enque(node.right)
  endloop
 */

void BST::breadth() const {
	if (isEmpty()) {
		std::cout << "breadth called but list empty" << std::endl;
		return;
	}

	std::queue<BSTNode*> q;
	q.push(_root);

	while (!q.empty()) {
		BSTNode* currentNode = q.front();
		q.pop();

		currentNode->data()->print();

		if (currentNode->left()) q.push(currentNode->left());
		if (currentNode->right()) q.push(currentNode->right());
	}
}

void BST::inOrder() const { // TODO MAKE WITH A STACK OR QUEUE FOR E.C.
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

void BST::preOrder() const { // TODO MAKE WITH A STACK OR QUEUE FOR E.C.
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

void BST::postOrder() const { // TODO MAKE WITH A STACK OR QUEUE FOR E.C.
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
	return nullptr; // returns null if node not found
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
	else if (!node->data()->isGreater(*target)) {
		node->setRight(insert(node->right(), target));
	}
	return node;
}

// User-facing method, calls recursive remove
void BST::remove(Currency* target) {
	remove(_root, target);
}

// TODO: this method can be rewritten to call search()
// and operate on the node it finds

BSTNode* BST::remove(BSTNode* node, Currency* target) {
	if (node == nullptr) {
		return nullptr; // do nothing on empty tree
	}

	if (node->data()->isGreater(*target)) {
		node->setLeft(remove(node->left(), target));
	}
	else if (!node->data()->isGreater(*target)) {
		node->setRight(remove(node->right(), target));
	}
	else {
		if (node->left() == nullptr) {
			BSTNode* temp = node->right();
			delete node;
			return temp;
		}
		else if (node->right() == nullptr) {
			BSTNode* temp = node->right();
			delete node;
			return temp;
		}

		// Go right, then travel down left-child to find next node
		BSTNode* successor = node->right();
		while (successor && successor->left() != nullptr) {
			successor = successor->left();
		}

		// Clone successor's data to current node
		node->setData(successor->data());

		// Remove the successor node that we just cloned
		node->setRight(remove(node->right(), successor->data()));
	}
	return node;
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

void BST::logger(Currency* target) const {
	
}
