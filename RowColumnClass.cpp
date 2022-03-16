#include "RowColumnClass.h"
#include "constants.h"
#include <iostream>
using namespace std;

RowColumnClass::RowColumnClass()
{
  rowVal = INIT_VAL;
  colVal = INIT_VAL;
}

RowColumnClass::RowColumnClass(const int inRow, const int inCol)
{
  setRowCol(inRow, inCol);
}

void RowColumnClass::setRowCol(const int inRow, const int inCol)
{
  setRow(inRow);
  setCol(inCol);
}

void RowColumnClass::setRow(const int inRow)
{
  rowVal = inRow;
}  

void RowColumnClass::setCol(const int inCol)
{
  colVal = inCol;
}

int RowColumnClass::getRow() const
{
  return rowVal;
}

int RowColumnClass::getCol() const
{
  return colVal;
}

void RowColumnClass::addRowColTo(const RowColumnClass &inRowCol)
{
  rowVal += inRowCol.rowVal;
  colVal += inRowCol.colVal;
}

void RowColumnClass::printRowCol() const
{
  cout << "[" << rowVal << "," << colVal << "]";
}
