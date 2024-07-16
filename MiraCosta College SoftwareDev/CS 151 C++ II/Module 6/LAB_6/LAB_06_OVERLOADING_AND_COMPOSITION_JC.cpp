/*______________________________________
* FILE: LAB_06_OVERLOADING_AND_COMPOSITION_JC.cpp
* AUTHOR: Josh Clemens
* MODULE: 6
* PROJECT: 1
* LAST MODIFIED: October 01, 2022
* PROBLEM STATEMENT: Modify the previous string class to Estring to demonstrate overloading operators
* ALGORITHM:
*    INITIALIZE Estring class with overloaded operators ++, + , =, [], << for calculating and output
*    INITIALIZE Estring objects for testing
*    OUTPUT results after prefix and postfix ++ operators
*    OUTPUT results after [] and + operators
*______________________________________*/

#include "Estring.h"
#include <cstdlib>
#include <iostream>

using namespace std;

int main() {

    //create Estring class objects
    cout << "Create two strings, one using constructor and an assignment statement.\n";
    Estring EstringOne = "Hello MiraCosta!"; //regular constructor
    Estring EstringTwo;

    //uses overloaded assignment operator
    EstringTwo = EstringOne;

    //display both objects
    cout << "First string: " << EstringOne << endl << "Second String: " << EstringTwo << endl;

    //create objects to test prefix and postfix ++
    Estring EstringThree = "HelLo and Welcome to MiraCosta123!@@!";
    Estring EstringFour = "HelLo and Welcome to MiraCosta123!@@!";

    //testing prefix ++
    cout << "\nOriginal string:" << EstringThree << endl;
    cout << "Using prefix operator:" << ++EstringThree << endl;
    cout << "After using prefix:" << EstringThree << endl;

    //testing postfix++
    cout << "\nOriginal string:" << EstringFour << endl;
    cout << "Using postfix operator:" << EstringFour++ << endl;
    cout << "After using postfix:" << EstringFour << endl;
    cout << endl;

    //testing []
    cout << "Original: ";
    for (int i = 0; i < EstringOne.getSize(); i++){
        cout << EstringOne[i] << " ";
    }
    cout << endl;

    cout << "Updated: ";
    for (int i = 0; i < EstringOne.getSize(); i++){
        cout << ++EstringOne[i] << " ";
    }
    cout << endl;
    cout << endl;

    //testing overloaded + operator
    cout << "testing overloaded + operator: ";
    Estring EstringFive;
    EstringFive = EstringOne + EstringFour;
    cout << EstringFive << endl;

    return 0;
}
