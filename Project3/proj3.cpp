#include "ColorClass.h"
#include "RowColumnClass.h"
#include "ColorImageClass.h"
#include "MessageFileClass.h"
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

  cout << CHOICE_ONE << ". Encode a message from file" << "\n"
       << CHOICE_TWO << ". Perform decode" << "\n"
       << CHOICE_THREE << ". Write current image to file" << "\n"
       << CHOICE_FOUR << ". Exit the program" << "\n"
       << "Enter your choice: " << endl;
  
  int userChoice;
  cin >> userChoice;

  if (userChoice == CHOICE_ONE)
  {
    cout << "Enter name of file containing message:";
    string mesFilename;
    cin >> mesFilename;
    cout << mesFilename << endl;
    cout << "Enter row and column for message placement: ";
    int mesPlaceRow, mesPlaceCol;
    cin >> mesPlaceRow >> mesPlaceCol;
    cout << mesPlaceRow << " " << mesPlaceCol << endl;

    MessageFileClass encodeMes;
    bool validMesFound = encodeMes.messageRead(mesFilename);

    if (!validMesFound)
    {
      cout << "Message encode successful: No" << endl;
    }
    else
    {
      ppmImage.imageEncoding(mesFilename, mesPlaceRow, mesPlaceCol);
      cout << "Message encode successful: Yes" << endl;
    }
  }
  else if (userChoice == CHOICE_TWO)
  {
    ppmImage.imageDecoding();
  }
  else if (userChoice == CHOICE_THREE)
  {
    ppmImage.writeImageOut();
  }
  else if (userChoice == CHOICE_FOUR)
  {
    cout << "Thanks for using this program!" << endl;
  }
}