#include "ColorImageClass.h"
#include "MessageFileClass.h"
#include "constants.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

ColorImageClass::ColorImageClass(){}

bool ColorImageClass::imageRead(string inputFilename)
{
  int numRows;
  int numCols;
  int inRed;
  int inGreen;
  int inBlue;

  ifstream inFile;
  inFile.open(inputFilename.c_str());
  cout << "Reading initial image from: " << inputFilename << endl;
  
  inFile >> fileType;
  inFile >> numRows;
  inFile >> numCols;
  inFile >> maxAllowedVal;
  imgRowCol.setRowCol(numRows, numCols);

  if (fileType != "P3" || maxAllowedVal != FULL_VAL)
  {
    cout << "Error: Incorrect formatted image" << endl;
    cout << "Image read successful: No" << endl;
    return false;
  }

  for (int i = 0; i < numCols * numRows; i++)
  {
    inFile >> inRed;
    inFile >> inGreen;
    inFile >> inBlue;

    if (inFile.fail() || inFile.eof())
    {
      int errorRowInd = (i + zeroIndexShift) / numCols;
      int errorColInd = (i + zeroIndexShift) - errorRowInd * numCols;
      cout << "Error: Reading color from file" << endl;
      cout << "Error: Reading image pixel at row: " << errorRowInd
           << "col: " << errorColInd << endl;
      cout << "Image read successful: No" << endl;
      return false;
    }

    oneDArrFor2DImg[i].setTo(inRed, inGreen, inBlue);
  }
  cout << "Image read successful: Yes" << endl;
  return true;
}

bool ColorImageClass::imageEncoding(string mesFilename, int mesPlaceRow, 
        int mesPlaceCol)
{
  
}