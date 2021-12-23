/**
 * Ryan Grayson
 * rtg5xkh
 * PreLab 6
 * 3/24/2021
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
  int index = 0;
  int spacing = hash_table.size() / 52;
    
  if (s.at(0) <= 90)
    index += spacing * (s.at(0) - 65);
  else
    index += spacing * (s.at(0) - 71);
    
  for (int i = 1; i < s.length(); i++){
    index += 4 * (s.at(i) - 64);
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

