/**
 * Ryan Grayson
 * rtg5xkh
 * PreLab 10
 * huffnode.h
 * 4/21/2021
 */

#include <iostream>
using namespace std;

#ifndef HUFFNODE_H
#define HUFFNODE_H

class huffnode {
 public:

  huffnode();

  huffnode(char val, int freq);

  ~huffnode();

  unsigned char value;
  
  int frequency;
  
  huffnode* left;
  
  huffnode* right;

  friend class heap;
};

#endif
