/**
 * Ryan Grayson
 * rtg5xkh
 * PreLab 6
 * 3/24/2021
 * hashTable.h
 */

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
#include <list>

using namespace std;

class hashTable {
 public:

  hashTable();

  hashTable(int size);
	    
  int hash(string s);

  void insert(string elem);

  bool find(string elem);

 private:

  vector<list<string> > hash_table;
};

#endif
