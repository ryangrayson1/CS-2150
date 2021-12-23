/**
 * @file topological.cpp
 * 
 * @brief This file takes in a graph representation file as a 
 * command line parameter, topologically sorts it and prints
 * out the elements of the graph in that sorted order
 * 
 * @author Ryan Grayson
 * rtg5xkh
 * PreLab 11
 * @date 4/28/2021
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <queue>
using namespace std;

struct node {
  string value;
  int indegree;
  vector<node*> next;
  int topoOrder;
};
/** @struct node
 *  @brief A struct representing a graph vertex
 */
/** @var node::value 
 *  Member 'value' contains a string representation the graph vertex represented by this node
 */
/** @var node::indegree 
 *  Member 'indegree' contains the number of nodes that have edges leading to this node
 */
/** @var node::next 
 *  Member 'next' contains a vector of all of the nodes that this vertex has edges to
 */
/** @var node::topoOrder 
 *  Member 'topoOrder' contains this vertex's position in the graph's topologically sorted order
 */

/**
 * @brief sorts a graph topologcally
 * 
 * This function sorts a graph in an order such that if there is a path from 
 * one node to another, the first node appears before the second in the sort.
 * there is an additional property of this sort that if 2 nodes can be 
 * interchangeably placed in a normal topological sort, the one that comes 
 * first lexicographically will be placed first
 * 
 * @param v a vector of node pointers representing the graph
 *
 */
void topsort(vector<node*> &v){
  vector<node*> alphsort;
  queue<node*> q;
  int c = 0;

  node* a;

  for (int i = 0; i < v.size(); i++){

    if (v[i]->indegree == 0){
      alphsort.push_back(v[i]);
    }
  }

  bool nextFront;
  for(int i = 0; i < alphsort.size(); i++){

    if (alphsort.size() == 0)
      break;
    
    nextFront = true;
      
    for(int j = 0; j < alphsort.size(); j++){
	
      if (alphsort[i]->value > alphsort[j]->value)
        nextFront = false;
    }

    if (nextFront){
      q.push(alphsort[i]);
      alphsort.erase(alphsort.begin() + i);
      i = -1;
    }
  }

  while(!q.empty()){

    a = q.front();
    q.front()->topoOrder = ++c;
    q.pop();

    for (int j = 0; j < a->next.size(); j++){
      if (--(a->next[j]->indegree) == 0){
	alphsort.push_back(a->next[j]);
      }
    }

    for(int i = 0; i < alphsort.size(); i++){

      if (alphsort.size() == 0)
        break;
    
      nextFront = true;
      
      for(int j = 0; j < alphsort.size(); j++){
	
        if (alphsort[i]->value > alphsort[j]->value)
                nextFront = false;
      }

      if (nextFront){
        q.push(alphsort[i]);
        alphsort.erase(alphsort.begin() + i);
        i = -1;
      }
    }
  }
}

int main(int argc, char** argv) {
    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }
    // attempt to open the supplied file
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if (!file.is_open()) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }

    vector<node*> nodes;
    string s1, s2;
    node* n;
    node* n2;
    
    while(file >> s1 >> s2){
      if (s1 == "0" && s2 == "0")
	break;

      bool b = true;
      bool c = true;
      
      for (int i = 0; i < nodes.size(); i++){
	if (nodes[i]->value == s1)
	  b = false;
	
	if (nodes[i]->value == s2)
	  c = false;
      }
      
      if (b) { //if element_is_not_already_in_vector
	n = new node();
	n->indegree = 0;
	n->value = s1;
        nodes.push_back(n);
      }
      else{
	for (int i = 0; i < nodes.size(); i++){
	  if (nodes[i]->value == s1)
	    n = nodes[i];
	}
      }
      
      if (c) {
	n2 = new node();
	n2->indegree = 1;
	n2->value = s2;
	n->next.push_back(n2);
        nodes.push_back(n2);
      }
      else{
	for(int i = 0; i < nodes.size(); i++){
	  if (s2 == nodes[i]->value)
	    n2 = nodes[i];
	}
	n->next.push_back(n2);
	n2->indegree++;
      }
    }
    file.close();

    topsort(nodes);
    
    //print out the vector of nodes in order of topsort
    bool nextTop;
    for(int i = 0; i < nodes.size(); i++){
      if (nodes.size() == 0)
	break;

      nextTop = true;
      
      for(int j = 0; j < nodes.size(); j++){
	
	if (nodes[i]->topoOrder > nodes[j]->topoOrder){
	  nextTop = false;
	}
      }
      if (nextTop){
        cout << nodes[i]->value << " ";
	nodes[i]->next.resize(0);
	delete nodes[i];
        nodes.erase(nodes.begin() + i);
        i = -1;
      }
    }
    cout << endl;
    
    return 0;     
}
