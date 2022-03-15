#ifndef _COLORIMAGECLASS_H_
#define _COLORIMAGECLASS_H_
#include "ColorClass.h"
#include "RowColumnClass.h"
#include <string>
#include <fstream>

class ColorImageClass
{
  private:
    RowColumnClass imgRowCol;  // an object to store the row and column info
    int maxAllowedVal;  // the max allowed value for the RGB values
    string fileType;  // The type of the file
    // the attribute is a numRows * numCols 1D dynamic allocated array pointer
    // for a 2D matrix of (numRows, numCols)
    ColorClass *oneDArrFor2DImg = new ColorClass[imgRowCol.getRow()
        * imgRowCol.getCol()];

    // int **twoDImage = new int*[imgRowCol.getRow()];
    // for (int rInd = 0; rInd < imgRowCol.getRow(); rInd++)
    // {
    //   twoDImage[rInd] = new ColorClass[imgRowCol.getCol()];
    // }

  public:   
    // This function will read the image
    bool imageRead(string inputFilename);
    // This function will encode the image to include some information
    bool imageEncoding(string mesFilename, int mesPlaceRow, int mesPlaceCol);
    // This function will decode the image to look for the information
    bool imageDecoding();
    // This function will write the decoded image into an image file PPM
    bool writeImageOut();

};

#endif