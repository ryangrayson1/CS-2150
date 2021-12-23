/**
 * Ryan Grayson
 * rtg5xkh
 * 02/26/2021
 * PostLab 3
 * stack.cpp
 */

#include <iostream>
#include "stack.h"
#include "List.h"
using namespace std;

stack::stack(){
  lis = List();
}

void stack::push(int e){
  ListItr theHead = lis.first();
  theHead.moveBackward();
  lis.insertAfter(e, theHead);
}

void stack::pop(){
  if (!empty()){
    ListItr theTop = lis.first();
    lis.remove(theTop.current->value);
  }
  else
    cout << endl << "nothing to pop!" << endl;
}

int stack::top(){
      if (!empty()) {
      return lis.first().current->value;
    }
      else{
	cout << endl << "stack is empty!" << endl;
	return -100;
      }
}

bool stack::empty() const{
  return lis.isEmpty();
}
