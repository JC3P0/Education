/*______________________________________
* FILE: LAB_06_TIME&DATE_COMPOSITION_JC.cpp
* AUTHOR: Josh Clemens
* MODULE: 6
* PROJECT: 2
* LAST MODIFIED: October 01, 2022
* PROBLEM STATEMENT: Demonstrates composition from TimeDate that is "owned" by an Event class.
* ALGORITHM:
*    INITIALIZE two classes, Event and TimeDate
*    INITIALIZE Event to use TimeDate objects to demonstrate composition
*    INITIALIZE Event objects 
*    OUTPUT event objects
*______________________________________*/

#include "TimeDate.h"
#include "Event.h"
#include <iostream>

using namespace std;

int main() {

    //create first event and output
    Event party(17, 30, 14, "Oct.", 20, 30,
                14, "Oct.", "My Birthday Party");

    cout << party.getEvent() << endl;

    //create second event and output
    Event partyOne(16, 25, 28, "Apr.", 19, 45,
                   28, "Apr.", "My B-Day");

    cout << partyOne.getEvent() << endl;

    return 0;
}