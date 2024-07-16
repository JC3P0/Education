/*______________________
* AUTHOR: <Josh Clemens>
* COURSE: CS 150: C++ Programming 1
* NC (PROJECT)#: <NC11_2>
* LAST MODIFIED: <03/02/22>
*_______________________
* Pattern Display Funnel
*_____________________
* PROGRAM DESCRIPTION:
* Uses a for loop to output 6 lines of repeated characters \,!, and /.
*___________
* ALGORITHM:
* CALCULATE display a pattern with \,!,/ using nested for loops
*____________________________________________
* ALL IMPORTED LIBRARIES NEEDED AND PURPOSE:
* <cstdlib> Provides standard functions, including dynamic memory management,
* random number generation, communication with the environment,
* integer arithmetics, searching, sorting and converting.
* <iostream> Used for console input and output (cin and cout)
*____________________________________________*/

#include <cstdlib>
#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {

    /***** CONSTANT SECTION *****/ /***** DECLARATION SECTION *****/
    
    const int LINES = 6;
    const int MAX_CHARACTERS = 22;
    
    /***** INITIALIZATION SECTION *****/
    //no init.
    
    /***** INTRO SECTION *****/ 
    //no intro
    
    /***** INPUT SECTION *****/
    //no input
   
    /***** PROCESSING SECTION *****/ /***** OUTPUT SECTION *****/

    for (int l =0 ; l < LINES; l++)
    {
        for (int i = 0; i < (l * 2); i++) //increase front by 2 each line
        {
            cout << "\\";
        }
        for (int i = 0; i < MAX_CHARACTERS - (l * 4); i++) //decrease middle by 4 each line
        {
            cout << "!";    
        }
        for (int i = 0; i < (l * 2); i++) //increase back by 2 each line
        {
            cout << "/";
        }    
        cout << endl; //new line will be after each complete line
    }
    
    // system("PAUSE"); //for DevC++ on windows
    return EXIT_SUCCESS;
}
