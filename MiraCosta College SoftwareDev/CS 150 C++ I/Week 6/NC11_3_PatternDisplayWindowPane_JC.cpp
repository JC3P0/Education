/*______________________
* AUTHOR: <Josh Clemens>
* COURSE: CS 150: C++ Programming 1
* NC (PROJECT)#: <NC11_3>
* LAST MODIFIED: <03/02/22>
*____________________________
* Pattern Display Window Pane
*_____________________
* PROGRAM DESCRIPTION:
* Uses nested for loops to output window patterns.
*___________
* ALGORITHM:
* CALCULATE display a window pattern with +===+ and |   | using nested for loops.
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

    /***** CONSTANT SECTION *****/
    
    const int VERTICAL_SIZE = 3;
        
    /***** DECLARATION SECTION *****/

    int size;
    
    /***** INITIALIZATION SECTION *****/
    //no init.
    
    /***** INTRO SECTION *****/ 
    
    cout << "Welcome to wacky window designs!?" << endl;
        
    /***** INPUT SECTION *****/
    
    cout << "Enter the size of the windows: ";
    cin >> size;
    while (size <= 0) //input validation
    {
        cout << "Invalid, please enter 1 or more.\n";
        cout << "Enter the size of the windows: ";
        cin >> size;
    }
   
    /***** PROCESSING SECTION *****/ /***** OUTPUT SECTION *****/

    for (int j = 0; j < size; j++) // verticle length per size
    {
        for (int i = 0; i < size; i++) // top
        {
            cout << "+===";
        }
        cout << "+" << endl;
    
        for (int x = 0; x < VERTICAL_SIZE; x++) // middle
        {
            for (int i = 0; i < size; i++)
            {
                cout << "|   ";
            }
            cout << "|" << endl;
        }
    }
    for (int i = 0; i < size; i++) // bottom
    {
        cout << "+===";
    }
    cout << "+" << endl;
    
    // system("PAUSE"); //for DevC++ on windows
    return EXIT_SUCCESS;
}