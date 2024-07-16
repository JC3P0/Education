/*______________________________________
* FILE: LAB_13_ARITHMETIC_EXCEPTION_JC.cpp
* AUTHOR: Josh Clemens
* MODULE: 13
* PROJECT: Lab 1
* LAST MODIFIED: November 20, 2022
* PROBLEM STATEMENT: Uses squareRoot function to throw an exception if the int passed does not have a sqrt
* ALGORITHM:
*    INITIALIZE squareRoot function to throw an exception if the number passed is <= 0 or does not have a sqrt
*    LOOP through 0-25 calling squareRoot function each loop
*       CALCULATE if the current number being called has a sqrt 
*       EXCEPTION thrown in squareRoot function and caught in main for each number that does not have sqrt
*       OUTPUT numbers that have a sqrt
*    END of loop
*______________________________________*/

#include <iostream>
#include <cmath> //used for sqrt()
#include <string>
using namespace std;

// function prototype
int squareRoot(int);

int main(){

    for (int i = 0; i < 26; i++) { // loop through 0-25
        try {
            squareRoot(i);
            cout << "The square root of " << i << " is " << squareRoot(i) << endl;
        }
        catch (string exceptionString) {
            cout << i << exceptionString;
        }
    }

    //exit message
    cout << "Thank you for using the Arithmetic Exception program.\n";
    return 0;
}

int squareRoot(int num) {
    //if num is 0 or negative or does not have sqrt, throw exception
    if (num <= 0 || sqrt(num) != static_cast<int>(sqrt(num))) {
        throw string(" does not have a square root!\n");
    }
    return sqrt(num);
}