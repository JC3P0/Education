/*______________________________________
* FILE: LAB_11_RECURSION_CONVERTER_JC.cpp
* AUTHOR: Josh Clemens
* MODULE: 11
* PROJECT: Lab 1 & 2
* LAST MODIFIED: November 06, 2022
* PROBLEM STATEMENT: Use iterative and recursive functions to convert to and from binary / decimal.
* ALGORITHM:
*    INITIALIZE iterative and recursive convert functions
*    LOOP menu option 1 to continue and 3 to exit
*        SWITCH input
*        Case 1: Convert a decimal to binary with both iterative and recursive functions and output
*        Case 2: Convert a binary to decimal with both iterative and recursive functions and output
*    END menu option 3
*______________________________________*/

#include <iostream>
#include <string>
using namespace std;

string decimalConvert(int input); //iterative function to binary
int binaryToDecimal(string input); //iterative function to decimal
string strTo(int n); //recursive function to binary
int binaryConvert(string input); //recursive function to decimal

int main(int argc, char* argv[]) {
   
    int input = 0;
    string binary = "";
    int menuOption = 0;
    int binaryOutput = 0;
    string output = "";

    do{ 
        cout << "Enter a method of conversion \n1)Decimal to Binary \n2)Binary to Decimal \nChoice: ";
        cin >> menuOption;
        switch(menuOption){//switch menu option
            case 1:
                cout << "\nEnter Decimal number to convert to Binary: ";
                cin >> input;
                while (input < 0){   
                    cout << "Invalid entry." << endl;
                    cout << "Enter a number greater than 0";
                    cin >> input;
                }
        
                //call convert iterative function with users input
                output = decimalConvert(input);
                cout << "\nThis is string return value in binary using iterative function: " << output;
                //call convert recusive function with users input
                output = strTo(input);
                cout << "\nThis is string return value in binary using recursive function: " << output;

                break;
            case 2:

                cout << "\nEnter Binary number to convert to Decimal: ";
                cin >> binary;

                //call convert iterative function with users input
                binaryOutput = binaryToDecimal(binary);
                cout << "\nThis is string return value in binary using iterative function: " << binaryOutput;
                //call convert iterative function with users input
                binaryOutput = binaryConvert(binary);
                cout << "\nThis is string return value in binary using recursive function: " << binaryOutput;

                break;
        }
        
        //do while condition to continue or exit program
        cout << "\n\nEnter 1 to continue and 3 to close the program: ";
        cin >> menuOption;
        cout << endl;
    }while (menuOption != 3);

    cout << "Thank you for using the Decimal / Binary converter.";
    return 0;
}

/***** Function Definitions *****/

string decimalConvert(int input) {

    int counter = 0; //calculates length of string
    string tempString = ""; //holds the binary number
    //handles 0 input
    if (input == 0){
        tempString = "0";
    }
    //loop to convert decimal to binary while adding to tempString
    for(int i = 0; input > 0; i++){  
        tempString = to_string(input % 2) + tempString;
        counter++; //calculates length of string
        input = input / 2;  
    }   
    return tempString;
} 

string strTo(int n) {
    int base = 2; //binary is base 2
    string convertStr = "01";
    if(n < base){//base case
        return string(1, convertStr[n]);
    } else {
        return strTo(n / base) + convertStr[n % base]; //calls as recursion function
    }
}

int binaryToDecimal(string input){
    // int binary = stoi(input, nullptr, 2);
    int binary = stoi(input); //convert string to int
    int decimal = 0; //decimal to return
    int remainder = 0; 
    int product = 1; //start with 1 for first remainder * product
    while(binary != 0){
        remainder = binary % 10;
        decimal = decimal + (remainder * product);
        binary = binary / 10;
        product *= 2;
    }
    return decimal;
}

int binaryConvert(string input){
    int binary = stoi(input); //convert string to int
    if (binary == 0){//base case
        return 0;
    } else {
        return ((binary % 10) + (2 * binaryConvert(to_string(binary / 10)))); //call as recursion function while changing int to string
    }
}