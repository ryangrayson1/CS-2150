/**
 * Ryan Grayson
 * rtg5xkh
 * PreLab 10
 * heap.cpp
 * 4/20/2021
 * Source used - heap code from cs2150 slides
 */

#include <iostream>
#include <vector>
#include "heap.h"
using namespace std;

// default constructor
heap::heap(){
  tree = vector<huffnode*>();
  tree.push_back(nullptr);
  size = 0;
}

// builds a heap from an unsorted vector
heap::heap(vector<huffnode*> vec){
  size = vec.size();
  tree = vec;
  tree.push_back(tree[0]);
  tree[0] = 0;
  for (int i = size/2; i > 0; i--){
    percDown(i);
  }
}

// the destructor doesn't need to do much
heap::~heap() {
}

void heap::insert(huffnode* hn){
  tree.push_back(hn);
  size++;
  if (size > 1)
    percUp(size);
}

huffnode* heap::findMin(){
  if (size != 0)
    return tree[1];

  cout << "ERROR" << endl;
  return NULL;
}

huffnode* heap::deleteMin(){
  if (size == 0){
    cout << "dm ERROR" << endl;
    return nullptr;
  }

  huffnode* ret = tree[1];
  tree[1] = tree[size--];
  tree.pop_back();
  if (!isEmpty())
    percDown(1);
  
  return ret;
}

int heap::getSize(){
  return size;
}

void heap::makeEmpty(){
  size = 0;
  tree.resize(1);
}

bool heap::isEmpty(){
  return size == 0;
}

void heap::print(){
  for(int i = 0; i < size + 1; i++){
    cout << i << ": (" << tree[i]->value << ", " << tree[i]->frequency << ")" << endl;
  }
}

void heap::percUp(int h){
  huffnode* x = tree[h];
  
  for ( ; (h > 1) && (x->frequency < tree[h/2]->frequency); h /= 2 ) {
    tree[h] = tree[h/2]; // move parent down
  }
  
  tree[h] = x;
}

void heap::percDown(int h){
  huffnode* x = tree[h];

  while (h*2 <= size){
    int child = h*2;

    if ( (child + 1 <= size) && (tree[child + 1]->frequency < tree[child]->frequency) ){
      child++;
    }

    if (x->frequency > tree[child]->frequency){
      tree[h] = tree[child];
      h = child;
    }
    else{
      break;
    }
  }
  tree[h] = x;
}

vector<huffnode*> heap::getVec(){
  return tree;
}
