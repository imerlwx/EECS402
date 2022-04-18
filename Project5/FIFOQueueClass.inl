#include "LinkedNodeClass.h"
#include "FIFOQueueClass.h"
#include <iostream>
using namespace std;
#include "cstddef"

/* Programmer: Wengxi Li. Date: April 2022.
Purpose: This project will use object-oriented programming to develop two 
common linked data structures: a sorted doubly-linked list and a simple queue.
They will be implemented as templetes and used for event-driven simulations*/

// This will be a “first-in-first-out queue” data structure.
template < class T >
FIFOQueueClass< T >::FIFOQueueClass()
{
  head = NULL;
  tail = NULL;
}

template < class T >
FIFOQueueClass< T >::~FIFOQueueClass()
{
  clear();
}

template < class T >
void FIFOQueueClass< T >::enqueue(const T &newItem)
{
  LinkedNodeClass< T > *newNodePtr;
  newNodePtr = new LinkedNodeClass< T >(tail, newItem, NULL);
  newNodePtr->setBeforeAndAfterPointers();
  
  if (tail == NULL)
  {
    head = newNodePtr;
  }
  tail = newNodePtr;
}

template < class T >
bool FIFOQueueClass< T >::dequeue(T &outItem)
{
  if (head == NULL || tail == NULL)
  {
    return false;
  }
  
  outItem = head->getValue();
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
void FIFOQueueClass< T >::print() const
{
  LinkedNodeClass< T > *nodePtr = head;

  while(nodePtr != NULL)
  {
    cout << nodePtr->getValue() << " ";
    nodePtr = nodePtr->getNext();
  }

  cout << endl;
}

template < class T >
int FIFOQueueClass< T >::getNumElems() const
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
void FIFOQueueClass< T >::clear()
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