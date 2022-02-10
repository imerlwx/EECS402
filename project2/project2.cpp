#include <iostream>
using namespace std;

/* Programmer: Wengxi Li. Date: February 2022.
Purpose: This project will use object-oriented programming to develop three
simple classes to represent and utilize colors and images */

class ColorClass {
  private:
    
    int redVal;
    int greenVal;
    int blueVal;
    const int FULL_VAL = 1000;
    const int ZERO_VAL = 0;
    
    // This function will check if the color value is out of range. If true, 
    // clipped it to the maximum or minimum value. Otherwise return false.
    bool clippVal(int colorVal1, const int colorVal2);

  public:
    // default ctor sets the color’s initial RGB values to the color full white
    ColorClass();  
    
    // value ctor sets the color’s initial RGB values to the values provided
    ColorClass(const int inRed, const int inGreen, const int inBlue):
    redVal(inRed), greenVal(inGreen), blueVal(inBlue)
    { ; } 

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

int main(){}

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

bool ColorClass::clippVal(int colorVal1, const int colorVal2)
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

void ColorClass::printComponentValues()const
{
  cout << "R: " << redVal << " G: " << greenVal << " B: " << blueVal << endl;
}