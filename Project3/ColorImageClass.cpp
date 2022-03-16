#include "ColorImageClass.h"
#include "MessageFileClass.h"
#include "constants.h"
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
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
  
  if (inFile.fail())
  {
    cout << "Error: Unable to open image file" << endl;
    return false;
  }
  
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
  
  twoDImage = new ColorClass*[imgRowCol.getRow()];
  for (int rInd = 0; rInd < imgRowCol.getRow(); rInd++)
  {
    twoDImage[rInd] = new ColorClass[imgRowCol.getCol()];
  }
  
  for (int rInd = 0; rInd < numRows; rInd++)
  {
    for (int cInd = 0; cInd < numCols; cInd++)
    {
      inFile >> inRed;
      inFile >> inGreen;
      inFile >> inBlue;

      if (inFile.fail() || inFile.eof())
      {
        cout << "Error: Reading color from file" << endl;
        cout << "Error: Reading image pixel at row: " << rInd
            << "col: " << cInd << endl;
        cout << "Image read successful: No" << endl;
        return false;
      }

      twoDImage[rInd][cInd].setTo(inRed, inGreen, inBlue);
    }
    
  }
  cout << "Image read successful: Yes" << endl;
  return true;
}

bool ColorImageClass::imageEncoding(MessageFileClass encodeMes, 
        int mesPlaceRow, int mesPlaceCol)
{
  if (mesPlaceRow >= imgRowCol.getRow() || mesPlaceCol >= imgRowCol.getCol())
  {
    return false;
  }
  
  int mesRow, mesCol = encodeMes.getMesSize();
  int encodeVal;
  int **encodeMatrix = encodeMes.getEncodeMatrix();

  for (int encodeRowInd = max(mesPlaceRow, imageStartRow); encodeRowInd < 
       min(mesPlaceRow + mesRow, imgRowCol.getRow()); encodeRowInd++)
  {
    for (int encodeColInd = max(mesPlaceCol, imageStartCol); encodeColInd <
         min(mesPlaceCol + mesCol, imgRowCol.getCol()); encodeColInd++)
    {
      encodeVal = encodeMatrix[encodeRowInd][encodeColInd];
      twoDImage[encodeRowInd][encodeColInd].setTo(encodeVal);
    }
  }

  return true;
}

bool ColorImageClass::writeImageOut(string outputFilename)
{
  ofstream outFile;
  outFile.open(outputFilename.c_str());
  if (outFile.fail())
  {
    cout << "Error: Unable to open output file" << endl;
    return false;
  }
  
  outFile << imageType << endl;
  outFile << imgRowCol.getCol() << " " << imgRowCol.getRow() << endl;
  outFile << FULL_VAL << endl;
  for (int rInd = imageStartRow; rInd < imgRowCol.getRow(); rInd++)
  {
    for (int cInd = imageStartCol; cInd < imgRowCol.getCol(); cInd++)
    {
      // output the red, green, blue value into the file in order
      outFile << twoDImage[rInd][cInd].getRedVal() << " " 
              << twoDImage[rInd][cInd].getGreenVal() << " "
              << twoDImage[rInd][cInd].getBlueVal() << " ";
      // after each row is output, change to a new line
      if (cInd == imgRowCol.getCol() - zeroIndexShift)
      {
        outFile << "\n";
      }
    }
  }
  return true;
}