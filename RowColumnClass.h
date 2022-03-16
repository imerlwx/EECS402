#ifndef _ROWCOLUMNCLASS_H_
#define _ROWCOLUMNCLASS_H_

// This class is to uniquely identify a specific pixel within an image.  
class RowColumnClass
{
  private:
    int rowVal;
    int colVal; 
    
  public:
    // This default constructor simply sets both the row and column value 
    // of the newly created RowColumnClass object to -99999. 
    RowColumnClass();
    // This value constructor simply sets the row and column values to the 
    // corresponding values passed into the constructor. 
    RowColumnClass(const int inRow, const int inCol);

    // These functions are simple “setter functions” that just directly set
    // the appropriate attribute(s) to the value(s) provided. 
    void setRowCol(const int inRow, const int inCol); 
    void setRow(const int inRow);  
    void setCol(const int inCol);
    
    // These functions are simple “getter functions” that just return the 
    // appropriate attribute value to the caller. 
    int getRow() const;
    int getCol() const;

    // This function adds the row and column index values in the input 
    // parameter to the row and column index of the object the function 
    // is called on 
    void addRowColTo(const RowColumnClass &inRowCol);

    // This function prints this object's attribute's in the format 
    // "[<row>,<col>]" where <row> and <col> are replaced with the value 
    // of the corresponding attribute values.
    void printRowCol() const;
};

#endif