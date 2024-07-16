/*____________________
* AUTHOR: Josh Clemens
* COURSE: CS 150: C++ Programming 1
* NC (PROJECT)#: NC_15_01
* LAST MODIFIED: 03/19/22
*__________________
* More Nested Loops
*_____________________
* PROGRAM DESCRIPTION:
* Uses a nested for loop to output the following "-" and number pyramids
*___________
* ALGORITHM:
* CALCULATE display pyramid patterns with - and numbers 1,3,5,7,9
*___________________________________________
* ALL IMPORTED LIBRARIES NEEDED AND PURPOSE:
* <cstdlib> Provides standard functions, including dynamic memory management,
* random number generation, communication with the environment,
* integer arithmetics, searching, sorting and converting.
* <iostream> Used for console input and output (cin and cout)
*____________________________________________*/


#include <cstdlib>
#include <iostream>
using namespace std;
int main(int argc, char *argv[]) 
{
    /***** DECLARATION SECTION *****/
    // no declaration
    
    /***** CONSTANT SECTION *****/ 
    
    const int LINE = 5; // verticle length of patterns
    
    /***** INITIALIZATION SECTION *****/
    
    int num = 1; //starts the number pyramid at 1
    int dashes = 5; //starts the - pyramids at 5

    /***** INTRO SECTION *****/ 
    //no intro
    
    /***** INPUT SECTION *****/
    //no input
   
    /***** PROCESSING SECTION *****/ /***** OUTPUT SECTION *****/
    
    for (int i = 1; i <= LINE; i++) // verticle length
    { 
        for (int x = 0; x < dashes; x++) //left pyramid
        {
            cout << "-";
        }
        
        for (int y = 0; y < num; y++) //center number pyramid
        {
            cout << num;
        }
        
        for (int z = 0; z < dashes; z++) //right pyramid
        {
            cout << "-";
        }
        cout << endl; //starts a new line for each pass through the loop
        dashes -= 1; //left and right pyramids decrease by 1 each loop
        num += 2; //center number pyramid skips by 2 each loop (1,3,5,7,9)
    }

    // system("PAUSE"); //for DevC++ on windows
    return EXIT_SUCCESS;
}
