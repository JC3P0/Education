/*______________________________________
* FILE: HW_05_NUMBERS_IN_ENGLISH_JC
* AUTHOR: Josh Clemens
* MODULE: 5
* PROJECT: 1
* LAST MODIFIED: September 26, 2022
* PROBLEM STATEMENT: Converts a user defined number to English.
* ALGORITHM: 
*     INITIALIZE Numbers class to accept a user entered number and convert to English
*     INITIALIZE static constant variables for converting numbers to english
*     LOOP menu options to continue entering numbers to conver to english 0 to exit program. validate for negative input.
*______________________________________*/

#include "Numbers.h"
#include <cstdlib>
#include <iostream>

using namespace std;

//used to convert numbers to english
const string Numbers::lessThan20[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
const string Numbers::tens[] = {"", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
const string Numbers::hundreds = " hundred";
const string Numbers::thousands = " thousand";

int main() {

    /***** DECLARATION & INITIALIZATION SECTION *****/

    double input = 0;

    /***** INTRO SECTION *****/

    cout << "Welcome to the Numbers in English program!\n\n";

    cout << "Enter numbers to be converted to English\nEnter 0 to exit program.\n";

    do{
        string output = "";

        /***** INPUT SECTION *****/

        // validate for negative input
        cout << "\nEnter number to convert to English: ";
        cin >> input;
        while (input < 0){
            cout << "Invalid entry." << endl;
            cout << "Enter a number greater than 0";
            cin >> input;
        }

        /***** PROCESSING / OUTPUT SECTION *****/

        //create Numbers class object to call numbersToEnglish function with users input
        Numbers numberOne(input);
        //call convert function with users input
        output = numberOne.numberToEnglish(input);

        cout << "\nThis is string return value in English.\n";
        cout << output;
        cout << endl;
    }while (input != 0);

    cout << "Thank you for using the Numbers to English program!";

    // system("PAUSE"); //for DevC++ on windows
    return EXIT_SUCCESS;
}