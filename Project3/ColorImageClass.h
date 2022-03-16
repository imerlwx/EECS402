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
    ColorClass **twoDImage; // Pointer to a pointer to construct a "2D" array

  public:
    // This function will read the image
    bool imageRead(string inputFilename);
    // This function will encode the image to include some information, if the
    // image does not have any change (message is all out of bounds), return 
    // false. Otherwise return true.
    bool imageEncoding(MessageFileClass encodeMes, int mesPlaceRow, 
      int mesPlaceCol);
    // This function will decode the image to look for the information
    bool imageDecoding();
    // This function will write the decoded image into an image file PPM
    bool writeImageOut(string outputFilename);

};

#endif