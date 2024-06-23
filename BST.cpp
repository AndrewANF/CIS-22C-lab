// Lab 4 - 1 June 2024
// BST.cpp
// Linhnam Le & Andrew Forsberg
// This assignment demonstrates binary search trees
#include "BST.h"
#include <iostream>
#include <ostream>
#include <queue>
#include <fstream>
#include <sstream>

//this saves and prints the node that is given to a file 
/*
pre: BSTNode* node
post: n/a
return: void
*/
void printValue(BSTNode* node) { //TODO 

    std::stringstream ss;

    ss << node->data()->wholePart() << "." << node->data()->fractPart();

    std::string formattedString = ss.str();


  std::cout << formattedString << ", ";
  


	// std::ofstream outfile("output.txt" , std::ios_base::app);

    // if (outfile.is_open()) {
        
    //     outfile << formattedString << ", ";

        
    //     outfile.close();
    // } else {
        
    //     std::cerr << "Unable to open file for writing." << std::endl;
    // }
}

// BFS or level order traversal will use a queue to traverse though the tree
// It will print out each element and save to a file.
// pre:	self
// post: 	printed tree
// return:	void
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

BSTNode* BST::getRoot(){
	return _root;
}
void BST::setRoot(BSTNode* newValue){
	_root = newValue;
}


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

/*
inorder will print to screen and output the inOrder traversel of the tree
pre:	self
post: 	printed tree
return:	void

*/

void BST::inOrder() const { // TODO MAKE WITH A STACK OR QUEUE FOR E.C.
	if (isEmpty()) {
		std::cout << "inOrder called but list empty" << std::endl;
		return;
	}
	inOrder(_root);
}
//helper meathod for recursion
//pre:	root of tree
//post: printed tree
//return: void
void BST::inOrder(BSTNode* node) const {
	if (node) {
		inOrder(node->left());
		printValue(node);
		inOrder(node->right());
	}

}
/*
will print to terminal and output.txt the pre-order trversal of the tree
pre: na
post: printed tree
return void
*/
void BST::preOrder() const { // TODO MAKE WITH A STACK OR QUEUE FOR E.C.
	if (isEmpty()) {
		std::cout << "preOrder called but list empty" << std::endl;
		return;
	}
	preOrder(_root);
}
/*
helper function preOrder to enable recursion
*/
void BST::preOrder(BSTNode* node) const {
	if (node) {
		printValue(node);
		preOrder(node->left());
		preOrder(node->right());
	}
}

/*
will print to terminal and output.txt the post-order traversal of the tree
pre: na
post: printed tree
return void
*/
void BST::postOrder() const { // TODO MAKE WITH A STACK OR QUEUE FOR E.C.
	if (isEmpty()) {
		std::cout << "postOrder called but list empty" << std::endl;
		return;
	}
	postOrder(_root);
}
/*
Helper method to enable recursion for postOrder
*/
void BST::postOrder(BSTNode* node) const {
	if (node) {
		postOrder(node->left());
		postOrder(node->right());
		printValue(node);

	}
}


/*
searches the tree for a target currency
pre: Currency* targer
post: na
return: pointer to currency obj or nullptr if not found
*/
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
/*
pre: Currency* targer
post: root with new node
return : void
*/
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
/*
pre: Currency* targer
post: removed target if found. 
return: void
*/
void BST::remove(Currency* target) {
    _root = remove(_root, target);
}
//remove helper function to enable recursion
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
        
        if (node->left() == nullptr) {

            BSTNode* temp = node->right();
            delete node;
            return temp;

        } else if (node->right() == nullptr) {

            BSTNode* temp = node->left();
            delete node;
            return temp;

        }

        
        BSTNode* successor = node->right();

        while (successor && successor->left() != nullptr) {
            successor = successor->left();
        }

        
        node->setData(successor->data());
        node->setRight(remove(node->right(), successor->data()));

    } else if (node->data()->isGreater(*target)) {

        node->setLeft(remove(node->left(), target));
    } else {

        node->setRight(remove(node->right(), target));
    }

    return node;
}


//Method to empty tree
/*
pre: na
post: emptyed tree
return : void
*/
void BST::empty() {
	if (isEmpty()) { return; }
	empty(_root);
	_root = nullptr;
}
//helper function to enable recusion for empty
void BST::empty(BSTNode* node) {
	if (node != nullptr) {
		empty(node->left());
		empty(node->right());
		delete node;
	}

}

//isEmpty will return false if the tree is empty
/*
pre: na
post: na
return: true if empty else false
*/
bool BST::isEmpty() const {
	return _root == nullptr;
}

//count will return the number of nodes in the tree
/*
pre: na
post: na
return: int number of nodes in tree
*/
int BST::count() const {
	return count(_root);
}
//helper function for count to enable recusion
int BST::count(BSTNode* node) const {
	if (!node) { return 0; }
	return 1 + count(node->left()) + count(node->right());
}

void BST::print() const {
  std::cout << "\nBreadth : ";
  breadth();
  std::cout << "\nIn Order : ";
  inOrder();
  std::cout << "\nPre Order : ";
  preOrder();
  std::cout << "\nPost Order : ";
  postOrder();
}

void BST::logger(Currency* target) const {
	
}
