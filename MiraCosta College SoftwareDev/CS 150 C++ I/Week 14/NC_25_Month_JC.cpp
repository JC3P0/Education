/*____________________
* AUTHOR: Josh Clemens
* COURSE: CS 150: C++ Programming 1
* NC (PROJECT)#: NC_25
* LAST MODIFIED: April 27, 2022
*______
* Month
*_____________________
* PROGRAM DESCRIPTION:
* Object oriented program using a Month class with fuctions and friend functions to display and change months.
*___________
* ALGORITHM:
* INITIATE Month objects
* OUTPUT Month objects
* CALCULATE if objects are equal and display
* CALCULATE increment and decrement both objects
* CALCULATE if objects are equal and display
* ASSIGN objects to = each other
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
#include <cmath> //sqrt in distance function
#include "Month.h"

using namespace std;

int main(int argc, char* argv[]) {

    /***** CONSTANT SECTION *****/
    //no const.
 
    /***** DECLARATION SECTION *****/
    //no dec.
    
    /***** INITIALIZATION SECTION *****/

    Month m1("December", 12);
    Month m2;

    /***** INTRO SECTION *****/

    cout << "Welcome to the month program.\n\n";

    /***** INPUT SECTION *****/
    //no input
    
    /***** PROCESSING SECTION *****/ /***** OUTPUT SECTION *****/

    cout << m1;
    cout << m2;
    if (m1 == m2){
        cout << "objects are equal" << endl;
     } else {
         cout << "(Expected)objects are NOT equal" << endl;
    }
    m1++;
    m2--;
    cout << m1;
    cout << m2;
    if (m1 == m2){
        cout << "objects are equal" << endl;
     } else {
         cout << "(Expected)objects are NOT equal" << endl;
        }
    m1 = m2;
    cout << m1;
    cout << m2;
    if (m1 == m2){
        cout << "(Expected)objects are equal" << endl;
     } else {
         cout << "objects are NOT equal" << endl;
    }
    
    // system("PAUSE"); //for DevC++ on windows
    return EXIT_SUCCESS;
}