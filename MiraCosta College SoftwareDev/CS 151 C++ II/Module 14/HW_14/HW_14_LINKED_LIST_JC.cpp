/*______________________________________
* FILE: HW_14_LINKED_LIST_JC.cpp
* AUTHOR: Josh Clemens
* MODULE: 14
* PROJECT: 1, 2, 3, 4, 5
* LAST MODIFIED: November 27, 2022
* PROBLEM STATEMENT: Uses LinkedList class to add functions, print, reverse, search, and insert
* ALGORITHM:
*    INITIALIZE LinkedList class to add functions, print, reverse, search, and insert
*    INITIALIZE LinkedList object in main
*    CALCULATE add values to object
*    OUTPUT object with values
*    CALCULATE use isMember() function to find values, return true is found and false if not
*    OUTPUT object after isMember()
*    CALCULATE use reverse() function to reverse the list
*    OUTPUT object after reverse()
*    CALCULATE use search() function to find index of value, return index or -1 if not found
*    CALCULATE use insert() function to add values to list
*    OUTPUT object after insert()
*______________________________________*/

#include <iostream>
#include "LinkedList.h"
using namespace std;

int main() {

    LinkedList list; //create class object

    //add values
    cout << "Adding values to list.\n";
    list.add(7.0);
    list.add(8.0);
    list.add(9.0);
    cout << "Here is the list after adding values.\n";
    list.print();
    cout << endl;

    //test isMember()
    cout << "Testing isMember(9.0)\n";
    if(list.isMember(9.0)){
        cout << "(9.0) is a member!\n";
    }
    else {
        cout << "Error: item not found\n";
    }
    cout << "Testing isMember(7.0)\n";
    if(list.isMember(7.0)){
        cout << "(7.0) is a member!\n";
    }
    else {
        cout << "Error: item not found\n";
    }
    cout << "Testing isMember(5.0)\n";
    if(list.isMember(5.0)){
        cout << "(5.0) is a member!\n";
    }
    else {
        cout << "Error: item not found\n";
    }
    cout << endl;

    //test print()
    cout << "Printing list: ";
    list.print();
    cout << endl;

    //test reverse()
    list.reverse();
    cout << "Reverse the list: ";
    list.print();
    cout << endl;

    //test search()
    cout << "Using search() to find index, return -1 if not found: \n";
    cout << "(7.0) is at index : " << list.search(7.0) << endl;
    cout << "(9.0) is at index : " << list.search(9.0) << endl;
    cout << "(10.0) is at index : " << list.search(10.0) << endl;
    cout << endl;

    //test insert()
    cout << "Lets insert some values using insert().\n";
    cout << "list.insert(10.0, 0) : ";
    list.insert(10.0, 0);
    list.print();
    cout << "list.insert(12.0, 2) : ";
    list.insert(12.0, 2);
    list.print();
    cout << "list.insert(15.0, 9) : ";
    list.insert(15.0, 9);
    list.print();

    return 0;
}