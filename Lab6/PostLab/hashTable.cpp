/**
 * Ryan Grayson
 * rtg5xkh
 * PostLab 6
 * 3/30/2021
 * hashTable.cpp
 */

#include <iostream>
#include <vector>
#include <list>
#include "hashTable.h"

using namespace std;

hashTable::hashTable(){
  hash_table = vector<list<string> >();
}

hashTable::hashTable(int size){
  hash_table = vector<list<string> >(size);
}

int hashTable::hash(string s){
  int spacing = hash_table.size() / 26;
    
  int index = spacing * (s[0] - 97);
    
  for (int i = 1; i < s.length(); i++){
    index += (s[i] - 97);
  }
  
  return index % hash_table.size();
}

void hashTable::insert(string elem){
  hash_table[hash(elem)].push_front(elem);
}

bool hashTable::find(string elem){

  for (string s : hash_table[hash(elem)]) {
    if (s == elem)
      return true;
  }
  return false;
}
