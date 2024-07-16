/*______________________________________
* FILE: HW_07_PALINDROMES_JC.cpp
* AUTHOR: Josh Clemens
* MODULE: 7
* PROJECT: 1
* LAST MODIFIED: October 09, 2022
* PROBLEM STATEMENT: Use the string class to derive a PString class to accept a string object and check if Palidrome or not.
* ALGORITHM:
*    INITIALIZE PString class with public access to string class and to accept string object through constructor.
*    LOOP menu with input, enter 0 to exit program.
*    INPUT get users input for testing.
*    INITIALIZE PString object with users input.
*    CALCULATE if palindrome or not.
*    OUTPUT results.
*______________________________________*/

#include <iostream>
#include "PString.h"
using namespace std;

int main() {

    //intro
    cout << "Welcome to the Palindrome program!!!\n\n";

    //decl. and init.
    string input = " ";

    //input, processing and output
    do{
       
        cout << "(Enter 0 to exit) \nEnter a Palindrome to test: ";
        getline(cin, input);

        //validate input for 0 to break out of loop and end program
        if(input == "0"){
            break;
        }

        //create object to test isPalindrome
        PString test(input);
       
        cout << endl;

        //if true, output is Palindrome, else is not
        if (test.isPalindrome(input)){
            cout << test << ": is a Palindrome!!!\n\n";
        } else {
            cout << test << ": is not a Palindrome...\n\n";
        }

    } while (input != "0");

    //exit message
    cout << "\nThank you for using the Palindrome program!!!\n";

    return 0;
}