#ifndef _MESSAGEFILECLASS_H_
#define _MESSAGEFILECLASS_H_
#include "RowColumnClass.h"
#include <string>
using namespace std;

class MessageFileClass
{
  private:
    RowColumnClass mesRowCol; // an object to store the row and column info
    // dynamically allocate a one D array 
    int *oneDArrFor2DMes = new int[mesRowCol.getRow() * mesRowCol.getCol()];
  
  public:
    // This function will read the encoding message, if the file is valid for
    // encoding, return true; otherwise return false.
    bool messageRead(string mesFilename);
};


#endif