#include "ColorClass.h"
#include "RowColumnClass.h"
#include "ColorImageClass.h"
#include "MessageFileClass.h"
#include "userInterface.h"
#include "constants.h"
#include <iostream>
#include <fstream>
using namespace std;
#include <cstdlib>
#include <string>

int main(int argc, char *argv[])
{
  if (argc != ARGC_NUM)
  {
    cout << "Usage: " << argv[0] << "<startPPM.ppm>" << endl;
    exit(2);
  }
  
  string inputFilename = argv[1];    
  ColorImageClass ppmImage;
  bool validInputFound = ppmImage.imageRead(inputFilename);

  if (!validInputFound)
  {
    cout << "While reading the image, an error was encountered." 
    << "Exiting the program!" << endl;
    exit(3);
  }

  userInterface(ppmImage);
}