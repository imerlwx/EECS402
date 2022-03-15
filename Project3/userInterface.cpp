#include "MessageFileClass.h"
#include "constants.h"
#include "userInterface.h"
#include "ColorImageClass.h"
#include <string>
#include <iostream>
using namespace std;

void userInterface(ColorImageClass ppmImage)
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
      userInterface(ppmImage);
    }
    else
    {
      ppmImage.imageEncoding(mesFilename, mesPlaceRow, mesPlaceCol);
      cout << "Message encode successful: Yes" << endl;
      userInterface(ppmImage);
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