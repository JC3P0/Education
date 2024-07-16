/*______________________________________
* FILE: HW_13_SIMPLE_VECTOR_MODIFICATION_JC.cpp
* AUTHOR: Josh Clemens
* MODULE: 13
* PROJECT: 2
* LAST MODIFIED: November 20, 2022
* PROBLEM STATEMENT: Modifies the SimpleVector class template to include pushBack and popBack member functions.
* ALGORITHM:
*    INITIALIZE SimpleVector class template to include pushBack and popBack member functions.
*    INITIALIZE SimpleVector int and string objects for testing
*    CALCULATE try to add an int and string to both objects using pushBack function, throw exception if object is full
*    OUTPUT objects after pushBack is called
*    CALCULATE call popBack on both objects till object is empty, throw exception if object is empty
*    OUTPUT objects after popBack is called
*______________________________________*/

#include <iostream>
#include <string>
#include "SimpleVector.h"
using namespace std;

int main() {

    const int SIZE = 5; //size of objects
    SimpleVector<int> intSV(SIZE); //int object
    SimpleVector<string> stringSV(SIZE); //string object
    int testNum = 55; //add to int vector object
    string testString = "66"; //add to string vector object

    // store values in the simpleVector objects
    for (int i = 0; i < SIZE; i++){
        intSV[i] = ((i + 2) * 2); //int object
    }
    for (int i = 0; i < SIZE; i++){
	//string object, static_cast (i value + 2) to char on each loop
        stringSV[i] = (static_cast<char>(i) + 2); 
    }

    // Int simpleVector object //
    // Display the values in int vector object
    cout << "These values are in the int simpleVector object:\n";
    intSV.print();

    //try to add item to vector / catch exception if the vector is full
    cout << "\nAdd an Int value: " << testNum << endl; //try to add item to int vector
    try{
        intSV.pushBack(testNum);
    }
    catch (SimpleVector<int>::ArrayIsFull){
        cout << "Error: Int simpleVector object is full.\n";
    }
    cout << "These are the values in the int simpleVector object after pushBack:\n";
    intSV.print();

    cout << "\nRemove all elements from array.\n";
    // test for + 1 past array size to test ArrayIsEmpty exception
    for (int i = 0 ; i < intSV.getSize() + 1; i++){
        try{
            intSV.popBack();
        }
        catch (SimpleVector<int>::ArrayIsEmpty){
            cout << "Error: Int simpleVector object is empty.\n";
        }
    }
    cout << "These are the values in int simpleVector object after popBack:\n";
    intSV.print();

    // String simpleVector object //
    // display the values in the stringSV
    cout << "\nThese values are in string simpleVector object:\n";
    stringSV.print();

    //try to add item to vector / catch exception if the vector is full
    cout << "\nAdd a string value: " << testString << endl; //add this to string vector object
    try{
        stringSV.pushBack(testString);
    }
    catch (SimpleVector<string>::ArrayIsFull){
        cout << "Error: String simpleVector object is full.\n";
    }
    cout << "These values are simpleVector object after pushBack:\n";
    stringSV.print();

    cout << "\nRemove all elements from array.\n";
    // test for + 1 past array size to test ArrayIsEmpty exception
    for (int i = 0 ; i < stringSV.getSize() + 1; i++){
        try{
            stringSV.popBack();
        }
        catch (SimpleVector<string>::ArrayIsEmpty){
            cout << "Error: String simpleVector object is empty.\n";
        }
    }
    cout << "These values are simpleVector object after popBack:\n";
    stringSV.print();

    //exit message
    cout << "\nThank you for using the SimpleVector program.\n";
    return 0;
}