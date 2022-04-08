/* Programmer: Wengxi Li. Date: April 2022.
Purpose: This project will use object-oriented programming to develop three 
common linked data structures: a sorted doubly-linked list, a simple queue, 
and a simple stack */

#include "LinkedNodeClass.h"
#include "FIFOQueueClass.h"
#include <iostream>
using namespace std;
#include "cstddef"

// This will be a “first-in-first-out queue” data structure.
FIFOQueueClass::FIFOQueueClass()
{
  head = NULL;
  tail = NULL;
}

FIFOQueueClass::~FIFOQueueClass()
{
  clear();
}

void FIFOQueueClass::enqueue(const int &newItem)
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

bool FIFOQueueClass::dequeue(int &outItem)
{
  if (head == NULL || tail == NULL)
  {
    return false;
  }
  
  outItem = head->getValue();
  LinkedNodeClass *newHeadPtr = head->getNext();
  delete head;
  head = newHeadPtr;

  if (head != NULL)
  {
    head->setPreviousPointerToNull();
  }
  else
  {
    tail = NULL;
  }
  
  return true;
}

void FIFOQueueClass::print() const
{
  LinkedNodeClass *nodePtr = head;

  while(nodePtr != NULL)
  {
    cout << nodePtr->getValue() << " ";
    nodePtr = nodePtr->getNext();
  }

  cout << endl;
}

int FIFOQueueClass::getNumElems() const
{
  int numElems = 0;
  
  LinkedNodeClass *nodePtr = head;
  while(nodePtr != NULL)
  {
    numElems++;
    nodePtr = nodePtr->getNext();
  }
  return numElems;
}

void FIFOQueueClass::clear()
{
  if (head == NULL || tail == NULL)
  {
    return;
  }
  
  LinkedNodeClass *tempNode;  // point to the node in the list
  LinkedNodeClass *tempNodePtr = head;
  
  while(tempNodePtr != NULL)
  {
    tempNode = tempNodePtr->getNext();
    delete tempNodePtr;
    tempNodePtr = tempNode;
  }
  
  head = NULL;
  tail = NULL;
}