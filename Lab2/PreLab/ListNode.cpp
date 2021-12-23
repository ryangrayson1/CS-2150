/**
 * Ryan Grayson
 * rtg5xkh
 * 02/18/2021
 * PreLab 2
 * ListNode.cpp
 */

#include <iostream>
#include "ListNode.h"
using namespace std;

//done
ListNode::ListNode(){
  value = 0;
  previous = NULL;
  next = NULL;
}

//added
ListNode::ListNode(int val, ListNode* prev, ListNode* nex){
  value = val;
  previous = prev;
  next = nex;
}
