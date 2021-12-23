/**
 * Ryan Grayson
 * rtg5xkh
 * PreLab 10
 * huffnode.cpp
 * 4/21/2021
 */

#include <iostream>
#include "huffnode.h"
using namespace std;

huffnode::huffnode(){
  value = 0;
  frequency = 0;
  left = nullptr;
  right = nullptr;
}

huffnode::huffnode(char val, int freq){
  value = val;
  frequency = freq;
  left = nullptr;
  right = nullptr;
}
  
huffnode::~huffnode(){
  delete left;
  delete right;
}
