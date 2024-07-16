/*______________________
* AUTHOR: <Josh Clemens>
* COURSE: CS 150: C++ Programming 1
* NC (PROJECT)#: NC12_2
* LAST MODIFIED: 03/03/22
*_______________
* Student LineUp
*_____________________
* PROGRAM DESCRIPTION:
* Opens file "LineUp.txt" then loops to read all student names then arrange in alphabetical order.
*___________
* ALGORITHM:
* READ names from file
* CALCULATE in alphabetical order the first and last names
* OUTPUT first and last names
*____________________________________________
* ALL IMPORTED LIBRARIES NEEDED AND PURPOSE:
* <cstdlib> Provides standard functions, including dynamic memory management,
* random number generation, communication with the environment,
* integer arithmetics, searching, sorting and converting.
* <iostream> Used for console input and output (cin and cout).
* <fstream> to open and read files
*____________________________________________*/

#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char *argv[]) {

    /***** CONSTANT SECTION *****/
    //no const.
 
    /***** DECLARATION SECTION *****/

    ifstream inFile;
    string inputName;

    /***** INITIALIZATION SECTION *****/
    
    string lastName = "Aaa";
    string firstName = "Zzz";
 
    /***** INTRO SECTION *****/ 

    cout << "Welcome to the Student Line Up.\n";
    cout << endl; 

    /***** INPUT SECTION *****/

    inFile.open("lineup.txt");
   
    /***** PROCESSING SECTION *****/

    while (inFile >> inputName)
    {
        if (inputName > lastName)
        {
            lastName = inputName;
        }
        else if (inputName < firstName)
        {
            firstName = inputName;
        }
    }
    
    /***** OUTPUT SECTION *****/

    cout << "The student in the front of the line is, " << firstName << "." << endl;
    cout << "The student at the end of the line is, " << lastName << "." << endl;
 
    // system("PAUSE"); //for DevC++ on windows
    return EXIT_SUCCESS;
}
