/*______________________________________
* FILE: HW_13_STRING_BOUND_EXCEPTIONS_JC.cpp
* AUTHOR: Josh Clemens
* MODULE: 13
* PROJECT: 1
* LAST MODIFIED: November 20, 2022
* PROBLEM STATEMENT: Uses BCheckString class derived from STL string class to throw an exception if value is negative or greater than the length of the string or returns the location of the value passed.
* ALGORITHM:
*    INITIALIZE BCheckString class derived from STL string to create a string object and return the index of a value passed in, exception thrown if value is negative or greater than length of string.
*    INITIALIZE BCheckString object in main with a sentence
*    LOOP menu 1 continue 0 exit
*       OUTPUT BCheckString object
*       PROMPT users input to index the BCheckString object
*       CALCULATE if index is in range
*       EXCEPTION if index is out of range
*       OUTPUT the char at index location if index is in range
*       OUTPUT menu options
*       PROMPT user menu option, 1 continue, 0 exit
*    END loop 0 to exit
*______________________________________*/

#include <iostream>
#include "BCheckString.h"
using namespace std;

int main() {

    string welcomeMessage = "Welcome to the String Bound Exceptions program.";
    int index; //user inputs index
    int menu = 1; //menu loop, start true
    char holdIndex; //test the user input index

    BCheckString objOne(welcomeMessage); // BCheckString object with welcomeMessage

    while (menu){
        cout << welcomeMessage << endl;
        cout << "Enter the index of the above welcome message: ";
        cin  >> index; //get users index input

        // try to find the users index / catch if the value is out of bounds
        try {
            holdIndex = objOne[index];
            cout << "The character at index: " << index << " is: " << holdIndex << endl;
        }
        catch (BCheckString::BoundsException) {
            cout << "Index: " << index << " is out of bounds.\n";
        }
        cout << "\nEnter 1 to continue or 0 to Exit\n";
        cout << "Option: ";
        cin >> menu; //while loop condition
        cout << endl;
    }

    //exit message
    cout << "Thank you for using the String Bound Exceptions program.\n";
    return 0;
}