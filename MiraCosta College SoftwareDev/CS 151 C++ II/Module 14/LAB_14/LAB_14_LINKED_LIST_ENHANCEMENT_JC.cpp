/*______________________________________
* FILE: LAB_14_LINKED_LIST_ENHANCEMENT_JC.cpp
* AUTHOR: Josh Clemens
* MODULE: 14
* PROJECT: 1
* LAST MODIFIED: November 27, 2022
* PROBLEM STATEMENT: Add functions to the LinkedList.h class to increase usability of the linked list.
* ALGORITHM:
*    INITIALIZE LinkedList class to add functions, contains, lastIndexOf, remove, removeAt, set, and display
*    INITIALIZE LinkedList object in main
*    OUTPUT empty object
*    CALCULATE add values to object
*    OUTPUT object with values
*    CALCULATE use remove() function to remove a value from list, return 1 if successful and 0 if not
*    OUTPUT object after remove()
*    CALCULATE use removeAt() function to remove a value by index from list, return element to be removed is successful or throw runtime error if not
*    OUTPUT object after removeAt()
*    CALCULATE use lastIndexOf() function to a specific data element, return -1 if not successful
*    OUTPUT object after lastIndexOf()
*    CALCULATE use contains() function to find specific data element, return true if found and false if not
*    OUTPUT object after contains()
*    CALCULATE use set() function to replace data element with given index and value, return element to be removed or T() if unsuccessful
*    OUTPUT object after set()
*______________________________________*/

#include <iostream>
#include "LinkedList.h"
using namespace std;

int main() {

    LinkedList<double> list;

    cout << "Print empty list:\n";
    list.display();

    cout << "Adding to the list...\n";
    //add to the list
    list.add(0, 2.5);
    list.add(1, 7.9);
    list.add(2, 12.6);
    list.add(3, 5.3);
    list.add(4, 3.2);
    list.add(5, 13.3);
    list.add(6, 6.5);
    list.add(7, 1.8);
    cout << "This is the list after adding values:\n";
    list.display(); //display list
    cout << endl;
    
    //test remove, one false, one true
    cout << "Removing from list with remove()\n";
    cout << "Remove (55.9)? : " << list.remove(55.9) << endl;
    cout << "This is the list after remove 55.9:\n";
    list.display();
    cout << endl;
    cout << "Remove (7.9)? : " << list.remove(7.9) << endl;
    cout << "This is the list after remove 7.9:\n";
    list.display();
    cout << endl;

    //test removeAt
    cout << "Removing from list with removeAt()\n";
    try{
        cout << "RemoveAt (12)? : " << list.removeAt(12) << endl;
        if (list.removeAt(12)){
            throw runtime_error("Invalid location!!!");
        }
        cout << "This is the list after removeAt 12:\n";
        list.display();
        cout << endl;
    } catch (exception e){
        cout << "Error: Invalid location!!!" << endl;
    }
    cout << "This is the list after removeAt (12):\n";
    list.display();
    cout << endl;
    cout << "RemoveAt (5)? : " << list.removeAt(5) << " is the item to be removed." << endl;
    cout << "This is the list after removeAt (5):\n";
    list.display();
    cout << endl;

    //testing listIndexOf()
    cout << "Using lastIndexOf() return -1 if element if not found.\n";
    cout << "Find last index of (67.8) : " << list.lastIndexOf(67.8) << endl;
    cout << "Find last index of (13.3) : " << list.lastIndexOf(13.3) << endl;
    cout << endl;

    //testing contains()
    cout << "Using contains() returns true if found and false if not found.\n";
    cout << "Does list contain (76)? : ";
    if (list.contains(76)){
        cout << "true";
    }
    else {
        cout << "false";
    }
    cout << endl;

    cout << "Does list contain (5.3)? : ";
    if (list.contains(5.3)){
        cout << "true";
    }
    else {
        cout << "false";
    }
    cout << endl;
    cout << endl;

    //test set()
    cout << "Using set() to replace an item, return the replaced item if replaced or T() if unsuccessful.\n";
    try{
        cout << "Item to be replaced with set(12, 72) : " << list.set(12, 72) << endl;
        cout << "This is the list after set(12, 72):\n";
        list.display();
    }
    catch (exception e){
        cout << "T()\n";
    }
    cout << endl;
    cout << "Here is the current list: \n";
    list.display();
    cout << "Item to be replaced with set(2, 55.7) : " << list.set(2, 55.7) << endl;
    cout << "This is the list after set(2, 55.7):\n";
    list.display();
    return 0;
}