/****************************************************
* AUTHOR: <Josh Clemens>
* COURSE: CS 150: C++ Programming 1
* NC (PROJECT)#: <NC03_1>
* LAST MODIFIED: <02/05/22>
*****************************************************************************
* CyborgDataTypes
*****************************************************************************
PROGRAM DESCRIPTION:
* Determine the amount of data used by the following data types.
****************************************************************************
ALGORITHM:
* CALCULATE sizeof() for bool, char, short, int, long, long long, float, double, and long double
* OUTPUT in byte(s)
*****************************************************************************
* ALL IMPORTED LIBRARIES NEEDED AND PURPOSE:
* <cstdlib> Provides standard functions, including dynamic memory management,
* random number generation, communication with the environment,
* integer arithmetics, searching, sorting and converting.
* <iostream> Used for console input and output (cin and cout)
*****************************************************************************/

#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    
    /***** CONSTANT SECTION *****/
    //no constant
    
    /***** DECLARATION SECTION *****/
    //no declaration
    
    /***** INITIALIZATION SECTION *****/
    //no initialization
    
    /***** INTRO SECTION *****/

    cout << "Cyborg data size chart:" << endl;

    /***** INPUT SECTION *****/
    //no input
    
    /***** PROCESSING SECTION *****/
    //no processing
    
    /***** OUTPUT SECTION *****/
    
    cout << "bool:\t\t\t" << sizeof(bool) << " byte(s)" << endl;
    cout << "char:\t\t\t" << sizeof(char) << " byte(s)" << endl;
    cout << "short:\t\t\t" << sizeof(short) << " byte(s)" << endl;
    cout << "int:\t\t\t" << sizeof(int) << " byte(s)" << endl;
    cout << "long:\t\t\t" << sizeof(long) << " byte(s)" << endl;
    cout << "long long:\t\t" << sizeof(long long) << " byte(s)" << endl;
    cout << "float:\t\t\t" << sizeof(float) << " byte(s)" << endl;
    cout << "double:\t\t\t" << sizeof(double) << " byte(s)" << endl;
    cout << "long double:\t" << sizeof(long double) << " byte(s)" << endl;
    
    // system("PAUSE"); //for DevC++ on windows
    return EXIT_SUCCESS;

}