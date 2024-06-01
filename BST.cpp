#include "BST.h"

void BST::breadthFirst() {
	if (isEmpty()) return; // do nothing on empty list

	BSTNode* node = this->_root;
	// probably will use a vector of pointers to each node
}

void BST::inOrder() {
	if (isEmpty()) return; // do nothing on empty list
	
	BSTNode* node = this->_root;
	inOrder(node->left);
	node->data()->print();
	inOrder(node->right);
}

void BST::preOrder() {
	if (isEmpty()) return; // do nothing on empty list

	BSTNode* node = this->_root;
	node->dollar()->print();
	preOrder(node->left);
	preOrder(node->right);
}

void BST::postOrder() {
	if (isEmpty()) return; // do nothing on empty list

	BSTNode* node = this->_root;
	postOrder(node->left);
	postOrder(node->right);
	node->dollar()->print();
}

BSTNode* BST::search(double target) {

}

BSTNode* BST::insert(double target) {

}

BSTNode* BST::remove(double target) {

}

void BST::empty() {

}

bool BST::isEmpty() const {

}

int BST::count() const {

}

void BST::print() const {

}