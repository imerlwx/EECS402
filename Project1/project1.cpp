#include <iostream>
using namespace std;

/* Programmer: Wengxi Li. Date: January 2022.
Purpose: This file is used to appoximate the area between a curve and the X-axis 
by fitting many rectangles between the curve and axis, whose midpoints are on 
the curve. Users could choose any interval, range and tolerance they want. */

// prints out the possible choices the user has, in a menu format
void printMenu(); 

// raises "val" to the power "power" and returns the result.
double toThePower(const double val, const int power); 

/* evaluates the cubic formula's result's sign. return false if the resulting y value
 is a negative value, or true if the resulting value is greater or equal to zero */
bool evaluateCubicFormula(const double aCoeff, const double bCoeff, 
const double cCoeff, const double dCoeff, const double xValue, double 
&resultVal);

/* approximate the area between the X-axis and the curve defined by the 
 formula using rectangles with height at the midpoint */
double approximateAreaWithRectangles(const double aCoeff, const double 
bCoeff, const double cCoeff, const double dCoeff, const double startX, 
const double endX, const int numRects);

#ifdef ANDREW_TEST 
#include "andrewTest.h" 
#else 
int main()
{
    printMenu();
    
    int userChoice;
    cout << "YOUR CHOICE: ";
    cin >> userChoice;    

    while (userChoice != 3)
    {
        double aCoeff, bCoeff, cCoeff, dCoeff;
        cout << "Enter (a b c d) for function y = a*x^3 + b*x^2 + c*x + d: ";
        cin >> aCoeff >> bCoeff >> cCoeff >> dCoeff;

        double startX, endX;
        cout << "Now enter x start and end values: ";
        cin >> startX >> endX;

        if (userChoice == 1)
        {
        int numRects;
        cout << "Enter the number of rectangles to use: ";
        cin >> numRects;

        cout << "Rectangle result is: " 
             << approximateAreaWithRectangles(aCoeff, bCoeff, cCoeff, dCoeff, startX, endX, numRects)
             << endl;

        }
        else if (userChoice == 2)
        {
        double correctAnswer;
        cout << "Enter correct answer: ";
        cin >> correctAnswer;

        double precision;
        cout << "Enter precision to reach: ";
        cin >> precision;

        int numRects = 1;
        while (numRects <= 100 && 
        (correctAnswer - approximateAreaWithRectangles(aCoeff, bCoeff, cCoeff, dCoeff, 
        startX, endX, numRects)) > precision)
        {
            numRects++;
        }
        
        if (numRects <= 100)
            cout << "Rectangles needed to reach precision: " << numRects << endl;
        else
            cout << "Tried 100 rectangles without reaching precision" << endl;

        }
        printMenu();
        cin >> userChoice;  
    }
    
    cout << "Thanks for using this program";
    return 0;           
}
#endif 

void printMenu() 
{
    cout << "1 Approximate Integral Using Rectangles" << endl;
    cout << "2 Experiment With Rectangle Precision" << endl;
    cout << "3 Quit The Program" << endl;
}

double toThePower(const double val, const int power) 
{
    double powerResult = 1; // initialize the power result

    for (int i = 0; i < power; i++)
        powerResult *= val;

    return powerResult;
}

bool evaluateCubicFormula(const double aCoeff, const double bCoeff, 
const double cCoeff, const double dCoeff, const double xValue, double 
&resultVal) 
{
    resultVal = aCoeff * toThePower(xValue, 3) + bCoeff * toThePower(xValue, 2) + cCoeff * xValue + dCoeff;
    if (resultVal < 0)
        return false;
    else
        return true;
}

double approximateAreaWithRectangles(const double aCoeff, const double 
bCoeff, const double cCoeff, const double dCoeff, const double startX, 
const double endX, const int numRects)
{
    double recWidth = (endX - startX) / numRects; // the rectangle's width
    double approArea = 0; // initialize the approxime area under the curve
    double xValue = startX + recWidth / 2; // the initial xValue equals startX plus half of the rectangle width

    for (int i = 0; i < numRects; i++)
    {        
        double recHeight = aCoeff * toThePower(xValue, 3) + bCoeff * toThePower(xValue, 2) + cCoeff * xValue + dCoeff;
        
        if (evaluateCubicFormula(aCoeff, bCoeff, cCoeff, dCoeff, xValue, recHeight))
            approArea += recHeight * recWidth; // add all the rectangles' area to get the area under the curve
        else
            approArea -= recHeight * recWidth; // when the area is negative, we should add its absolute value
        
        xValue += recWidth; // move to the midpoint of the next rectangle
    }
    return approArea;
}