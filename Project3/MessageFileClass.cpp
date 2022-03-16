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

  for (int rInd = 0; rInd < numRows; rInd++)
  {
    for (int cInd = 0; cInd < numCols; cInd++)
    {
      mesFile >> encodeVal;

      if (mesFile.fail() || mesFile.eof())
      {
        cout << "Error: Reading message value at row/Col: " << rInd
            << cInd << endl;
        return false;
      }
      twoDMessage[rInd][cInd] = encodeVal;
    }
  }
  return true;
}

int MessageFileClass::getMesSize()
{
  return mesRowCol.getRow(), mesRowCol.getCol();
}

int **MessageFileClass::getEncodeMatrix()
{
  return twoDMessage;
}