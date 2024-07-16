/*______________________________________
* FILE: HW_07_ENCRYPTABLE_STRING_JC.cpp
* AUTHOR: Josh Clemens
* MODULE: 7
* PROJECT: 2
* LAST MODIFIED: October 09, 2022
* PROBLEM STATEMENT: Extend the string class with public access to EncryptableString class to add one value to the ASCII char value from users input to encrypt the string. ignores spaces and punctuation.
* ALGORITHM:
*    INITIALIZE EncryptableString class with public access to string class and to accept string object through constructor.
*    LOOP menu with input, enter 0 to exit program.
*    INPUT get users input for encrypting.
*    INITIALIZE EncryptableString object with users input.
*    CALCULATE encrypt() to add one value to the ASCII char value skipping spaces and punctuation. z = a and 9 = 0 after encryption
*    OUTPUT results.
*______________________________________*/

#include <iostream>
#include "EncryptableString.h"

using namespace std;

int main() {

    //intro
    cout << "Welcome to the Encrypt-able String program!!!\n\n";

    //decl. and init.
    string input = " ";

    //input, processing and output
    do{
       
        cout << "(Enter 0 to exit) \nEnter a string to encrypt: ";
        getline(cin, input);

        //validate input for 0 to break out of loop and end program
        if(input == "0"){
            break;
        }

        //create object to encrypt string
        EncryptableString test(input);
       
        cout << endl;
        cout << "Original : " << input;
        cout << endl;
        cout << "Encrypted: ";
        test.encrypt(input); //encrypt the string
        cout << endl << endl;
        
    } while (input != "0");

    //exit message
    cout << "\n\nThank you for using the Encrypt-able String program!!!\n";

    return 0;
}