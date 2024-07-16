/*____________________
* AUTHOR: Josh Clemens
* COURSE: CS 150: C++ Programming 1
* NC (PROJECT)#: NC_22
* LAST MODIFIED: April 21, 2022
*_____
* Time
*_____________________
* PROGRAM DESCRIPTION:
* Object oriented program using a time class with fuctions and friend functions to display and change time.
*___________
* ALGORITHM:
* INITIATE time objects
* OUTPUT time objects
* CALCULATE if objects are equal and display
* CALCULATE increment one object
* CALCULATE if objects are equal and display
*___________________________________________
* ALL IMPORTED LIBRARIES NEEDED AND PURPOSE:
* <cstdlib> Provides standard functions, including dynamic memory management,
* random number generation, communication with the environment,
* integer arithmetics, searching, sorting and converting.
* <iostream> Used for console input and output (cin and cout).
* <iomanip> setprecision(2)
*____________________________________________*/

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "Time.h"

using namespace std;


int main(int argc, char* argv[]) {

    /***** CONSTANT SECTION *****/
    //no const.
 
    /***** DECLARATION SECTION *****/
    //no dec.
    
    /***** INITIALIZATION SECTION *****/

    Time t1(11, 59, PM);//parameterized constructor
    Time t2;//default constructor

    /***** INTRO SECTION *****/

    cout << "Welcome to the time Program.\n";
    
    /***** INPUT SECTION *****/
    //no input
    
    /***** PROCESSING SECTION *****/ /***** OUTPUT SECTION *****/

    cout << t1 << endl;
    cout << t2 << endl;
    if (t1 == t2) {
        cout << "Times objects are equal" << endl;
    } else {
        cout << "(Expected)Times objects are NOT equal" << endl;
    }
    t1++;
    cout << t1 << endl;
    cout << t2 << endl;
    if (t1 == t2) {
        cout << "(Expected)Times objects are equal" << endl;
    } else {
        cout << "Times objects are NOT equal" << endl;
    }
    cout << t1 << endl;
    t2++;
    cout << t2 << endl;
    if (t1 == t2) {
        cout << "Times objects are equal" << endl;
    } else {
        cout << "(Expected)Times objects are NOT equal" << endl;
    }
     
    // system("PAUSE"); //for DevC++ on windows
    return EXIT_SUCCESS;
}