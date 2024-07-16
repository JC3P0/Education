/*______________________________________
* FILE: LAB_15_SET_LINKED_LIST_JC.cpp
* AUTHOR: Josh Clemens
* MODULE: 15
* PROJECT: 1
* LAST MODIFIED: December 05, 2022
* PROBLEM STATEMENT: Add functions minus, equals, and clear to the SetLinkedList.h class to increase usability.
* ALGORITHM:
*    INITIALIZE SetLinkedList class to add functions, minus, equals, and clear
*    INITIALIZE SetLinkedList string objects in main, callingSet and otherSet
*    CALCULATE insert() elements into both sets
*    OUTPUT objects
*    CALCULATE intersect() objects
*    OUTPUT objects
*    CALCULATE minus() objects
*    OUTPUT objects
*    CALCULATE the union of minus and intersect objects
*    OUTPUT objects
*    CALCULATE equals() objects
*    OUTPUT yes or no
*    CALCULATE clear both objects and insert new elements to be tested
*    REPEAT with INITIALIZING SetLinkedList int objects in main, callingSet and otherSet and run same tests as above
*______________________________________*/

#include <iostream>
#include "SetLinkedList.h"
using namespace std;

int main() {

    //intro
    cout << "Welcome to the minus operation on sets program.\n\n";

    //***case 1***
    //sets used for cases 1 and 2
    Set<string> callingSetOne;
    Set<string> otherSetOne;

    //insert to sets
    callingSetOne.insert("C");
    callingSetOne.insert("G");
    callingSetOne.insert("E");
    callingSetOne.insert("A");

    otherSetOne.insert("E");
    otherSetOne.insert("C");
    otherSetOne.insert("F");

    cout << "Test case #1\n";
    //display sets
    cout << "Set A: ";
    callingSetOne.display();
    cout << "Set B: ";
    otherSetOne.display();
    //intersect sets
    cout << "A n B: ";
    callingSetOne.setIntersect(otherSetOne).display();
    //minus() sets
    cout << "A - B: ";
    callingSetOne.minus(otherSetOne).display();
    //minus() setUnion() setIntersect()
    cout << "(A - B) U (A n B): ";
    callingSetOne.minus(otherSetOne).setUnion(callingSetOne.setIntersect(otherSetOne)).display();
    cout << "equal?: ";
    if(callingSetOne.equals(callingSetOne.minus(otherSetOne).setUnion(callingSetOne.setIntersect(otherSetOne)))) {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
    }
    //clear sets
    callingSetOne.clear();
    otherSetOne.clear();

    //***case 2***
    cout << "\nTest case #2\n";
    //insert to sets
    callingSetOne.insert("Carlos");
    callingSetOne.insert("John");
    callingSetOne.insert("Alice");

    otherSetOne.insert("John");
    otherSetOne.insert("Henry");
    otherSetOne.insert("Maria");

    //display sets
    cout << "Set A: ";
    callingSetOne.display();
    cout << "Set B: ";
    otherSetOne.display();
    //intersect sets
    cout << "A n B: ";
    callingSetOne.setIntersect(otherSetOne).display();
    //minus() sets
    cout << "A - B: ";
    callingSetOne.minus(otherSetOne).display();
    //minus() setUnion() setIntersect()
    cout << "(A - B) U (A n B): ";
    callingSetOne.minus(otherSetOne).setUnion(callingSetOne.setIntersect(otherSetOne)).display();
    cout << "equal?: ";
    if(callingSetOne.equals(callingSetOne.minus(otherSetOne).setUnion(callingSetOne.setIntersect(otherSetOne)))) {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
    }
    //clear sets
    callingSetOne.clear();
    otherSetOne.clear();

    //***case 3***
    //sets used for cases 3 and 4
    cout << "\nTest case #3\n";
    Set<int> callingSetTwo;
    Set<int> otherSetTwo;

    //insert to sets
    callingSetTwo.insert(5);
    callingSetTwo.insert(1);
    callingSetTwo.insert(3);

    otherSetTwo.insert(1);
    otherSetTwo.insert(3);
    otherSetTwo.insert(5);
    otherSetTwo.insert(7);
    otherSetTwo.insert(9);

    //display sets
    cout << "Set A: ";
    callingSetTwo.display();
    cout << "Set B: ";
    otherSetTwo.display();
    //intersect sets
    cout << "A n B: ";
    callingSetTwo.setIntersect(otherSetTwo).display();
    //minus() sets
    cout << "A - B: ";
    callingSetTwo.minus(otherSetTwo).display();
    //minus() setUnion() setIntersect()
    cout << "(A - B) U (A n B): ";
    callingSetTwo.minus(otherSetTwo).setUnion(callingSetTwo.setIntersect(otherSetTwo)).display();
    cout << "equal?: ";
    if(callingSetTwo.equals(callingSetTwo.minus(otherSetTwo).setUnion(callingSetTwo.setIntersect(otherSetTwo)))) {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
    }
    //clear sets
    callingSetTwo.clear();
    otherSetTwo.clear();

    //****case 4***
    cout << "\nTest case #4\n";
    //insert to set
    callingSetTwo.insert(5);

    //display sets
    cout << "Set A: ";
    callingSetTwo.display();
    cout << "Set B: ";
    otherSetTwo.display();
    //intersect sets
    cout << "A n B: ";
    callingSetTwo.setIntersect(otherSetTwo).display();
    //minus() sets
    cout << "A - B: ";
    callingSetTwo.minus(otherSetTwo).display();
    //minus() setUnion() setIntersect()
    cout << "(A - B) U (A n B): ";
    callingSetTwo.minus(otherSetTwo).setUnion(callingSetTwo.setIntersect(otherSetTwo)).display();
    cout << "equal?: ";
    if(callingSetTwo.equals(callingSetTwo.minus(otherSetTwo).setUnion(callingSetTwo.setIntersect(otherSetTwo)))) {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
    }

    //outro
    cout << "\nThank you for using the minus operation on sets program.\n";

    return 0;
}