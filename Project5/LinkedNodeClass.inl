#include "LinkedNodeClass.h"
#include "cstddef"

/* Programmer: Wengxi Li. Date: April 2022.
Purpose: This project will use object-oriented programming to develop two 
common linked data structures: a sorted doubly-linked list and a simple queue.
They will be implemented as templetes and used for event-driven simulations*/

//The list node class will be the data type for individual nodes of
//a doubly-linked data structure.
template < class T >
LinkedNodeClass< T >::LinkedNodeClass(LinkedNodeClass< T > *inPrev, 
  const T &inVal, LinkedNodeClass< T > *inNext)
{
  prevNode = inPrev;
  nodeVal = inVal;
  nextNode = inNext;
}

template < class T >
T LinkedNodeClass< T >::getValue() const
{
  return nodeVal;
}

template < class T >
LinkedNodeClass< T >* LinkedNodeClass< T >::getNext() const
{
  return nextNode;
}

template < class T >
LinkedNodeClass< T >* LinkedNodeClass< T >::getPrev() const
{
  return prevNode;
}

template < class T >
void LinkedNodeClass< T >::setNextPointerToNull()
{
  nextNode = NULL;
}

template < class T >
void LinkedNodeClass< T >::setPreviousPointerToNull()
{
  prevNode = NULL;
}

template < class T >
void LinkedNodeClass< T >::setBeforeAndAfterPointers()
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