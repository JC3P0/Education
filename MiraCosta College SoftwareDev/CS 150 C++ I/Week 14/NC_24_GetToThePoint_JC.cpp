/*____________________
* AUTHOR: Josh Clemens
* COURSE: CS 150: C++ Programming 1
* NC (PROJECT)#: NC_24
* LAST MODIFIED: April 27, 2022
*______________
* GetToThePoint
*_____________________
* PROGRAM DESCRIPTION:
* Object oriented program using a Point and Line classes with fuctions and friend functions to output, calculate point and line distances.
*___________
* ALGORITHM:
* INITIATE Line and Point objects
* INITIATE a Line with two Points
* OUTPUT Line and Point objects
* CALCULATE if objects are equal and display
* CALCULATE distance of Point objects
* CALCULATE length of Line object
* CALCULATE if objects are equal and display
*___________________________________________
* ALL IMPORTED LIBRARIES NEEDED AND PURPOSE:
* <cstdlib> Provides standard functions, including dynamic memory management,
* random number generation, communication with the environment,
* integer arithmetics, searching, sorting and converting.
* <iostream> Used for console input and output (cin and cout).
* <cmath> sprt and pow calculations
*____________________________________________*/

#include <cstdlib>
#include <iostream>
#include <cmath>
#include "Line.h"
#include "Point.h"

using namespace std;

int main(int argc, char* argv[]) {

    /***** CONSTANT SECTION *****/
    //no const.
 
    /***** DECLARATION SECTION *****/
    //no dec.
    
    /***** INITIALIZATION SECTION *****/

    Line l1(1,1,4,4);
    Point p1;
    Point p2(0,4); 
    Line l2(p1, p2);

    /***** INTRO SECTION *****/

    cout << "Welcome to the GetToThePoint program.\n\n";

    /***** INPUT SECTION *****/
    //no input
    
    /***** PROCESSING SECTION *****/ /***** OUTPUT SECTION *****/

    cout << p1;
    cout << p2;
    cout << l1;
    cout << l2;
    if (l1 == l2) {
        cout << "objects are equal" << endl;
    } else {
        cout << "(Expected) Line objects are NOT equal" << endl;
    }
    if (p1 == p2) {
        cout << "objects are equal" << endl;
    } else {
        cout << "(Expected) Point objects are NOT equal" << endl;
    }
    
    cout << "The distance of p1 to p2 = " << p1.distanceTo(p2) << endl;
    cout << "The length of Line2 = " << l2.getLength() << endl;
    l1 = l2;    
    if (l1 == l2) {
        cout << "(Expected) Line objects are equal" << endl;
    } else {
        cout << "objects are NOT equal" << endl;
    }
    if (p1 == p2) {
        cout << "objects are equal" << endl;
    } else {
        cout << "(Expected) Point objects are NOT equal" << endl;
    }
    
    // system("PAUSE"); //for DevC++ on windows
    return EXIT_SUCCESS;
}