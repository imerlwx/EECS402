#include <iostream>
using namespace std;

/* Programmer: Wengxi Li. Date: February 2022.
Purpose: This project will use object-oriented programming to develop three
simple classes to represent and utilize colors and images */

const int NUM_ROWS = 10;  // number of rows in the image
const int NUM_COLS = 18;  // number of columns in the image

class ColorClass {
  private:
    
    int redVal; // the amount of red in a color
    int greenVal; // the amount of green in a color
    int blueVal; // the amount of blue in a color
    const int FULL_VAL; // the largest amount in a color
    const int ZERO_VAL; // the smallest amount in a color
    
    // This function will check if the color value is out of range. If true, 
    // clipped it to the maximum or minimum value. Otherwise return false.
    bool clippVal(int &colorVal1, const int colorVal2);

  public:
    // default ctor sets the color’s initial RGB values to the color full white
    ColorClass();
    
    // Value ctor sets the color’s initial RGB values to the values provided.
    // If a specified color value is outside the valid range, it will be 
    // “clipped” to ensure all ColorClass attributes are always set to be 
    // within the valid range. 
    ColorClass(const int inRed, const int inGreen, const int inBlue); 

    // function sets the color’s initial RGB values to the color full black
    void setToBlack(); 
    // function sets the color’s initial RGB values to the color full red
    void setToRed();
    // function sets the color’s initial RGB values to the color full green
    void setToGreen();
    // function sets the color’s initial RGB values to the color full blue
    void setToBlue();
    // function sets the color’s initial RGB values to the color full white
    void setToWhite();

    // This function sets the color object's RGB values to the provided values
    // If any input value is outside the allowed color value range, then the 
    // assigned value is "clipped" in order to keep the RGB color values within
    // the valid range and return true. Otherwise return false.
    bool setTo(const int inRed, const int inGreen, const int inBlue);
    // This function sets the color's component color values to the same as 
    // those in the "inColor" input parameter object. The function returns true
    // if any clipping was necessary, otherwise the function returns false. 
    bool setTo(const ColorClass &inColor);
    
    // This function causes each RGB value to have the corresponding value from
    // the input parameter color added to it.
    bool addColor(const ColorClass &rhsColor);    
    // This function causes each RGB value to have the corresponding value from
    // the input parameter subtracted from it.
    bool subtractColor(const ColorClass &rhsColor);
    // This function performs a simplified brightness adjustment which 
    // multiplies each RGB value by the adjustment factor provided. If 
    // adjFactor is greater than 1, the color gets brighter, if adjFactor is 
    // less than 1, the color gets dimmer. the RGB values will still be in the
    // allowed color value range.
    bool adjustBrightness(const double adjFactor);

    // Prints the component color values to the console using the following 
    // format: "R: <red> G: <green> B: <blue>" where <red>, <green>, <blue>
    // are all replaced with their corresponding component color values.
    void printComponentValues()const;
};

// This class is to uniquely identify a specific pixel within an image.  
class RowColumnClass
{
  private:
    int rowVal;
    int colVal; 
	  const int INIT_VAL;
    
  public:
    // This default constructor simply sets both the row and column value 
	  // of the newly created RowColumnClass object to -99999. 
	  RowColumnClass();
	  // This value constructor simply sets the row and column values to the 
	  // corresponding values passed into the constructor. 
	  RowColumnClass(const int inRow, const int inCol);
	
	  // These functions are simple “setter functions” that just directly set
	  // the appropriate attribute(s) to the value(s) provided. 
    void setRowCol(const int inRow, const int inCol); 
    void setRow(const int inRow);  
    void setCol(const int inCol);
    
	  // These functions are simple “getter functions” that just return the 
	  // appropriate attribute value to the caller. 
    int getRow() const;
	  int getCol() const;
	
    // This function adds the row and column index values in the input 
	  // parameter to the row and column index of the object the function 
	  // is called on 
    void addRowColTo(const RowColumnClass &inRowCol);	
	
	  // This function prints this object's attribute's in the format 
	  // "[<row>,<col>]" where <row> and <col> are replaced with the value 
	  // of the corresponding attribute values.
	  void printRowCol() const;
};

class ImageClass
{
  private:
    // the attribute is a numRows * numCols 2D matrix

    ColorClass imageAry[NUM_ROWS][NUM_COLS];
    
    // If the location specified is a valid location for the image, returns 
    // true, otherwise returns false.
    bool checkLoc(const RowColumnClass &inRolCol) const;
    // This function will initialize all the imageAry to black
    void initializeToBlack();

  public:
    
    // This default constructor sets all pixels in the image to full black
    ImageClass();
    // This function assigns all image pixels to the color provided via input
    // parameter “inColor”
    void initializeTo(const ColorClass &inColor);
    
    // This function performs a pixel-wise addition, such that each pixel in 
    // the image has the pixel in the corresponding location in the right hand
    // side input image added to it.
    bool addImageTo(const ImageClass &rhsImage);
    // This function causes the image's pixel values to be set to the sum of
    // the corresponding pixels in each image in the imagesToAdd parameter.
    bool addImages(const int numImgsToAdd, const ImageClass imagesToAdd []);

    // This function attempts to set the pixel at the location specified by the
    // “inRowCol” parameter to the color specified via the “inColor” parameter.
    bool setColorAtLocation(const RowColumnClass &inRowCol, 
      const ColorClass &inColor);
    // If the row/column provided is a valid row/column for the image, this 
    // function returns true and the output reference parameter "outColor" is
    // assigned to the color of the image pixel at that location. Otherwise 
    // return false and do not modify anything.
    bool getColorAtLocation(const RowColumnClass &inRowCol, 
      ColorClass &outColor) const;

    // This function prints the contents of the image to the screen. Each 
    // pixel is printed using the format described for the ColorClass above.
    void printImage() const;
};

int main()
{
  ColorClass testColor;
  RowColumnClass testRowCol;
  RowColumnClass testRowColOther(111, 222);
  ImageClass testImage;
  ImageClass testImages[3];
  //Test some basic ColorClass operations...
  cout << "Initial: ";
  testColor.printComponentValues();
  cout << endl;
  testColor.setToBlack();
  cout << "Black: ";
  testColor.printComponentValues();
  cout << endl;
  testColor.setToGreen();
  cout << "Green: ";
  testColor.printComponentValues();
  cout << endl;
  testColor.adjustBrightness(0.5);
  cout << "Dimmer Green: ";
  testColor.printComponentValues();
  cout << endl;
  //Test some basic RowColumnClass operations...
  cout << "Want defaults: ";
  testRowCol.printRowCol();
  cout << endl;
  testRowCol.setRowCol(2, 8);
  cout << "Want 2,8: ";
  testRowCol.printRowCol();
  cout << endl;
  cout << "Want 111, 222: ";
  testRowColOther.printRowCol();
  cout << endl;
  testRowColOther.setRowCol(4, 2);
  testRowCol.addRowColTo(testRowColOther);
  cout << "Want 6,10: ";
  testRowCol.printRowCol();
  cout << endl;
  //Test some basic ColorImageClass operations...
  testColor.setToRed();
  testImage.initializeTo(testColor);
  testRowCol.setRowCol(555, 5);
  cout << "Want: Color at [555,5]: Invalid Index!" << endl;
  cout << "Color at ";
  testRowCol.printRowCol();
  cout << ": ";
  if (testImage.getColorAtLocation(testRowCol, testColor))
  {
    testColor.printComponentValues();
  }
  else
  {
    cout << "Invalid Index!";
  }
  cout << endl;
  testRowCol.setRow(4);
  cout << "Want: Color at [4,5]: R: 1000 G: 0 B: 0" << endl;
  cout << "Color at ";
  testRowCol.printRowCol();
  cout << ": ";
  if (testImage.getColorAtLocation(testRowCol, testColor))
  {
    testColor.printComponentValues();
  }
  else
  {
    cout << "Invalid Index!";
  }
  cout << endl;
  //Set up an array of images of different colors
  testColor.setToRed();
  testColor.adjustBrightness(0.25);
  testImages[0].initializeTo(testColor);
  testColor.setToBlue();
  testColor.adjustBrightness(0.75);
  testImages[1].initializeTo(testColor);
  testColor.setToGreen();
  testImages[2].initializeTo(testColor);
  //Modify a few individual pixel colors
  testRowCol.setRowCol(4, 2);
  testColor.setToWhite();
  testImages[1].setColorAtLocation(testRowCol, testColor);
  testRowCol.setRowCol(2, 4);
  testColor.setToBlack();
  testImages[2].setColorAtLocation(testRowCol, testColor);
  //Add up all images in testImages array and assign result
  //to the testImage image
  testImage.addImages(3, testImages);
  //Check some certain values
  cout << "Added values:" << endl;
  for (int colInd = 0; colInd < 8; colInd += 2)
  {
    testRowCol.setRowCol(4, colInd);
    cout << "Color at ";
    testRowCol.printRowCol();
    cout << ": ";
    if (testImage.getColorAtLocation(testRowCol, testColor))
    {
      testColor.printComponentValues();
    }
    else
    {
      cout << "Invalid Index!";
    }
    cout << endl;
  }
  for (int rowInd = 0; rowInd < 8; rowInd += 2)
  {
    testRowCol.setRowCol(rowInd, 4);
    cout << "Color at ";
    testRowCol.printRowCol();
    cout << ": ";
    if (testImage.getColorAtLocation(testRowCol, testColor))
    {
      testColor.printComponentValues();
    }
    else
    {
      cout << "Invalid Index!";
    }
    cout << endl;
  }
  cout << "Printing entire test image:" << endl;
  testImage.printImage();
  return 0;
}

ColorClass::ColorClass(): FULL_VAL(1000), ZERO_VAL(0)
{
  setToWhite();
}

ColorClass::ColorClass(const int inRed, const int inGreen, const int inBlue)
: FULL_VAL(1000), ZERO_VAL(0)
{
  clippVal(redVal, inRed);
  clippVal(greenVal, inGreen);
  clippVal(blueVal, inBlue);
}

void ColorClass::setToBlack()
{
  redVal = ZERO_VAL;
  greenVal = ZERO_VAL;
  blueVal = ZERO_VAL;
}

void ColorClass::setToRed()
{
  redVal = FULL_VAL;
  greenVal = ZERO_VAL;
  blueVal = ZERO_VAL;
}

void ColorClass::setToGreen()
{
  redVal = ZERO_VAL;
  greenVal = FULL_VAL;
  blueVal = ZERO_VAL;
}

void ColorClass::setToBlue()
{
  redVal = ZERO_VAL;
  greenVal = ZERO_VAL;
  blueVal = FULL_VAL;
}

void ColorClass::setToWhite()
{
  redVal = FULL_VAL;
  greenVal = FULL_VAL;
  blueVal = FULL_VAL;
}

bool ColorClass::clippVal(int &colorVal1, const int colorVal2)
{
  if (colorVal2 > FULL_VAL || colorVal2 < ZERO_VAL)
  {
    if (colorVal2 > FULL_VAL)
    {
      colorVal1 = FULL_VAL;
    }
    else
    {
      colorVal1 = ZERO_VAL;
    }
    return true;
  }
  else
  {
    colorVal1 = colorVal2;
    return false;
  }
}

bool ColorClass::setTo(const int inRed, const int inGreen, const int inBlue)
{
  // Only if all the three value are return false will this whole function 
  // return false. 
  return (clippVal(redVal, inRed) || clippVal(greenVal, inGreen) || 
          clippVal(blueVal, inBlue));
}

bool ColorClass::setTo(const ColorClass &inColor)
{  
  redVal = inColor.redVal;
  greenVal = inColor.greenVal;
  blueVal = inColor.blueVal;
  return false; 
}

bool ColorClass::addColor(const ColorClass &rhsColor)
{
  redVal += rhsColor.redVal;
  greenVal += rhsColor.greenVal;
  blueVal += rhsColor.blueVal;
  return setTo(redVal, greenVal, blueVal);
}

bool ColorClass::subtractColor(const ColorClass &rhsColor)
{
  redVal -= rhsColor.redVal;
  greenVal -= rhsColor.greenVal;
  blueVal -= rhsColor.blueVal;
  return setTo(redVal, greenVal, blueVal);
}

bool ColorClass::adjustBrightness(const double adjFactor)
{
  // redVal, greenVal and blueVal are integer, so it needs to type casting
  redVal = int(adjFactor * redVal);
  greenVal = int(adjFactor * greenVal);
  blueVal = int(adjFactor * blueVal);
  return setTo(redVal, greenVal, blueVal);
}

void ColorClass::printComponentValues() const
{
  cout << "R: " << redVal << " G: " << greenVal << " B: " << blueVal;
}

RowColumnClass::RowColumnClass(): INIT_VAL(-99999)
{
  rowVal = INIT_VAL;
  colVal = INIT_VAL;
}

RowColumnClass::RowColumnClass(const int inRow, const int inCol)
: INIT_VAL(-99999)
{
  rowVal = inRow;
  colVal = inCol;
}

void RowColumnClass::setRowCol(const int inRow, const int inCol)
{
  rowVal = inRow;
  colVal = inCol;
}

void RowColumnClass::setRow(const int inRow)
{
  rowVal = inRow;
}  

void RowColumnClass::setCol(const int inCol)
{
  colVal = inCol;
}

int RowColumnClass::getRow() const
{
  return rowVal;
}

int RowColumnClass::getCol() const
{
  return colVal;
}

void RowColumnClass::addRowColTo(const RowColumnClass &inRowCol)
{
  rowVal += inRowCol.rowVal;
  colVal += inRowCol.colVal;
}

void RowColumnClass::printRowCol() const
{
  cout << "[" << rowVal << ", " << colVal << "]";
}

ImageClass::ImageClass()
{
  initializeToBlack();
};

void ImageClass::initializeToBlack()
{
  for (int i = 0; i <  NUM_ROWS; i++)
  {
    for (int j = 0; j < NUM_COLS; j++)
    {
      imageAry[i][j].setToBlack();
    }
  }
}

void ImageClass::initializeTo(const ColorClass &inColor)
{
  for (int i = 0; i <  NUM_ROWS; i++)
  {
    for (int j = 0; j < NUM_COLS; j++)
    {
      imageAry[i][j].setTo(inColor);
    }
  }
}

bool ImageClass::addImageTo(const ImageClass &rhsImage)
{
  bool clipOrNot = false;

  for (int i = 0; i <  NUM_ROWS; i++)
  {
    for (int j = 0; j < NUM_COLS; j++)
    {
      if (imageAry[i][j].addColor(rhsImage.imageAry[i][j]))
      {
        clipOrNot = true;
      }
    }
  }
  return clipOrNot;
}

bool ImageClass::addImages(const int numImgsToAdd, 
  const ImageClass imagesToAdd [])
{
  initializeToBlack();
  bool clipOrNot = false;
  for (int i = 0; i < numImgsToAdd; i++)
  {
    if (addImageTo(imagesToAdd[i]))
    {
      clipOrNot = true;
    }
  }
  return clipOrNot;
}

bool ImageClass::setColorAtLocation(const RowColumnClass &inRowCol, 
  const ColorClass &inColor)
{
  if (checkLoc(inRowCol))
  {
    imageAry[inRowCol.getRow()][inRowCol.getCol()].setTo(inColor);
    return true;
  }
  else
  {
    return false;
  }
}

bool ImageClass::getColorAtLocation(const RowColumnClass &inRowCol, 
  ColorClass &outColor) const
{
  if (checkLoc(inRowCol))
  {
    outColor.setTo(imageAry[inRowCol.getRow()][inRowCol.getCol()]);
    return true;
  }
  else
  {
    return false;
  }
}

void ImageClass::printImage() const
{
  for (int i = 0; i <  NUM_ROWS; i++)
  {
    for (int j = 0; j < NUM_COLS; j++)
    {
      if (j != 0)
      {
        cout << "--";
      }
      imageAry[i][j].printComponentValues();     
    }
    cout << "\n";
  }
}

bool ImageClass::checkLoc(const RowColumnClass &inRolCol) const
{
  if (inRolCol.getRow() > NUM_ROWS || inRolCol.getCol() > NUM_COLS)
  {
    return false;
  }
  else
  {
    return true;
  }
}
