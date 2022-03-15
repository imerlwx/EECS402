#include "MessageFileClass.h"
#include <string>
#include "constants.h"
#include <iostream>
#include <fstream>
using namespace std;

bool MessageFileClass::messageRead(string mesFilename)
{
  ifstream mesFile;
  mesFile.open(mesFilename.c_str());

  if (mesFile.fail())
  {
    return false;
  }

  int numRows;
  int numCols;
  mesFile >> numCols;
  mesFile >> numRows;
  mesRowCol.setRowCol(numRows, numCols);
  int encodeVal;

  for (int i = 0; i < numCols * numRows; i++)
  {
    mesFile >> encodeVal;

    if (mesFile.fail() || mesFile.eof())
    {
      int errorRowInd = (i + zeroIndexShift) / numCols;
      int errorColInd = (i + zeroIndexShift) - errorRowInd * numCols;
      cout << "Error: Reading message value at row/Col: " << errorRowInd
           << errorColInd << endl;
      return false;
    }

    oneDArrFor2DMes[i] = encodeVal;
  }
  return true;
}