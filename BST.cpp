#include "BST.h"

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

void BST::inOrder(BSTNode *node) const {
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

void BST::preOrder(BSTNode *node) const {
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
