#include "MessageFileClass.h"
#include "constants.h"
#include "userInterface.h"
#include "ColorImageClass.h"
#include <string>
#include <iostream>
using namespace std;

void userInterface(ColorImageClass &ppmImage)
{
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
    cout << "Enter row and column for message placement: ";
    int mesPlaceRow, mesPlaceCol;
    cin >> mesPlaceRow >> mesPlaceCol;

    MessageFileClass encodeMes;
    bool validMesFound = encodeMes.messageRead(mesFilename);

    if (!validMesFound)
    {
      cout << "Message encode successful: No" << endl;
      userInterface(ppmImage);
    }
    else
    {
      ppmImage.imageEncoding(encodeMes, mesPlaceRow, mesPlaceCol);
      cout << "Message encode successful: Yes" << endl;
      userInterface(ppmImage);
    }
  }
  
  else if (userChoice == CHOICE_TWO)
  {
    ppmImage.imageDecoding();
    cout << "Image modified to decoded image contents" << endl;
    userInterface(ppmImage);
  }
  
  else if (userChoice == CHOICE_THREE)
  {
    cout << "Enter name of file to write image to: " << endl;
    string outputFilename;
    cin >> outputFilename;
    bool validOutput = ppmImage.writeImageOut(outputFilename);
    if (validOutput)
    {
      cout << "Image write successful: Yes" << endl;
    }
    else
    {
      cout << "Image write successful: No" << endl;
    }
    userInterface(ppmImage);
  }
  
  else if (userChoice == CHOICE_FOUR)
  {
    cout << "Thanks for using this program!" << endl;
  }
}