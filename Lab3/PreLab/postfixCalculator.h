/**
 * Ryan Grayson
 * rtg5xkh
 * 02/24/2021
 * PreLab 3
 * postfixCalculator.h
 */

#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H

#include <iostream>
#include <stack>
using namespace std;

class postfixCalculator {

 public:
  
  postfixCalculator();

  void addElement(int x);
  
  void plus();

  void minus();

  void print();

 private:

  stack<int> theStack;
  
};

#endif
