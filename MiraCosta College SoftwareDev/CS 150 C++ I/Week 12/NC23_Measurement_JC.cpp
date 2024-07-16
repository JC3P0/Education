/*____________________
* AUTHOR: Josh Clemens
* COURSE: CS 150: C++ Programming 1
* NC (PROJECT)#: NC_23
* LAST MODIFIED: April 21, 2022
*____________
* Measurement
*_____________________
* PROGRAM DESCRIPTION:
* Object oriented program using a measurment class with fuctions and friend functions to display and change measurments.
*___________
* ALGORITHM:
* INITIATE objects
* CALCULATE if objects are equal and display
* CALCULATE increment one object and decrement the other, check if equal and display
* INTIATE another object by adding a prevous object from another and display
* INTIATE another object by subtracting a prevous object from another and display
*___________________________________________
* ALL IMPORTED LIBRARIES NEEDED AND PURPOSE:
* <cstdlib> Provides standard functions, including dynamic memory management,
* random number generation, communication with the environment,
* integer arithmetics, searching, sorting and converting.
* <iostream> Used for console input and output (cin and cout).
*____________________________________________*/

#include <cstdlib>
#include <iostream>
#include "Measurement.h"

using namespace std;

int main(int argc, char* argv[]) {

    /***** CONSTANT SECTION *****/
    //no const.
 
    /***** DECLARATION SECTION *****/ 
    //no dec.
    
    /***** INITIALIZATION SECTION *****/

    Measurement m1(5, 18);

    /***** INTRO SECTION *****/

    cout << "Welcome to the measurement program.\n";
    
    /***** INPUT SECTION *****/
    //no input
    
    /***** PROCESSING SECTION *****/ /***** OUTPUT SECTION *****/

    cout << m1;
    cout << endl;
    Measurement m2 = m1;
    cout << m2;
    cout << endl;
    if (m1 == m2) {
        cout << "(Expected)objects are equal" << endl;
    } else {
        cout << "objects are NOT equal" << endl;
    }
    m1++;
    m2--;
    cout << m1;
    cout << endl;
    cout << m2;
    cout << endl;
    if (m1 == m2) {
        cout << "objects are equal" << endl;
    } else {
        cout << "(Expected) objects are NOT equal" << endl;
    }
    Measurement m3 = m1 + m2;
    m3++;//to display correct inches
    m3--;//to display correct inches
    cout << m3;
    cout << endl;
    Measurement m4 = m1 - m2;
    cout << m4;
    cout << endl;

    // system("PAUSE"); //for DevC++ on windows
    return EXIT_SUCCESS;
}




