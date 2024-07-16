/*____________________
* AUTHOR: Josh Clemens
* COURSE: CS 150: C++ Programming 1
* NC (PROJECT)#: NC_15_02
* LAST MODIFIED: 03/19/22
*__________________
* More Nested Loops
*_____________________
* PROGRAM DESCRIPTION:
* Uses a nested for loop to output patterns using "/", "*", and "\." The size (rows) to change with user input. Enter 0 to end the program.
*___________
* ALGORITHM:
* PROMPT user for size of pyramids
* VALIDATE enter 0 to end program
* CALCULATE display patterns using "/", "*", and "\" per user input
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
    /***** CONSTANT SECTION *****/ 
    // no const. 

    /***** DECLARATION SECTION *****/

    int size;
    
    /***** INITIALIZATION SECTION *****/
    // no init.

    /***** INTRO SECTION *****/ 
    
    cout << "Welcome to the size pyramid!";
    
    /***** INPUT SECTION *****/

    do
    {
        cout << "\nEnter Size: ";
        cin >> size;
        cout << endl;
    
    /***** PROCESSING SECTION *****/ /***** OUTPUT SECTION *****/

        for (int i = 1; i <= size; i++) // verticle length
        { 
            for (int x = size; x > i; x--) //left pyramid
            {
                cout << "////";
            }
        
            for (int y = 1; y < i; y++) //center pyramid
            {
                cout << "********";
            }

            for (int z = size; z > i; z--) //right pyramid
            {
                cout << "\\\\\\\\";
            }
            cout << endl;
        }
    }while (size != 0); // validate input
        cout << "Thanks for using the size pyramid!\n";

    // system("PAUSE"); //for DevC++ on windows
    return EXIT_SUCCESS;
}
