/*______________________________________
* FILE: HW_06_DAY_OF_YEAR_JC.cpp
* AUTHOR: Josh Clemens
* MODULE: 6
* PROJECT: 1
* LAST MODIFIED: October 01, 2022
* PROBLEM STATEMENT: Use DayOfYear class to calculate the month and day in the month to be output.
* ALGORITHM:
*   INITIALIZE DayOfYear class to accept two constructors, one for a single data type "day" and one for two data types "day" and "month."
*       VALIDATE day and month to be in range of respective month and month name to match a real month.
*       CALCULATE month name, day of the month and day of the year for both constructors
*       OVERLOAD ++ & -- operators for prefix and postfix calculations
*       CALCULATE for first and last day scenarios after using ++ & -- operators
*       OVERLOAD << operator for output
*   INITIALIZE class objects of DayOfYear class for testing, using both constructors
*   CALCULATE using ++ & -- operators for prefix and postfix calculations
*   OUTPUT results
*   VALIDATE input with incorrect information to show how bad data is handled
*______________________________________*/

#include "DayOfYear.h"
#include <iostream>

using namespace std;

const string DayOfYear::monthNames[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
const int DayOfYear::monthValues[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};

int main() {

    cout << "Welcome to the Day of the Year program!!!\n\n";

    //use first constructor to create objects
    cout << "Uses first constructor to create objects\n";
    DayOfYear dayObjOne(15);
    DayOfYear dayObjTwo(31);
    DayOfYear dayObjThree(59);
    DayOfYear dayObjFour(180);
    DayOfYear dayObjFive(360);

    //output
    cout << dayObjOne;
    cout << dayObjTwo;
    cout << dayObjThree;
    cout << dayObjFour;
    cout << dayObjFive;
    cout << endl;

    //use second constructor to create objects
    cout << "Uses second constructor to create objects\n";
    DayOfYear dayObjSix("January", 1);
    DayOfYear dayObjSeven("March", 4);
    DayOfYear dayObjEight("July", 25);
    DayOfYear dayObjNine("December", 31);

    //output
    cout << dayObjSix;
    cout << dayObjSeven;
    cout << dayObjEight;
    cout << dayObjNine;
    cout << endl;

    //use prefix --dayObjSix
    cout << "Using: " << dayObjSix;
    cout << "The original value: " << dayObjSix;
    cout << "Using --prefix    : " << --dayObjSix;
    cout << "After --prefix    : " << dayObjSix;
    cout << endl;

    //use prefix ++dayObjSeven
    cout << "Using: " << dayObjSeven;
    cout << "The original value: " << dayObjSeven;
    cout << "Using ++prefix    : " << ++dayObjSeven;
    cout << "After ++prefix    : " << dayObjSeven;
    cout << endl;

    //use postfix dayObjEight--
    cout << "Using: " << dayObjEight;
    cout << "The original value: " << dayObjEight;
    cout << "Using postfix--    : " << dayObjEight--;
    cout << "After postfix--    : " << dayObjEight;
    cout << endl;

    //use postfix dayObjNine++
    cout << "Using: " << dayObjNine;
    cout << "The original value: " << dayObjNine;
    cout << "Using postfix++    : " << dayObjNine++;
    cout << "After postfix++    : " << dayObjNine;
    cout << endl;

    //test invalid data
    cout << "\nShowing bad data given to second constructor: February, 30.\n";
    DayOfYear dayObjTen("February", 30);
    cout << dayObjTen;
    cout << endl;

    cout << "\nThank you for using the DayOfYear program!!!\n";

    return 0;
}