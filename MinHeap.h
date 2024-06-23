
//Min heap inharets from BinarySearchTree(BST) and Overrides search insert and delete
#include "BST.h"
#include "Currency.h"


class MinHeap: public BST{
 public:
  
  //Heapifys the tree
  void minHeapify();

  //returns the minimum value in the tree
  //this will me the root
  BSTNode* getMin();

  //
  void search(Currency* target) const;
  void insert(Currency* target);
  void remove(Currency* target);
  
  int _heapSize = 0;


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




inline void MinHeap::minHeapify(){
  if (getRoot()) {
    if (getRoot()->left()) {
      minHeapify(getRoot());
    }
  }
}

inline void MinHeap::minHeapify(BSTNode* node){

  if (node) {

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
    // else if parent is greater then right child,
    //swap
    else if ( node->data()->isGreater(*node->right()->data()) ) {
    
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



 
