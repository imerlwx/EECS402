#ifndef _COLORCLASS_H_
#define _COLORCLASS_H_

// This class will contain information about describing a color
class ColorClass 
{  
  private:    
    int redVal; // the amount of red in a color
    int greenVal; // the amount of green in a color
    int blueVal; // the amount of blue in a color
    
    // This function will check if the color value is out of range. If true,
    // clipped it to the maximum or minimum value. Otherwise return false.
    bool clippVal(int &colorVal1, const int colorVal2);

  public:
    // default ctor sets the color’s initial RGB values to full white
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
    // function sets the color’s initial RGB values to the color yellow
    void setToYellow();
    // function sets the color’s initial RGB values to the color magenta
    void setToMagenta();
    // function sets the color’s initial RGB values to the color cyan
    void setToCyan();
    // function sets one of the RGB value to even number
    void setToEven(int rgbVal); 
    // function sets one of the RGB value to odd number
    void setToOdd(int rgbVal);  

    // This function sets the color object's RGB values to the provided values
    // If any input value is outside the allowed color value range, then the 
    // assigned value is "clipped" in order to keep the RGB color values 
    // within the valid range and return true. Otherwise return false.
    bool setTo(const int inRed, const int inGreen, const int inBlue);
    // This function sets the color's component color values to the same as 
    // those in the "inColor" input parameter object. The function returns 
    // true if any clipping was necessary, otherwise it returns false. 
    bool setTo(const ColorClass &inColor);
    // This function will set the color to what the encode number defines.
    // There are 8 encodeVal from 0 ~ 7, and 8 colors in the order of : Black,
    // Red, Green, Blue, White, Yellow, Magenta, Cyan
    bool setTo(const int encodeVal);
    
    // This function causes each RGB value to have the corresponding value 
    // from the input parameter color added to it.
    bool addColor(const ColorClass &rhsColor);    
    // This function causes each RGB value to have the corresponding value 
    // from the input parameter subtracted from it.
    bool subtractColor(const ColorClass &rhsColor);
    // This function performs a simplified brightness adjustment which 
    // multiplies each RGB value by the adjustment factor provided. If 
    // adjFactor is greater than 1, the color gets brighter, if adjFactor is 
    // less than 1, the color gets dimmer. the RGB values will still be in 
    // the allowed color value range.
    bool adjustBrightness(const double adjFactor);

    // Prints the component color values to the console using the following 
    // format: "R: <red> G: <green> B: <blue>" where <red>, <green>, <blue>
    // are all replaced with their corresponding component color values.
    void printComponentValues()const;
};

#endif