
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

  BSTNode* getLastLevelsLastNode();

 private:


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

// Using breadth traversal, return "last" node in heap (bottom-most, right-most)
BSTNode* MinHeap::getLastLevelsLastNode() {
    if (getRoot() == nullptr) { // nullptr on empty heap
        return nullptr;
    }

    // breadth traversal. uses queue class written for previous lab
    std::queue<BSTNode*> q;
    q.push(getRoot());

    // this is the node that will be returned
    BSTNode* target = nullptr;

    while (!q.empty()) {
        BSTNode* currentNode = q.front();
        q.pop();

        target = currentNode;

        if (currentNode->left() != nullptr) {
            q.push(currentNode->left());
        }
        if (currentNode->right() != nullptr) {
            q.push(currentNode->right());
        }
    }

    return target;
}


// jyn's special sauce remove algorithm (NOT recursive)
void MinHeap::remove(Currency* target) {



    // do nothing on empty heap
    if (getRoot() == nullptr) {
        return;
    }


    // Call search to grab targetNode
    BSTNode* targetNode = search(target);

    if (targetNode == nullptr) {
        return;
    }

    // find last node (see method documentation)
    // With given TEST_VALS, this should always be the node with value 151.00
    BSTNode* lastNode = getLastLevelsLastNode();

    if (lastNode == targetNode) {
        if (getRoot() == targetNode) { setRoot(nullptr); }
        delete lastNode; // mem management - TODO: review destructor
        return;
    }

    // Swaps target node and last node, later we will re-heapify and whatnot
    // Using remove order-of-operations explained in zylabs
    Currency* tmp = targetNode->data();
    targetNode->setData(lastNode->data());
    lastNode->setData(tmp);

    // Remove the last node from the heap & clean up "parent" node ptrs
    BSTNode* lastPar = getNextParent(lastNode);
    if (lastPar != nullptr) {
        if (lastPar->left() == lastNode) { lastPar->setLeft(nullptr); }
        else if (lastPar->right() == lastNode) { lastPar->setRight(nullptr); }
    }
    delete lastNode;
    minHeapify();
}

// Helper function to find the parent of a node
inline BSTNode* MinHeap::getNextParent(BSTNode* node) {
    if (getRoot() == nullptr || node == nullptr) {
        return nullptr;
    }

    std::queue<BSTNode*> q;
    q.push(getRoot());

    while (!q.empty()) {
        BSTNode* currentNode = q.front();
        q.pop();

        if (currentNode->left() == node || currentNode->right() == node) {
            return currentNode;
        }

        if (currentNode->left()) q.push(currentNode->left());
        if (currentNode->right()) q.push(currentNode->right());
    }

    return nullptr;
}


 
