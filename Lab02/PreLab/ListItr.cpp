/**
 * Ryan Grayson
 * rtg5xkh
 * 02/18/2021
 * PreLab 2
 * ListItr.cpp
 *
 * Source consulted:
 * https://stackoverflow.com/questions/15675275/comparing-to-a-null-in-c#:~:text=You%20are%20trying%20to%20compare,std%3A%3Astring%20is%20empty.
 */

#include <iostream>
#include "ListItr.h"
using namespace std;

//done
ListItr::ListItr(){
  current = NULL;
}

//done
ListItr::ListItr(ListNode* theNode){
  current = theNode;
}

//done
bool ListItr::isPastEnd() const {
  return (current->next == NULL);
}

//done
bool ListItr::isPastBeginning() const {
  return (current->previous == NULL);
}

//done
void ListItr::moveForward() {
  if (!isPastEnd())
    current = current->next;
}

//done
void ListItr::moveBackward() {
  if (!isPastBeginning())
    current = current->previous;
}

//done
int ListItr::retrieve() const {
  return current->value;
}
