#include <iostream>
using namespace std;
#include "LinkedNodeClass.h"
#include "SortedListClass.h"
#include "cstddef"

/* Programmer: Wengxi Li. Date: April 2022.
Purpose: This project will use object-oriented programming to develop two 
common linked data structures: a sorted doubly-linked list and a simple queue.
They will be implemented as templetes and used for event-driven simulations*/

//The sorted list class does not store any data directly. Instead,
//it contains a collection of LinkedNodeClass objects, each of which
//contains one element.
template < class T >
SortedListClass< T >::SortedListClass()
{
  head = NULL;
  tail = NULL;
}

template < class T >
SortedListClass< T >::SortedListClass(const SortedListClass< T > &rhs)
{
  if (rhs.head == NULL || rhs.tail == NULL)
  {
    head = NULL;
    tail = NULL;
    return;
  }
  
  LinkedNodeClass< T > *nodePtr = rhs.head;
  LinkedNodeClass< T > *newNode = NULL;
  LinkedNodeClass< T > *tempNode = NULL;

  while (nodePtr != NULL)
  {
    // dynamically create a new node that deep copy the rhs node
    tempNode = new LinkedNodeClass< T >(newNode, nodePtr->getValue(), NULL);
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

template < class T >
SortedListClass< T >::~SortedListClass()
{
  clear();
}

template < class T >
void SortedListClass< T >::clear()
{
  if (head == NULL || tail == NULL)
  {
    return;
  }
  
  LinkedNodeClass< T > *tempNode;  // point to the node in the list
  LinkedNodeClass< T > *tempNodePtr = head;
  
  while(tempNodePtr != NULL)
  {
    tempNode = tempNodePtr->getNext();
    delete tempNodePtr;
    tempNodePtr = tempNode;
  }
  
  head = NULL;
  tail = NULL;
}

template < class T >
void SortedListClass< T >::insertValue(const T &valToInsert)
{
  LinkedNodeClass< T > *nodePtr = head;
  LinkedNodeClass< T > *newNode;

  while (nodePtr != NULL && nodePtr->getValue() <= valToInsert)
  {
    nodePtr = nodePtr->getNext();
  }
  
  if (nodePtr != NULL && nodePtr->getPrev() == NULL)
  // means the node is inserted at the front
  {
    newNode = new LinkedNodeClass< T >(NULL, valToInsert, nodePtr);
    head = newNode;
  }
  else if (nodePtr != NULL && nodePtr->getPrev() != NULL) 
  // means the node is inserted in the middle or at the front
  {
    newNode = new LinkedNodeClass< T >(nodePtr->getPrev(), 
      valToInsert, nodePtr);
  }
  else if (nodePtr == NULL && head != NULL)
  // means the inserted node is at the back
  {
    newNode = new LinkedNodeClass< T >(tail, valToInsert, NULL);
    tail = newNode;
  }
  else // means the inserted node is the only one node in the list
  {
    newNode = new LinkedNodeClass< T >(NULL, valToInsert, NULL);
    head = newNode;
    tail = newNode;
  }
  newNode->setBeforeAndAfterPointers();
}

template < class T >
void SortedListClass< T >::printForward() const
{
  cout << "Forward List Contents Follow:" << endl;

  LinkedNodeClass< T > *newHeadPtr = head;
  while (newHeadPtr != NULL)
  {
    cout << "  " << newHeadPtr->getValue() << endl;
    newHeadPtr = newHeadPtr->getNext();
  }

  cout << "End Of List Contents" << endl;
}

template < class T >
void SortedListClass< T >::printBackward() const
{
  cout << "Backward List Contents Follow:" << endl;

  LinkedNodeClass< T > *newTailPtr = tail;
  while (newTailPtr != NULL)
  {
    cout << "  " << newTailPtr->getValue() << endl;
    newTailPtr = newTailPtr->getPrev();
  }
  
  cout << "End Of List Contents" << endl;
}

template < class T >
bool SortedListClass< T >::removeFront(T &theVal)
{
  // If the list was empty, the function returns false to do nothing
  if (head == NULL || tail == NULL)
  {
    return false;
  }

  theVal = head->getValue();
  LinkedNodeClass< T > *newHeadPtr = head->getNext();
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

template < class T >
bool SortedListClass< T >::removeLast(T &theVal)
{
  if (head == NULL || tail == NULL)
  {
    return false;
  }
  
  theVal = tail->getValue();
  LinkedNodeClass< T > *newTailPtr = tail->getPrev();
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

template < class T >
int SortedListClass< T >::getNumElems() const
{
  int numElems = 0;
  
  LinkedNodeClass< T > *nodePtr = head;
  while(nodePtr != NULL)
  {
    numElems++;
    nodePtr = nodePtr->getNext();
  }
  return numElems;
}

template < class T >
bool SortedListClass< T >::getElemAtIndex(const int index, T &outVal) const
{
  int numElems = getNumElems();
  // If the index is out of range, outVal remains unchanged and return false
  if (index >= numElems || index < 0)
  {
    return false;
  }
  
  LinkedNodeClass< T > *nodePtr = head;
  for (int i = 0; i < index; i++)
  {
    nodePtr = nodePtr->getNext();
  }
  outVal = nodePtr->getValue();
  
  return true;
}