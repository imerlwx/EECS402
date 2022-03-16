// for (int i = 0; i < numCols * numRows; i++)
  // {
  //   inFile >> inRed;
  //   inFile >> inGreen;
  //   inFile >> inBlue;

  //   if (inFile.fail() || inFile.eof())
  //   {
  //     int errorRowInd = (i + zeroIndexShift) / numCols;
  //     int errorColInd = (i + zeroIndexShift) - errorRowInd * numCols;
  //     cout << "Error: Reading color from file" << endl;
  //     cout << "Error: Reading image pixel at row: " << errorRowInd
  //          << "col: " << errorColInd << endl;
  //     cout << "Image read successful: No" << endl;
  //     return false;
  //   }

  //   oneDArrFor2DImg[i].setTo(inRed, inGreen, inBlue);
  // }

  // the attribute is a numRows * numCols 1D dynamic allocated array pointer
    // for a 2D matrix of (numRows, numCols)
    // ColorClass *oneDArrFor2DImg = new ColorClass[imgRowCol.getRow()
    //     * imgRowCol.getCol()];


// for (int i = 0; i < numCols * numRows; i++)
  // {
  //   mesFile >> encodeVal;

  //   if (mesFile.fail() || mesFile.eof())
  //   {
  //     int errorRowInd = (i + zeroIndexShift) / numCols;
  //     int errorColInd = (i + zeroIndexShift) - errorRowInd * numCols;
  //     cout << "Error: Reading message value at row/Col: " << errorRowInd
  //          << errorColInd << endl;
  //     return false;
  //   }

  //   oneDArrFor2DMes[i] = encodeVal;
  // }

  // cout << CHOICE_ONE << ". Encode a message from file" << "\n"
  //      << CHOICE_TWO << ". Perform decode" << "\n"
  //      << CHOICE_THREE << ". Write current image to file" << "\n"
  //      << CHOICE_FOUR << ". Exit the program" << "\n"
  //      << "Enter your choice: " << endl;
  
  // int userChoice;
  // cin >> userChoice;

  // if (userChoice == CHOICE_ONE)
  // {
  //   cout << "Enter name of file containing message:";
  //   string mesFilename;
  //   cin >> mesFilename;
  //   cout << mesFilename << endl;
  //   cout << "Enter row and column for message placement: ";
  //   int mesPlaceRow, mesPlaceCol;
  //   cin >> mesPlaceRow >> mesPlaceCol;
  //   cout << mesPlaceRow << " " << mesPlaceCol << endl;

  //   MessageFileClass encodeMes;
  //   bool validMesFound = encodeMes.messageRead(mesFilename);

  //   if (!validMesFound)
  //   {
  //     cout << "Message encode successful: No" << endl;
  //   }
  //   else
  //   {
  //     ppmImage.imageEncoding(encodeMes, mesPlaceRow, mesPlaceCol);
  //     cout << "Message encode successful: Yes" << endl;
  //   }
  // }

  // else if (userChoice == CHOICE_TWO)
  // {
  //   ppmImage.imageDecoding();
  // }

  // else if (userChoice == CHOICE_THREE)
  // {
  //   ppmImage.writeImageOut();
  // }

  // else if (userChoice == CHOICE_FOUR)
  // {
  //   cout << "Thanks for using this program!" << endl;
  // }