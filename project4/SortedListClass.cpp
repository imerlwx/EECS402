/* Programmer: Wengxi Li. Date: April 2022.
Purpose: This project will use object-oriented programming to develop three 
common linked data structures: a sorted doubly-linked list, a simple queue, 
and a simple stack */

#include <iostream>
using namespace std;
#include "LinkedNodeClass.h"
#include "SortedListClass.h"
#include "cstddef"

//The sorted list class does not store any data directly. Instead,
//it contains a collection of LinkedNodeClass objects, each of which
//contains one element.

SortedListClass::SortedListClass()
{
  head = NULL;
  tail = NULL;
}

SortedListClass::SortedListClass(const SortedListClass &rhs)
{
  if (rhs.head == NULL || rhs.tail == NULL)
  {
    head = NULL;
    tail = NULL;
    return;
  }
  
  LinkedNodeClass *nodePtr = rhs.head;
  LinkedNodeClass *newNode = NULL;
  LinkedNodeClass *tempNode = NULL;

  while (nodePtr != NULL)
  {
    // dynamically create a new node that deep copy the rhs node
    tempNode = new LinkedNodeClass(newNode, nodePtr->getValue(), NULL);
    if (newNode == NULL)
    {
      head = tempNode;
    }
    newNode = tempNode;
    newNode->setBeforeAndAfterPointers();
    nodePtr = nodePtr->getNext();
  }

  tail = newNode;
}

SortedListClass::~SortedListClass()
{
  clear();
}

void SortedListClass::clear()
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

void SortedListClass::insertValue(const int &valToInsert)
{
  LinkedNodeClass *nodePtr = head;
  LinkedNodeClass *newNode;

  while (nodePtr != NULL && nodePtr->getValue() <= valToInsert)
  {
    nodePtr = nodePtr->getNext();
  }
  
  if (nodePtr != NULL && nodePtr->getPrev() == NULL)
  // means the node is inserted at the front
  {
    newNode = new LinkedNodeClass(NULL, valToInsert, nodePtr);
    head = newNode;
  }
  else if (nodePtr != NULL && nodePtr->getPrev() != NULL) 
  // means the node is inserted in the middle or at the front
  {
    newNode = new LinkedNodeClass(nodePtr->getPrev(), valToInsert, nodePtr);
  }
  else if (nodePtr == NULL && head != NULL)
  // means the inserted node is at the back
  {
    newNode = new LinkedNodeClass(tail, valToInsert, NULL);
    tail = newNode;
  }
  else // means the inserted node is the only one node in the list
  {
    newNode = new LinkedNodeClass(NULL, valToInsert, NULL);
    head = newNode;
    tail = newNode;
  }
  newNode->setBeforeAndAfterPointers();
}

void SortedListClass::printForward() const
{
  cout << "Forward List Contents Follow:" << endl;

  LinkedNodeClass *newHeadPtr = head;
  while (newHeadPtr != NULL)
  {
    cout << "  " << newHeadPtr->getValue() << endl;
    newHeadPtr = newHeadPtr->getNext();
  }

  cout << "End Of List Contents" << endl;
}

void SortedListClass::printBackward() const
{
  cout << "Backward List Contents Follow:" << endl;

  LinkedNodeClass *newTailPtr = tail;
  while (newTailPtr != NULL)
  {
    cout << "  " << newTailPtr->getValue() << endl;
    newTailPtr = newTailPtr->getPrev();
  }
  
  cout << "End Of List Contents" << endl;
}

bool SortedListClass::removeFront(int &theVal)
{
  // If the list was empty, the function returns false to do nothing
  if (head == NULL || tail == NULL)
  {
    return false;
  }

  theVal = head->getValue();
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

bool SortedListClass::removeLast(int &theVal)
{
  if (head == NULL || tail == NULL)
  {
    return false;
  }
  
  theVal = tail->getValue();
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

int SortedListClass::getNumElems() const
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

bool SortedListClass::getElemAtIndex(const int index, int &outVal) const
{
  int numElems = getNumElems();
  // If the index is out of range, outVal remains unchanged and return false
  if (index >= numElems || index < 0)
  {
    return false;
  }
  
  LinkedNodeClass *nodePtr = head;
  for (int i = 0; i < index; i++)
  {
    nodePtr = nodePtr->getNext();
  }
  outVal = nodePtr->getValue();
  
  return true;
}