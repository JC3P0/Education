/*______________________________________
* FILE: HM2_P1_Decimal_to_Binary_Converter.cpp
* AUTHOR: Josh Clemens
* MODULE: 2
* PROJECT: Homework 2
* LAST MODIFIED: September 01, 2022
* PROBLEM STATEMENT: This program converts decimals to binary.
* ALGORITHM:
*     LOOP do while loop to start/ continue entering decimals or exit program.
*     PROMPT user to enter decimal number.
*     VALIDATE input to not be less than 0, return to PROMPT if invalid entry.
*     CALCULATE call convert function to convert decimal number 
                to binary by looping input % 2 (store this to temp string) 
                then input / 2 and repeat until input is 0. Loop the temp string in reverse for output return.
*     OUTPUT converted number in binary.
*     PROMPT user for menuOption to continue looping and converting numbers or 2 to exit program.
*______________________________________*/


#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

string decimalConvert(int input);

int main(int argc, char* argv[]) {

    /***** DECLARATION & INITIALIZATION SECTION *****/
    
    int input = 0;
    int menuOption = 0;
    string output = "";

    //do while condition user input 2
    do{
        
        cout << "Enter number to convert to decimal: ";
        cin >> input;
        while (input < 0){   
            cout << "Invalid entry." << endl;
            cout << "Enter a number greater than 0";
            cin >> input;
        }

        //call convert function with users input
        output = decimalConvert(input);
        
        cout << "\nThis is string return value in binary.\n";
        cout << output;
        //do while condition to continue or exit program
        cout << "\n\nEnter 1 to continue and 2 to close the program: ";
        cin >> menuOption;
        cout << endl;
    }while (menuOption != 2);

    cout << "Thank you for using the Decimal converter.";

    // system("PAUSE"); //for DevC++ on windows
    return EXIT_SUCCESS;
}

/***** Function Definitions *****/

string decimalConvert(int input) {

    int counter = 0; //calculates length of string
    string tempString = ""; //holds the binary number in reverse during loop calculation
    string returnString = ""; //returns the binary number in correct order

    //handles 0 input
    if (input == 0){
        returnString = "0";
    }

    //loop to convert decimal to binary while adding to tempString
    for(int i = 0; input > 0; i++){  
        
        tempString += to_string(input % 2);
        counter++; //calculates length of string
        // cout << "\ntest tempString " << tempString; //testing line
        input = input / 2;  

    }   

    //reverse the string
    for(int i = counter - 1; i >= 0; i--){
        // cout << tempString[i]; //testing line
        returnString += tempString[i];
    }
    // cout << "\ntest returnString " << returnString; //testing line
    return returnString;
} 