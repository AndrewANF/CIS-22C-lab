// Lab 6
// lab6.cpp
// Linhnam Le & Andrew Nunez Forsberg
// This assignment demonstrates a Min Heap
// 06/23/24

#include "Dollar.h"

#include <iostream>

#include "MinHeap.h"

const int SIZE = 20;
const double TEST_VALS[SIZE] = {
  57.12,
  23.44,
  87.43,
  68.99,
  111.22,
  44.55,
  77.77,
  18.36,
  543.21,
  20.21,
  345.67,
  36.18,
  48.48,
  101.00,
  11.00,
  21.00,
  51.00,
  1.00,
  251.00,
  151.00
};

int main() {

  //create min Heap
  MinHeap heap = MinHeap();
  //insert test values from TEST_VALS
  for (int i = 0; i < SIZE; i++) {
    // After 10th item print traversal methods
    if (i == 10) {
      std::cout << "Tenth Item added, Printing traversals: \n";
      heap.print();
    }
    Dollar * newNode = new Dollar(TEST_VALS[i]);
    heap.insert(newNode);

  }
  //After last item print traversal methods
  std::cout << "\n\nFinal item added, Printing traversals:\n";
  heap.print();

// Test Search and delete methods


/*

  Dollar * searchTarget = new Dollar(1.0);

  std::cout << "\n\nTesting Search: 1.0";
  if (heap.search(searchTarget)) {
    std::cout << "\nSearch target found";
  } else {
    std::cout << "\nSearch target Not found";
  }

  std::cout << "\n";
  heap.remove();
  heap.print();

  std::cout << "\nTesting Search: 1.0";
  if (heap.search(searchTarget)) {
    std::cout << "\nSearch target found";
  } else {
    std::cout << "\nSearch target Not found";
  }

*/



  std::cout << std::endl;

  //exit program
  return 0;
}