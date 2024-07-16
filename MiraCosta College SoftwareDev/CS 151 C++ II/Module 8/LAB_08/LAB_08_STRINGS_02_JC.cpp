/*______________________________________
* FILE: LAB_08_STRINGS_02_JC.cpp
* AUTHOR: Josh Clemens
* MODULE: 8
* PROJECT: 2
* LAST MODIFIED: October 16, 22
* PROBLEM STATEMENT: Use several string functions to convert from int, string, hex, binary and decimal.
* ALGORITHM:
*    INITIALIZE an int
*    INPUT get users int input
*    CONVERT int to string and output
*    CONVERT string back to int using istringstream class and output
*    CONVERT int to binary and output
*    CONVERT back to decimal using stoi and output
*    CONVERT to hex using stringstream class and output
*    CONVERT back to decimal using stringstream class and output
*______________________________________*/

#include <sstream>
#include <istream>
#include <iostream>

using namespace std;

int main() {

    //intro
    cout << "Welcome to the String functions program!!!\n\n";

    int original = 0;
    
    do{
        
        cout << "Enter a non-negative whole number:";
        cin >> original;

        //validate input for "-1" to break out of loop and end program
        if(original < 0){
            break;
        }
    
        //convert using to_string and add rah!
        string originalAsString = to_string(original) + " rah!";
    
        //output string
        cout << "That number converted to a string:" << originalAsString << endl;
    
        //convert back to a number using istringstream class
        istringstream inpstr(originalAsString);
        int originalCopy;
        inpstr >> originalCopy;
        cout << "Converted back to an number:      " << originalCopy << endl;
    
        //convert to binary string of 0's and 1's
        char *binary = new char[33];
        *(binary + 32) = '\0';
        int index = 32;
        do{
            *(binary + (--index)) = (char)(originalCopy % 2 + '0');
            originalCopy /= 2;
        } while (originalCopy > 0);
        cout << "That number in Binary is:         " << (binary + index) << endl;
    
        //convert back to int
        originalCopy = stoi((binary + index), nullptr, 2);
        cout << "Back to decimal:                  " << originalCopy << endl;
    
        //convert to hexadecimal(base 16)
        stringstream iostr;
        iostr << hex << original;
        string temp = iostr.str();
        cout << "Here's your number in Hex:        " << temp << endl;
    
        //convert back to decimal
        iostr >> hex >> originalCopy;
        cout << "And back once more:               " << originalCopy << endl;

        cout << "\nEnter next number to test or -1 to exit program.\n" << endl;

    } while (original >= 0);

    //exit message
    cout << "\nThank you for using the String functions program!!!\n";

    return 0;
}
