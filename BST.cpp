// Lab 4 - 1 June 2024
// BST.cpp
// Linhnam Le & Andrew Forsberg
// This assignment demonstrates binary search trees
#include "BST.h"
#include <ostream>
#include <queue>
#include <fstream>
#include <sstream>

//this saves and prints the node that is given to a file 
void printValue(BSTNode* node) { //TODO 

    std::stringstream ss;

    ss << node->data()->wholePart() << "." << node->data()->fractPart();

    std::string formattedString = ss.str();


  std::cout << formattedString << ", ";
  


	std::ofstream outfile("output.txt" , std::ios_base::app);

    
    if (outfile.is_open()) {
        
        outfile << formattedString << ", ";

        
        outfile.close();
    } else {
        
        std::cerr << "Unable to open file for writing." << std::endl;
    }



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

		printValue(currentNode);

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
		printValue(node);
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
		printValue(node);
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
		printValue(node);

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
    _root = remove(_root, target);
}

BSTNode* BST::remove(BSTNode* node, Currency* target) {
    if (node == nullptr) {
        return nullptr; // Base case: node not found
    }

    // Search for the node to remove
    BSTNode* targetNode = search(target);
    if (targetNode == nullptr) {
        return node; // Target node not found
    }

    if (node == targetNode) {
        // Node with only one child or no child
        if (node->left() == nullptr) {
            BSTNode* temp = node->right();
            delete node;
            return temp;
        } else if (node->right() == nullptr) {
            BSTNode* temp = node->left();
            delete node;
            return temp;
        }

        // Node with two children: Get the in-order successor (smallest in the right subtree)
        BSTNode* successor = node->right();
        while (successor && successor->left() != nullptr) {
            successor = successor->left();
        }

        // Copy the successor's data to this node
        node->setData(successor->data());

        // Delete the successor
        node->setRight(remove(node->right(), successor->data()));
    } else if (node->data()->isGreater(*target)) {
        node->setLeft(remove(node->left(), target));
    } else {
        node->setRight(remove(node->right(), target));
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
