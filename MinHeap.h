
//Min heap inharets from BinarySearchTree(BST) and Overrides search insert and delete
#include "BST.h"
#include "Currency.h"
#include <iterator>


class MinHeap: public BST{
 public:
  
  //Heapifys the tree
  void minHeapify();

  //returns the minimum value in the tree
  //this will me the root
  BSTNode* getMin();

  //
  BSTNode* search(Currency* target);
  void insert(Currency* target);
  void remove(Currency* target);
  
  int _heapSize = 0;


 private:

  BSTNode* getLastLevelsLastNode();

  BSTNode* remove(BSTNode* node, Currency* target);
  BSTNode* search(BSTNode* node, Currency* target);
  BSTNode* insert(BSTNode* node, Currency* target);
  void minHeapify(BSTNode* node);
 
  //gets the next parent of the next 
  //node with < 2 children
  BSTNode* getNextParent();
  BSTNode* getNextParent(BSTNode* node);
 
 

};

// Returns the next parent to keep the 
// heap a compleate tree
inline BSTNode* MinHeap::getNextParent() {

  
  if (getRoot() == nullptr) {
    return nullptr;
  }


  std::queue<BSTNode*> q;
  q.push(getRoot());

  while (!q.empty()) {
	  BSTNode* currentNode = q.front();
	  q.pop();

      if (currentNode->left() == nullptr || currentNode->right() == nullptr) {
          return currentNode;
      }

	  if (currentNode->left()) q.push(currentNode->left());
	  if (currentNode->right()) q.push(currentNode->right());
  }

  return nullptr;
}



// makes the heap compleate and corretly formated
inline void MinHeap::minHeapify(){
  if (getRoot()) {

    //checks if the left node is nullptr
    //if it is that means it has no children
    if (getRoot()->left()) {
      minHeapify(getRoot());
    }
  }
}

//Used to enable recusive checking of the heap
//I may want to change the way that swapping works swap objects not change values TODO?
inline void MinHeap::minHeapify(BSTNode* node){

  if (!node) return;

  if (node->left()) {

    //check left sub tree
    if (node->left()) {
      minHeapify(node->left());
    }
    //check right suntree
    if (node->right()) {
      minHeapify(node->right());
    }


    //if parent is greater then left children
    //swap
    if (node->data()->isGreater(*node->left()->data() ) ) {

      // parent node = temp
      
      int wholeTmp = node->data()->wholePart();
      int fracTmp = node->data()->fractPart();
      
      // parentNode = leftChild
      
      node->data()->setWholePart(node->left()->data()->wholePart());
      node->data()->setFractPart(node->left()->data()->fractPart());
      
      // leftChild = temp 
      
      node->left()->data()->setWholePart(wholeTmp);
      node->left()->data()->setFractPart(fracTmp);

    }
  }


  if (node->right()){
    // else if parent is greater then right child,
    //swap
    if ( node->data()->isGreater(*node->right()->data()) ) {
    
      // parent node = temp
      
      int wholeTmp = node->data()->wholePart();
      int fracTmp = node->data()->fractPart();
      
      // parentNode = rightChild
      
      node->data()->setWholePart(node->right()->data()->wholePart());
      node->data()->setFractPart(node->right()->data()->fractPart());
      
      // rightChild = temp 
      
      node->right()->data()->setWholePart(wholeTmp);
      node->right()->data()->setFractPart(fracTmp);
      
    }
  }

}

//inserts a targert Currency object in to the 
//heap.
inline void MinHeap::insert(Currency* target) {



  //newNode will be the node
  //that is inserted
  BSTNode* newNode = new BSTNode(target);

  if (getRoot() == nullptr) {
    setRoot(newNode);
  }else{
    // parentNode will be used to 
    // deside where to put newNode
    BSTNode* parentNode = getNextParent();
    if (parentNode->left() == nullptr) {
        parentNode->setLeft(newNode); 
    } else {
        parentNode->setRight(newNode);
    }
  }
  minHeapify();

}


/*
searches the tree for a target currency
pre: Currency* targer
post: na
return: pointer to currency obj or nullptr if not found
*/
inline BSTNode* MinHeap::search(Currency* target) {
	return search(getRoot(), target);
}

inline BSTNode* MinHeap::search(BSTNode* node, Currency* target) {
	if (node) {
		if (node->data()->isEqual(*target)) {
			return node;
		}
    //tmp used to check if there are any 
    //matches for the sub trees
    BSTNode* tmp = search(node->left(), target);

    //checks left
		if (tmp != nullptr) {
			return tmp;
		}
    tmp = search(node->right(), target);
    //checks right
		if(tmp != nullptr) {
			return tmp;
		}
	}
	return nullptr; // returns null if node not found
}

inline BSTNode* MinHeap::getLastLevelsLastNode(){


  if (getRoot() == nullptr) {
    return nullptr;
  }


  BSTNode* prevNode = nullptr;
  std::queue<BSTNode*> q;
  q.push(getRoot());

  while (!q.empty()) {
	  BSTNode* currentNode = q.front();
	  q.pop();
      if (currentNode->left() == nullptr && currentNode->right() == nullptr ) {
        if (prevNode == nullptr) {
          return currentNode;
        } else {

          if (prevNode->left() == nullptr) {
            return prevNode->left();
          }
          else if (prevNode->right() == nullptr) { //I could just to the else but makes it more readable
            return prevNode->right();
          }
          
        }
      }

      if (currentNode->right() == nullptr) {
          return currentNode->right();
      }

	  if (currentNode->left()) q.push(currentNode->left());
	  if (currentNode->right()) q.push(currentNode->right());
    prevNode = currentNode;

  }

  return nullptr;



}



inline void MinHeap::remove(Currency* target) {
    setRoot( remove(getRoot(), target));
}

//remove helper function to enable recursion
inline BSTNode* MinHeap::remove(BSTNode* node, Currency* target) {
    if (node == nullptr) {
        return nullptr; // Base case: node not foun
    }

    // Search for the node to remove
    BSTNode* targetNode = search(target);
    if (targetNode == nullptr) {
        return node; // Target node not found
    }

          
}


 
