#include "BST.h"
#include <queue>

//Destructor TODO
BST::~BST() {
	std::cout << "Destructor called" << std::endl;
}


//this saves and prints the node that is given to a file 
void printValue(BSTNode* node) { //TODO 

	node->data()->print();
	std::cout << " TESTING saveing to file DELETE ME WHEN DONE" << std::endl; //DELETE TESTING ONLY

}


//BFS or lever order traversal will use a queue to traverse though the tree
//It will print out each element and save to a file.
//breadth()
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
void BST::breadth() const { //TODO

if (_root == nullptr) {
  return;
}
  std::queue<BSTNode*> q;
  q.push(this->_root);

  while (q.empty() == false) {
    
    BSTNode* node = q.front();
    
    printValue(node);
    
    q.pop();

    if (node->left() != nullptr) {
      q.push(node->left());
    }
    if (node->right() != nullptr) {
      q.push(node->right());
    }
  }



}


//Inorder will traverse the tree printing and saveing the value of the nodes it comes across
/*
Inorder():
  
*/

void BST::inOrder() const {    //TODO MAKE WITH A STACK OR QUEUE FOR E.C.

inOrder(_root);

}

void BST::inOrder(BSTNode *node) const {
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
