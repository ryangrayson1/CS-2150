/**
 * Ryan Grayson
 * rtg5xkh
 * 02/18/2021
 * PostLab 2
 * ListNode.cpp
 */

#include <iostream>
#include "ListNode.h"
using namespace std;

//done
ListNode::ListNode(){
  value = -1;
  previous = NULL;
  next = NULL;
}

//added - done
ListNode::ListNode(int val){
  value = val;
}

//added - done
ListNode::ListNode(int val, ListNode* prev, ListNode* nex){
  value = val;
  previous = prev;
  next = nex;
}
