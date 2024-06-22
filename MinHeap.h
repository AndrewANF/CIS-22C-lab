
//Min heap inharets from BinarySearchTree(BST) and Overrides search insert and delete
#include "BST.h"


class MinHeap: public BST{
 public:
  
  //Heapifys the tree
  void minHeapify();

  //returns the minimum value in the tree
  //this will me the root
  BSTNode* getMin();

  //
  BSTNode* search(Currency* target) const;
  BSTNode* insert(Currency* target);
  BSTNode* remove(Currency* target);
  int _maxSize;
  int _heapSize;


 private:

 BSTNode* remove(BSTNode* node, Currency* target);
 BSTNode* search(BSTNode* node, Currency* target) const;
 BSTNode* insert(BSTNode* node, Currency* target);
 

};  
