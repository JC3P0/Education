/*______________________________________
* FILE: HW_08_PASSWORD_VERIFIER_JC.cpp
* AUTHOR: Josh Clemens
* MODULE: 8
* PROJECT: 2
* LAST MODIFIED: October 16, 22
* PROBLEM STATEMENT: Use a password verifier function to test users input for password verification.
*                    Passwords must include at least 6 characters, contain at least one lower and
*                    one upper case character, contain at least one digit, and cannot contain a blank space.
* ALGORITHM:
*    INITIALIZE password verifier function and test for the following: contains 6+ characters,
*               contains at least one lower and one upper case character,
*               contains at least one digit, and cannot contain a blank space.
*    LOOP do while condition 'q' to exit program
*       INPUT get users input password to be verified
*       VALIDATE input with 'q' to quit the program
*       CALCULATE users input is a valid password or not
*       OUTPUT if password entered is valid, if not output why the password was incorrect
*______________________________________*/

#include <cstring>
#include <string>
#include <iostream>

using namespace std;

bool passwordVerifier(char*, int);

int main() {

    //intro
    cout << "Welcome to the Password Verifier program!!!\n\n";

    //used for user input
    char input[100];

    do{
        cout << "(Enter 'q' to exit) \nEnter a Password to verify: ";
        cin.get(input, 100);
        cin.clear();
        cin.ignore();

        //validate input for 'q' to break out of loop and end program
        if(input[0] == 'q'){
            break;
        }

        //call passwordVerifier function to test input
        if (passwordVerifier(input, strlen(input))){
            cout << endl;
            cout << input << ": is a valid Password!!!\n\n";
        } else {
            cout << endl;
            cout << input << ": is not a valid Password...\nPlease try again...\n\n";
        }
    } while (input[0] != 'q');

    //exit message
    cout << "\nThank you for using the Password Verifier program!!!\n";

    return 0;
}

bool passwordVerifier(char* password, int length){

    //used to validate upper and lower case characters
    int lower = 0;
    int upper = 0;
    int space = 0;

    //validate at least 6 characters long
    if (length < 6){
        cout << "Password must be 6+ characters\n";
        // return false;
    }
    //validate contain at least 1 character
    if (length -1 < 1){
        cout << "Password must contain at least 1 character\n";
        // return false;
    }

    //check for lower, upper case and space characters
    for (int i = 0; i < length; i++){
        if (isupper(password[i])){
            upper++;
        }
        if (islower(password[i])){
            lower++;
        }
        if (password[i] == ' '){
            space++;
            cout << "Password cannot contain a space...\n";
        }

    }

    //check if password contains an upper and lowercase character
    if (upper < 1 || lower < 1){
        // cout << "Testing lower: " << lower << " Testing upper: " << upper << endl; //testing line
        cout << "Password must contain at least one upper and one lower case character...\n";
        // return false;
    }

    //only return true if all validation conditions are met
    if(length > 5 && upper > 0 && lower > 0 && space == 0){
        return true;
    }

    return false;
}