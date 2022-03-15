#include "ColorClass.h"
#include "constants.h"
#include <iostream>
using namespace std;

ColorClass::ColorClass()
{
  setToWhite();
}

ColorClass::ColorClass(const int inRed, const int inGreen, const int inBlue)
{
  clippVal(redVal, inRed);
  clippVal(greenVal, inGreen);
  clippVal(blueVal, inBlue);
}

void ColorClass::setToBlack()
{
  setToEven(redVal);
  setToEven(greenVal);
  setToEven(blueVal);
}

void ColorClass::setToRed()
{
  setToOdd(redVal);
  setToEven(greenVal);
  setToEven(blueVal);
}

void ColorClass::setToGreen()
{
  setToEven(redVal);
  setToOdd(greenVal);
  setToEven(blueVal);
}

void ColorClass::setToBlue()
{
  setToEven(redVal);
  setToEven(greenVal);
  setToOdd(blueVal);
}

void ColorClass::setToWhite()
{
  setToOdd(redVal);
  setToOdd(greenVal);
  setToOdd(blueVal);
}

void ColorClass::setToYellow()
{
  setToOdd(redVal);
  setToOdd(greenVal);
  setToEven(blueVal);
}

void ColorClass::setToMagenta()
{
  setToOdd(redVal);
  setToEven(greenVal);
  setToOdd(blueVal);
}

void ColorClass::setToCyan()
{
  setToEven(redVal);
  setToOdd(greenVal);
  setToOdd(blueVal);
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
  bool checkRed = clippVal(redVal, inRed);
  bool checkGreen = clippVal(greenVal, inGreen);
  bool checkBlue = clippVal(blueVal, inBlue);
  // Only if all the three value are return false will this whole function 
  // return false. 
  return (checkRed || checkGreen || checkBlue);
}

bool ColorClass::setTo(const ColorClass &inColor)
{  
  redVal = inColor.redVal;
  greenVal = inColor.greenVal;
  blueVal = inColor.blueVal;
  return false; 
}

bool ColorClass::setTo(const int encodeVal)
{
  if (encodeVal < 0 || encodeVal > 7)
  {
    return false;
  }
  
  switch(encodeVal)
  {
    case 0:
      setToBlack();
      break;
    case 1:
      setToRed();
      break;
    case 2:
      setToGreen();
      break;
    case 3:
      setToBlue();
      break;
    case 4:
      setToWhite();
      break;
    case 5:
      setToYellow();
      break;
    case 6:
      setToMagenta();
      break;
    case 7:
      setToCyan();
      break;
  }
  return true;
}

void ColorClass::setToEven(int rgbVal)
{
  if (rgbVal % 2 != 0) // if it is not even, tweak it
  {
    rgbVal -= rgbTreak;
  }
}

void ColorClass::setToOdd(int rgbVal)
{
  if (rgbVal % 2 == 0) // if it is not odd, tweak it
  {
    rgbVal += rgbTreak;
  }
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