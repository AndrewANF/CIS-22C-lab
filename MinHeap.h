//Min heap inharets from BinarySearchTree(BST) and Overrides search insert and delete
#include "BST.h"

#include "Currency.h"

#include <cstddef>

#include <iterator>


class MinHeap: public BST {
  public:

    //Heapifys the tree
    void minHeapify();

  //returns the minimum value in the tree
  //this will me the root
  BSTNode * getMin();

  //
  BSTNode * search(Currency * target);
  void insert(Currency * target);
  void remove();

  int _heapSize = 0;

  private:

    //BSTNode* remove(BSTNode* node, Currency* target);
    BSTNode * search(BSTNode * node, Currency * target);
  BSTNode * insert(BSTNode * node, Currency * target);
  void minHeapify(BSTNode * node);

  //gets the next parent of the next 
  //node with < 2 children
  BSTNode * getNextParent();
  BSTNode * getNextParent(BSTNode * node);

  BSTNode * getLastNode();
  void deleteLastNode(BSTNode * last);

  void deleteRoot();

  void swap(BSTNode * a, BSTNode * b);

  BSTNode * getParent(BSTNode * node);

};

// Returns the next parent to keep the 
// heap a compleate tree
inline BSTNode * MinHeap::getNextParent() {

  if (getRoot() == nullptr) {
    return nullptr;
  }

  std::queue < BSTNode * > q;
  q.push(getRoot());

  while (!q.empty()) {
    BSTNode * currentNode = q.front();
    q.pop();

    if (currentNode -> left() == nullptr || currentNode -> right() == nullptr) {
      return currentNode;
    }

    if (currentNode -> left()) q.push(currentNode -> left());
    if (currentNode -> right()) q.push(currentNode -> right());
  }

  return nullptr;
}

// makes the heap compleate and corretly formated
inline void MinHeap::minHeapify() {
  if (getRoot()) {

    //checks if the left node is nullptr
    //if it is that means it has no children
    if (getRoot() -> left()) {
      minHeapify(getRoot());
    }
  }
}

//Used to enable recusive checking of the heap
//I may want to change the way that swapping works swap objects not change values TODO?
inline void MinHeap::minHeapify(BSTNode * node) {
  if (!node) return;

  if (node -> left()) {

    //check left sub tree
    if (node -> left()) {
      minHeapify(node -> left());
    }
    //check right suntree
    if (node -> right()) {
      minHeapify(node -> right());
    }

    //if parent is greater then left children
    //swap
    if (node -> data() -> isGreater( * node -> left() -> data())) {

      // parent node = temp

      int wholeTmp = node -> data() -> wholePart();
      int fracTmp = node -> data() -> fractPart();

      // parentNode = leftChild

      node -> data() -> setWholePart(node -> left() -> data() -> wholePart());
      node -> data() -> setFractPart(node -> left() -> data() -> fractPart());

      // leftChild = temp 

      node -> left() -> data() -> setWholePart(wholeTmp);
      node -> left() -> data() -> setFractPart(fracTmp);

    }
  }

  if (node -> right()) {
    // else if parent is greater then right child,
    //swap
    if (node -> data() -> isGreater( * node -> right() -> data())) {

      // parent node = temp

      int wholeTmp = node -> data() -> wholePart();
      int fracTmp = node -> data() -> fractPart();

      // parentNode = rightChild

      node -> data() -> setWholePart(node -> right() -> data() -> wholePart());
      node -> data() -> setFractPart(node -> right() -> data() -> fractPart());

      // rightChild = temp 

      node -> right() -> data() -> setWholePart(wholeTmp);
      node -> right() -> data() -> setFractPart(fracTmp);

    }
  }

}

//inserts a targert Currency object in to the 
//heap.
inline void MinHeap::insert(Currency * target) {

  //newNode will be the node
  //that is inserted
  BSTNode * newNode = new BSTNode(target);

  if (getRoot() == nullptr) {
    setRoot(newNode);
  } else {
    // parentNode will be used to 
    // deside where to put newNode
    BSTNode * parentNode = getNextParent();
    if (parentNode -> left() == nullptr) {
      parentNode -> setLeft(newNode);
    } else {
      parentNode -> setRight(newNode);
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
inline BSTNode * MinHeap::search(Currency * target) {
  return search(getRoot(), target);
}

inline BSTNode * MinHeap::search(BSTNode * node, Currency * target) {
  if (node) {
    if (node -> data() -> isEqual( * target)) {
      return node;
    }
    //tmp used to check if there are any 
    //matches for the sub trees
    BSTNode * tmp = search(node -> left(), target);

    //checks left
    if (tmp != nullptr) {
      return tmp;
    }
    tmp = search(node -> right(), target);
    //checks right
    if (tmp != nullptr) {
      return tmp;
    }
  }
  return nullptr; // returns null if node not found
}

inline void MinHeap::swap(BSTNode * a, BSTNode * b) {

  int wholeTmp = a -> data() -> wholePart();
  int fracTmp = a -> data() -> fractPart();

  // parentNode = rightChild

  a -> data() -> setWholePart(b -> data() -> wholePart());
  a -> data() -> setFractPart(b -> data() -> fractPart());

  // rightChild = temp 

  b -> data() -> setWholePart(wholeTmp);
  b -> data() -> setFractPart(fracTmp);

}

inline void MinHeap::deleteRoot() {

  //checks for empty heap
  if (getRoot() == nullptr) return;

  BSTNode * last = getLastNode();

  //checks if there is only one node in heap
  if (last != getRoot()) {
    swap(getRoot(), last);
  }
  deleteLastNode(last);

  if (getRoot() != nullptr) {
    minHeapify();
  }

}

inline BSTNode * MinHeap::getLastNode() {

  if (getRoot() == nullptr) return nullptr;

  std::queue < BSTNode * > q;

  q.push(getRoot());

  BSTNode * last = nullptr;

  while (!q.empty()) {

    last = q.front();
    q.pop();

    if (last -> left()) q.push(last -> left());

    if (last -> right()) q.push(last -> right());

  }
  return last;
}

inline void MinHeap::deleteLastNode(BSTNode * last) {

  if (getRoot() == nullptr) return;

  std::queue < BSTNode * > q;

  q.push(getRoot());

  while (!q.empty()) {

    BSTNode * node = q.front();
    q.pop();

    if (node -> left() == last) {

      node -> setLeft(nullptr);
      delete last;
      return;
    } else if (node -> right() == last) {
      node -> setRight(nullptr);
      delete last;
      return;
    }

    if (node -> left()) q.push(node -> left());
    if (node -> right()) q.push(node -> right());
  }

}

inline BSTNode * MinHeap::getParent(BSTNode * node) {

  if (!getRoot() || getRoot() == node) return nullptr;

  std::queue < BSTNode * > q;

  q.push(getRoot());
  while (!q.empty()) {
    BSTNode * parent = q.front();
    q.pop();
    if (parent -> left() == node || parent -> right() == node) {
      return parent;
    }
    if (parent -> left()) q.push(parent -> left());
    if (parent -> right()) q.push(parent -> right());
  }
  return nullptr;
}

inline void MinHeap::remove() {

  deleteRoot();

}

// Helper function to find the parent of a node
inline BSTNode * MinHeap::getNextParent(BSTNode * node) {
  if (getRoot() == nullptr || node == nullptr) {
    return nullptr;
  }

  std::queue < BSTNode * > q;
  q.push(getRoot());

  while (!q.empty()) {
    BSTNode * currentNode = q.front();
    q.pop();

    if (currentNode -> left() == node || currentNode -> right() == node) {
      return currentNode;
    }

    if (currentNode -> left()) q.push(currentNode -> left());
    if (currentNode -> right()) q.push(currentNode -> right());
  }

  return nullptr;
}