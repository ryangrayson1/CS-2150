/**
 * Ryan Grayson
 * rtg5xkh
 * 02/18/2021
 * PreLab 2
 * List.cpp
 */

#include <iostream>
#include "List.h"
#include "ListItr.h"
using namespace std;

//done
List::List() {
  head = new ListNode(); 
  tail = new ListNode();

  head->next = tail;
  tail->previous = head;

  count = 0;
}

List::List(const List& source){
}

List::~List(){
}

List& List::operator=(const List& source){
  return *this;
}

bool List::isEmpty() const{
  return true;
}

void List::makeEmpty(){
}

ListItr List::first() const{
  ListItr li(head->next);
  return li;
}

ListItr List::last() const{
  ListItr li(tail->previous);
  return li;
}

void List::insertBefore(int x, ListItr position){
}

void List::insertAfter(int x, ListItr position){
}

void List::insertAtTail(int x){
  ListNode* ln;
  ln = new ListNode(x, tail->previous, tail);
  (tail->previous)->next = ln;
  tail->previous = ln;
  count++;
}

ListItr List::find(int x){
  return NULL;
}

void List::remove(int x){
}

int List::size() const {
  ListItr li = first();
  int size = 0;
  while (!li.isPastEnd()){
    li.moveForward();
    size++;
  }
  return size;
}

//NON MEMBER FUNCTION - done
void printList(List& source, bool forward){
  if (forward){
    ListItr first = source.first();
    while(!first.isPastEnd()){
      cout << first.retrieve() << " ";
      first.moveForward();
    }
    cout << endl;
  }
  else{
    ListItr last = source.last();
    while(!last.isPastBeginning()){
      cout << last.retrieve() << " ";
      last.moveBackward();
    }
    cout << endl;
  }
}
