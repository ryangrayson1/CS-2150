/**
 * Ryan Grayson
 * rtg5xkh
 * 02/26/2021
 * PostLab 3
 * stack.h
 */

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "List.h"
using namespace std;

class stack{
 public:

  stack();

  void push(int e);

  void pop();

  int top();

  bool empty() const;

 private:

  List lis;
  
};

#endif
