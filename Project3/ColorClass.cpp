#include "ColorClass.h"
#include "constants.h"
#include <iostream>
using namespace std;

ColorClass::ColorClass(){}

ColorClass::ColorClass(const int inRed, const int inGreen, const int inBlue)
{
  clippVal(redVal, inRed);
  clippVal(greenVal, inGreen);
  clippVal(blueVal, inBlue);
}

void ColorClass::encToBlack()
{
  setToEven(redVal);
  setToEven(greenVal);
  setToEven(blueVal);
}

void ColorClass::encToRed()
{
  setToOdd(redVal);
  setToEven(greenVal);
  setToEven(blueVal);
}

void ColorClass::encToGreen()
{
  setToEven(redVal);
  setToOdd(greenVal);
  setToEven(blueVal);
}

void ColorClass::encToBlue()
{
  setToEven(redVal);
  setToEven(greenVal);
  setToOdd(blueVal);
}

void ColorClass::encToWhite()
{
  setToOdd(redVal);
  setToOdd(greenVal);
  setToOdd(blueVal);
}

void ColorClass::encToYellow()
{
  setToOdd(redVal);
  setToOdd(greenVal);
  setToEven(blueVal);
}

void ColorClass::encToMagenta()
{
  setToOdd(redVal);
  setToEven(greenVal);
  setToOdd(blueVal);
}

void ColorClass::encToCyan()
{
  setToEven(redVal);
  setToOdd(greenVal);
  setToOdd(blueVal);
}

void ColorClass::decToBlack()
{
  setTo(FULL_VAL, FULL_VAL, FULL_VAL);
}

void ColorClass::decToRed()
{
  setTo(FULL_VAL, ZERO_VAL, ZERO_VAL);
}

void ColorClass::decToGreen()
{
  setTo(ZERO_VAL, FULL_VAL, ZERO_VAL);
}

void ColorClass::decToBlue()
{
  setTo(ZERO_VAL, ZERO_VAL, FULL_VAL);
}

void ColorClass::decToWhite()
{
  setTo(ZERO_VAL, ZERO_VAL, ZERO_VAL);
}

void ColorClass::decToYellow()
{
  setTo(FULL_VAL, FULL_VAL, ZERO_VAL);
}

void ColorClass::decToMagenta()
{
  setTo(FULL_VAL, ZERO_VAL, FULL_VAL);
}

void ColorClass::decToCyan()
{
  setTo(ZERO_VAL, FULL_VAL, FULL_VAL);
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

bool ColorClass::encodeVal(const int encodeVal)
{
  if (encodeVal < MIN_ENCODE_NUM || encodeVal > MAX_ENCODE_NUM)
  {
    return false;
  }
  
  switch(encodeVal)
  {
  case 0:
    encToBlack();
    break;
  case 1:
    encToRed();
    break;
  case 2:
    encToGreen();
    break;
  case 3:
    encToBlue();
    break;
  case 4:
    encToWhite();
    break;
  case 5:
    encToYellow();
    break;
  case 6:
    encToMagenta();
    break;
  case 7:
    encToCyan();
    break;
  }
  
  return true;
}

bool ColorClass::decodeVal()
{
  if (redVal % 2 == 0 && greenVal % 2 == 0 && blueVal % 2 == 0)
  {
    decToBlack();
  }
  else if (redVal % 2 != 0 && greenVal % 2 == 0 && blueVal % 2 == 0)
  {
    decToRed();
  }
  else if (redVal % 2 == 0 && greenVal % 2 != 0 && blueVal % 2 == 0)
  {
    decToGreen();
  }
  else if (redVal % 2 == 0 && greenVal % 2 == 0 && blueVal % 2 != 0)
  {
    decToBlue();
  }
  else if (redVal % 2 != 0 && greenVal % 2 != 0 && blueVal % 2 != 0)
  {
    decToWhite();
  }
  else if (redVal % 2 != 0 && greenVal % 2 != 0 && blueVal % 2 == 0)
  {
    decToYellow();
  }
  else if (redVal % 2 != 0 && greenVal % 2 == 0 && blueVal % 2 != 0)
  {
    decToMagenta();
  }
  else if (redVal % 2 == 0 && greenVal % 2 != 0 && blueVal % 2 != 0)
  {
    decToCyan();
  }
  return true;
}

void ColorClass::setToEven(int rgbVal)
{
  if (rgbVal % 2 != 0) // if it is not even, tweak it
  {
    rgbVal -= RGB_TWEAK;
  }
}

void ColorClass::setToOdd(int rgbVal)
{
  if (rgbVal % 2 == 0) // if it is not odd, tweak it
  {
    rgbVal += RGB_TWEAK;
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

int ColorClass::getRedVal()const
{
  return redVal;
}

int ColorClass::getGreenVal()const
{
  return greenVal;
}

int ColorClass::getBlueVal()const
{
  return blueVal;
}

void ColorClass::printComponentValues() const
{
  cout << "R: " << redVal << " G: " << greenVal << " B: " << blueVal;
}