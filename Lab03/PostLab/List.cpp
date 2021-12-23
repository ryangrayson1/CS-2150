/**
 * Ryan Grayson
 * rtg5xkh
 * 02/18/2021
 * PostLab 2
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

//done
// Copy constructor
// Called when the code looks something like List list2 = list1;
// (In other words, it is called when you are trying to construct a **new** list from an existing one)
List::List(const List& source){
  head=new ListNode();
  tail=new ListNode();
  
  head->next=tail;
  tail->previous=head;

  count=0;

  // Make a deep copy of the list
  ListItr iter(source.head->next);
  while (!iter.isPastEnd()) {
      insertAtTail(iter.retrieve());
      iter.moveForward();
  }
}

//done
List::~List(){
  makeEmpty();
  delete head;
  delete tail;
}

//done
// Copy assignment operator
// Called when the code looks something like list2 = list1;
// (In other words, it is called when you are trying to set an **existing** list equal to another one)
List& List::operator=(const List& source) {
    if (this == &source) {
        // The two are the same list; no need to do anything
        return *this;
    }
    else {
        // Clear out anything this list contained
        // before copying over the items from the other list
        makeEmpty();

        // Make a deep copy of the list
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}

//done
bool List::isEmpty() const{
  return (size() == 0);
}

//done
void List::makeEmpty(){
  ListItr li = first();
  while (!li.isPastEnd()){
    li.moveForward();
    delete ((li.current)->previous);
  }
  
  head->next = tail;
  tail->previous = head;
  count = 0;
}

//done
ListItr List::first() const{
  ListItr li(head->next);
  return li;
}

//done
ListItr List::last() const{
  ListItr li(tail->previous);
  return li;
}

//done
void List::insertBefore(int x, ListItr position){
   ListNode* ln = new ListNode(x);
   ln->next = position.current;
   ln->previous = (position.current)->previous;
   ((position.current)->previous)->next = ln;
   (position.current)->previous = ln;
   count++;
}

//done
void List::insertAfter(int x, ListItr position){
  ListNode* ln = new ListNode(x);
  ln->previous = position.current;
  ln->next = (position.current)->next;
  ((position.current)->next)->previous = ln;
  (position.current)->next = ln;
  count++;
}

//done
void List::insertAtTail(int x){
  ListNode* ln = new ListNode(x, tail->previous, tail);
  (tail->previous)->next = ln;
  tail->previous = ln;
  count++;
}

//done
ListItr List::find(int x){
  ListItr li = first();
  while(!li.isPastEnd()){
    if ((li.current)->value == x)
      return li;
    li.moveForward();
  }
  return li;
}

//done
void List::remove(int x){
  ListItr li = find(x);
  if (!li.isPastBeginning() && !li.isPastEnd()){
  
  ((li.current)->previous)->next = (li.current)->next;
  ((li.current)->next)->previous = (li.current)->previous;
  
  delete li.current;
  count--;
  }
}

//done
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
