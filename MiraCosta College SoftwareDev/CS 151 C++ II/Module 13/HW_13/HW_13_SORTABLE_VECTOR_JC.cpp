/*______________________________________
* FILE: HW_13_SORTABLE_VECTOR_JC.cpp
* AUTHOR: Josh Clemens
* MODULE: 13
* PROJECT: 3
* LAST MODIFIED: November 20, 2022
* PROBLEM STATEMENT: Uses SortableVector class derived from SimpleVector class to sort objects and throw an exception if [] operator is called using negative or greater than size.
* ALGORITHM:
*    INITIALIZE SortableVector class template to sort objects and throw exception for negative or greater than size to [] operator
*    INITIALIZE double and string SortableVector objects with arrays
*    OUTPUT both objects
*    CALCULATE sort both objects
*    OUTPUT both objects
*    CALCULATE test negative and larger than size values to the [] operator and throw exception
*    OUTPUT the caught exception
*______________________________________*/

#include <iostream>
#include "SortableVector.h"
using namespace std;
int main() {

    //size of objects
    const int SIZE = 10;
    //double and string objects
    SortableVector<double> doubleObject(SIZE);
    SortableVector<string> stringObject(SIZE);
    //used to initialize objects
    double doubleArray[SIZE] = {55, 89, 24, 34, 66, 78, 11, 56, 42, 52};
    string stringArray[SIZE] = {"Josh", "Savannah", "Garret", "Bailey", "Susan", "Jose", "Bert", "Jeff", "Joan", "Mallory"};
    // initialize values in the objects
    for (int i = 0; i < SIZE; i++){
        doubleObject[i] = doubleArray[i];
        stringObject[i] = stringArray[i];
    }

    //display the objects
    cout << "Here is the data in both arrays: \n";
    cout << "Double array: ";
    doubleObject.print();
    cout << "String array: ";
    stringObject.print();

    //sort the objects
    doubleObject.sort();
    stringObject.sort();

    //display the objects
    cout << "\nHere is the data in both arrays AFTER sorting: \n";
    cout << "Double array: ";
    doubleObject.print();
    cout << "String array: ";
    stringObject.print();

    cout << "\nNow call negative value to the [] operator on the double object.\n";
    //try overload the [] operator with negative or grater than size of object / catch exception
    try{
        cout << doubleObject[-5];
    }
    catch (SortableVector<double>::ArrayIndex){
        cout << "Error: number is negative, index is out of bounds...\n";
    }
    cout << "\nNow call a larger value to the [] operator on the String object.\n";
    //try overload the [] operator with negative or grater than size of object / catch exception
    try{
        cout << stringObject[72];
    }
    catch (SortableVector<string>::ArrayIndex){
        cout << "Error: number is greater than size, index is out of bounds...\n";
    }

    //exit message
    cout << "\nThank you for using the Sortable Vector program.\n";
    return 0;
}