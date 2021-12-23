/**
 * Ryan Grayson
 * rtg5xkh
 * 02/24/2021
 * PreLab 3
 * postfixCalculator.cpp
 */

#include <iostream>
#include <cstdlib>
#include "postfixCalculator.h"
using namespace std;

postfixCalculator::postfixCalculator(){
  theStack = stack<int>();
}

void postfixCalculator::addElement(int x){
  theStack.push(x);
}

void postfixCalculator::plus(){
  if (!theStack.empty()){
    
    int x = theStack.top();
    theStack.pop();
    int y = theStack.top();
    theStack.pop();
    theStack.push(y + x);
  }
  else{
    cout << "nothing to add" << endl;
    exit(-1);
  }
}

void postfixCalculator::minus(){
  if (!theStack.empty()){
    int x = theStack.top();
    theStack.pop();
    int y = theStack.top();
    theStack.pop();
    theStack.push(y - x);
  }
  else{
    cout << "nothing to subtract" << endl;
    exit(-1);
  }
}
  
void postfixCalculator::print(){
  if (!theStack.empty()){
    cout << theStack.top() << endl;
  }
  else{
    cout << "the stack is empty" << endl;
    exit(-1);
  }
}

