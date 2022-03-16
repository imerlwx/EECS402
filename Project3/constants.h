#ifndef _CONSTANTS_H_
#define _CONSTANTS_H_
#include <string>
// This file will define all the global constants used in the main
const int ARGC_NUM = 2; // the number of arguments the user needs to input
const int FULL_VAL = 255; // the largest amount in a color
const int ZERO_VAL = 0; // the smallest amount in a color
const int INIT_VAL = -99999; // default initial value of row and column
const int ZERO_INDEX_SHIFT = 1;  // The index shift to account for the zero index
const int RGB_TWEAK = 1; // tweak the RGB value by at most 1 due to encoding
const int CHOICE_ONE = 1; 
const int CHOICE_TWO = 2;
const int CHOICE_THREE = 3;
const int CHOICE_FOUR = 4;
const int IMAGE_START_ROW= 0;
const int IMAGE_START_COL = 0;
const string IMAGE_TYPE = "P3";

#endif