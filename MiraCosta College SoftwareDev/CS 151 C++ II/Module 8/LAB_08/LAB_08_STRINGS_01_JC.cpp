/*______________________________________
* FILE: LAB_08_STRINGS_01_JC.cpp
* AUTHOR: Josh Clemens
* MODULE: 8
* PROJECT: 1
* LAST MODIFIED: October 16, 22
* PROBLEM STATEMENT: Create on encrypt function to add 1 to the ASCII value of numbers and letters of a given input.
* ALGORITHM:
*    INITIALIZE encrypt function to only change numbers and letters to the next ASCII value (character++)
*    VALIDATE characters z or Z and 9 to be changed to a or Z and 0
*    LOOP condition enter "quit" to exit program
*      INPUT get users input to be encrypted
*      VALIDATE user input to all lower case to test for "quit"
*      CALCULATE encrypt users input
*      OUTPUT users input
*______________________________________*/

#include <algorithm>
#include <iostream>

using namespace std;

void encrypt(char &character);

int main() {

    //intro
    cout << "Welcome to the Encrypt a String using Lambda functions program!!!\n\n";
    //used for user input
    string input = " ";
    //used to test user input
    string test = " ";

    do{

        cout << "(Enter Quit to exit) \nEnter a string to encrypt: ";
        getline(cin, input);

        //convert to lowercase to test QUIT
        test = input;
        for_each(test.begin(), test.end(),
                 [](char &c) {c = tolower(c);});

        //validate input for "quit" to break out of loop and end program
        if(test == "quit"){
            break;
        }

        cout << endl;
        cout << "Original : " << input;
        cout << endl;
        cout << "Encrypted: ";
        //encrypt each character
        for_each(input.begin(), input.end(),
                 [](char &c) {encrypt(c);});

        cout << input;
        cout << endl << endl;
    } while (test != "quit");

    //exit message
    cout << "\n\nThank you for using the Encrypt a String using Lambda functions program!!!\n";

    return 0;
}

//functions
void encrypt(char &character) {
    //condition to be ++ if character is 9 or z
    int flag = 0;
    //validate characters is number or letter
    if (isalnum(character)) {
        //check for lower and uppercase char a - y and numbers 0 - 8 then add 1.
        //z and 9 will convert to a and 0 at last if, if else
        if ((character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z')) {
            //if character is z or Z, -- to keep z or Z then use flag++ to handle in next if, if else
            if (character == 'z' || character == 'Z') {
                flag++;
                character--;
            }
            character++;
        } else if (character >= '0' && character <= '9') {
            //if character is 9, -- to keep it 9 and use flag++ to handle in next if, if else
            if (character == '9') {
                flag++;
                character--;
            }
            character++;
        }

        //only change z or 9 if flag condition was ++ (more than 0)
        if (character == 'z') {
            if (flag) {
                character = 'a';
            }
        } else if (character == 'Z') {
            if (flag) {
                character = 'A';
            }
        } else if (character == '9') {
            if (flag) {
                character = '0';
            }
        }
    }
}