/**
 * Ryan Grayson
 * rtg5xkh
 * PreLab 10
 * heap.h
 * 4/20/2021
 */

#include <iostream>
#include <vector>
#include "huffnode.h"
using namespace std;

#ifndef HEAP_H
#define HEAP_H

class heap {
 public:

  heap();

  heap(vector<huffnode*> vec);

  ~heap();

  void insert(huffnode* hn);

  huffnode* findMin();

  huffnode* deleteMin();

  int getSize();

  void makeEmpty();

  bool isEmpty();

  void print();

  vector<huffnode*> getVec();

private:

  vector<huffnode*> tree;

  int size;

  void percUp(int h);

  void percDown(int h);

};

#endif
