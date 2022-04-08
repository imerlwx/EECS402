/* Programmer: Wengxi Li. Date: April 2022.
Purpose: This project will use object-oriented programming to develop three 
common linked data structures: a sorted doubly-linked list, a simple queue, 
and a simple stack */

#include <iostream>
using namespace std;
#include "LinkedNodeClass.h"
#include "LIFOStackClass.h"
#include "cstddef"

LIFOStackClass::LIFOStackClass()
{
  head = NULL;
  tail = NULL;
}

LIFOStackClass::~LIFOStackClass()
{
  clear();
}

void LIFOStackClass::push(const int &newItem)
{
  LinkedNodeClass *newNodePtr;
  newNodePtr = new LinkedNodeClass(tail, newItem, NULL);
  newNodePtr->setBeforeAndAfterPointers();
  
  if (tail == NULL)
  {
    head = newNodePtr;
  }
  tail = newNodePtr;
}

bool LIFOStackClass::pop(int &outItem)
{
  if (head == NULL || tail == NULL)
  {
    return false;
  }
  
  outItem = tail->getValue();
  LinkedNodeClass *newTailPtr = tail->getPrev();
  delete tail;
  tail = newTailPtr;

  if (tail != NULL)
  {
    tail->setNextPointerToNull();
  }
  else
  {
    head = NULL;
  }
  
  return true;
}

void LIFOStackClass::print() const
{
  LinkedNodeClass *nodePtr = head;

  while(nodePtr != NULL)
  {
    cout << nodePtr->getValue() << " ";
    nodePtr = nodePtr->getNext();
  }

  cout << endl;
}

int LIFOStackClass::getNumElems() const
{
  int numElems = 0;
  
  LinkedNodeClass *newTailPtr = tail;
  while(newTailPtr != NULL)
  {
    numElems++;
    newTailPtr = newTailPtr->getPrev();
  }
  return numElems;
}

void LIFOStackClass::clear()
{
  if (head == NULL || tail == NULL)
  {
    return;
  }
  
  LinkedNodeClass *tempNode;  // point to the node in the list
  LinkedNodeClass *tempNodePtr = tail;
  
  while(tempNodePtr != NULL)
  {
    tempNode = tempNodePtr->getPrev();
    delete tempNodePtr;
    tempNodePtr = tempNode;
  }
  
  head = NULL;
  tail = NULL;
}