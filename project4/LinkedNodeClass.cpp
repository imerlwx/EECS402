/* Programmer: Wengxi Li. Date: April 2022.
Purpose: This project will use object-oriented programming to develop three 
common linked data structures: a sorted doubly-linked list, a simple queue, 
and a simple stack */

#include "LinkedNodeClass.h"
#include "cstddef"

//The list node class will be the data type for individual nodes of
//a doubly-linked data structure.

LinkedNodeClass::LinkedNodeClass(LinkedNodeClass *inPrev, const int &inVal,
  LinkedNodeClass *inNext)
{
  prevNode = inPrev;
  nodeVal = inVal;
  nextNode = inNext;
}

int LinkedNodeClass::getValue() const
{
  return nodeVal;
}

LinkedNodeClass* LinkedNodeClass::getNext() const
{
  return nextNode;
}

LinkedNodeClass* LinkedNodeClass::getPrev() const
{
  return prevNode;
}

void LinkedNodeClass::setNextPointerToNull()
{
  nextNode = NULL;
}

void LinkedNodeClass::setPreviousPointerToNull()
{
  prevNode = NULL;
}

void LinkedNodeClass::setBeforeAndAfterPointers()
{
  // only if the current node has a next/previous node could we reset it
  if (nextNode != NULL)
  {
    nextNode->prevNode = this;
  }
  if (prevNode != NULL)
  {
    prevNode->nextNode = this;
  }
}