/* Programmer: Wengxi Li. Date: April 2022.
Purpose: This project will use object-oriented programming to develop three 
common linked data structures: a sorted doubly-linked list, a simple queue, 
and a simple stack */

#include <iostream>
using namespace std;
#include "LinkedNodeClass.h"
#include "SortedListClass.h"
#include "FIFOQueueClass.h"
#include "LIFOStackClass.h"

//Do NOT remove any of the preprocessor directives in this file.
//They should not affect your ability to write test code in your
//main function below, and they must be in your submitted main
//file exactly as provided to you with the project.
#ifdef ANDREW_TEST
#include "andrewTest.h"
#else 

int main()
{
  //This is just a placeholder main function - it does exceptionally
  //little actual testing, so you'll want to add your own tests here.
  //Feel free to leave your tests in the version of this file you
  //submit, but we will not be running your main function, so the
  //output, etc., of your main doesn't need to match anything from
  //a sample output, etc.
  SortedListClass testList;
  SortedListClass testList2(testList);
  
  int theVal;

  testList.insertValue(3);
  testList.insertValue(5);
  testList.insertValue(7);
  testList.printForward();
  testList.insertValue(42);
  testList.printForward();
  testList.removeFront(theVal);
  cout << theVal << endl;
  testList.removeLast(theVal);
  cout << theVal << endl;
  testList.insertValue(1);
  testList.insertValue(4);
  testList.insertValue(5);
  testList.printForward();
  testList.printBackward();
  cout << testList.getNumElems() << endl;
  int index = 10;
  int outVal;
  testList.getElemAtIndex(index, outVal);
  cout << outVal << endl;
  // testList.printForward();
  // testList.printBackward();

  // SortedListClass testList1(testList);
  // testList1.printForward();
  // testList1.printBackward();
  // testList.insertValue(10);
  // testList.printBackward();
  // testList1.printForward();
  // testList1.insertValue(0);
  // testList1.printBackward();
  // testList.printForward();
  // cout << testList1.getNumElems() << endl;
  // testList1.printForward();
  // int index1 = 5;
  // int outVal1 = 50;
  // testList1.getElemAtIndex(index1, outVal1);
  // cout << outVal1 << endl;
  
  // FIFOQueueClass newQueue;

  // int outItem;
  // newQueue.dequeue(outItem);
  // newQueue.enqueue(1);
  
  // cout << outItem << endl;
  // newQueue.enqueue(10);
  // newQueue.enqueue(26);
  // newQueue.enqueue(47);
  // newQueue.enqueue(7);
  // newQueue.enqueue(33);
  // newQueue.dequeue(outItem);
  // cout << outItem << endl;
  // newQueue.dequeue(outItem);
  // cout << outItem << endl;
  // newQueue.dequeue(outItem);
  // cout << outItem << endl;
  // newQueue.dequeue(outItem);
  // cout << outItem << endl;
  // newQueue.dequeue(outItem);
  // cout << outItem << endl;
  // newQueue.dequeue(outItem);
  // cout << outItem << endl;
  // newQueue.print();
  // cout << newQueue.getNumElems() << endl;

  // LIFOStackClass newStack;

  // newStack.push(1);
  // newStack.push(10);
  // newStack.push(26);
  // newStack.push(47);
  // newStack.push(33);
  // newStack.push(7);
  // newStack.print();
  // cout << newStack.getNumElems() << endl;
  
  // int outItem;
  // newStack.pop(outItem);
  // cout << outItem << endl;
  // newStack.pop(outItem);
  // cout << outItem << endl;
  // newStack.pop(outItem);
  // cout << outItem << endl;
  // newStack.pop(outItem);
  // cout << outItem << endl;
  // newStack.pop(outItem);
  // cout << outItem << endl;
  // newStack.print();
  // cout << newStack.getNumElems() << endl;
  return 0;
}

#endif