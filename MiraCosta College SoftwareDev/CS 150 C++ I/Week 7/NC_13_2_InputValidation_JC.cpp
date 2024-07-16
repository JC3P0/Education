/*____________________
* AUTHOR: Josh Clemens
* COURSE: CS 150: C++ Programming 1
* NC (PROJECT)#: NC13_2
* LAST MODIFIED: 03/07/22
*________________
* InputValidation 
*_____________________
* PROGRAM DESCRIPTION:
* Uses a set of functions for input validation
*___________
* ALGORITHM:
* PROMPT users input
* CALCULATE if input is valid
* OUTPUT input validation requirements for invalid inputs
* PROMPT for valid input
*____________________________________________
* ALL IMPORTED LIBRARIES NEEDED AND PURPOSE:
* <cstdlib> Provides standard functions, including dynamic memory management,
* random number generation, communication with the environment,
* integer arithmetics, searching, sorting and converting.
* <iostream> Used for console input and output (cin and cout).
*____________________________________________*/

#include <cstdlib>
#include <iostream>
using namespace std;

double valInIsGrt(double max);
double valInIsLwr(double min);
double valInBtw(double min, double max);

int main() 
{

    /***** CONSTANT SECTION *****/
    //no const.
 
    /***** DECLARATION SECTION *****/
    
    double result;
    
    /***** INITIALIZATION SECTION *****/
    // no init.
    
    /***** INTRO SECTION *****/ 

    cout << "Welcome to Input Validation!\n";
    cout << endl;

    /***** INPUT SECTION *****/
    // see functions
 
    /***** PROCESSING SECTION *****/
    // see functions
    
    /***** OUTPUT SECTION *****/

    result = valInIsGrt(5);
    cout << result << " is correct!" << endl;
    cout << endl;
    result = valInIsLwr(10);
    cout << result << " is correct!" << endl;
    cout << endl;
    result = valInBtw(1, 4);
    cout << result << " is correct!" << endl;
    cout << endl;


    // system("PAUSE"); //for DevC++ on windows
    return EXIT_SUCCESS;
}

    /***** Function Definitions *****/

double valInIsGrt(double max)
{
    double input;
    cout << "Enter a number greater than " << max << ": ";
    cin >> input;
    
    while (input < max)
    {
        cout << "Invalid entry." << endl;
        cout << "Enter a number greater than " << max << ": ";
        cin >> input;
    }
    return input;
}

double valInIsLwr(double min)
{
    double input;
    cout << "Enter a number less than " << min << ": ";
    cin >> input;
    
    while (input > min)
    {
        cout << "Invalid entry." << endl;
        cout << "Enter a number less than " << min << ": ";
        cin >> input;
    }
    return input;
}

double valInBtw(double min, double max)
{
    double input;
    cout << "Enter a number between " << min << " and " << max << ": ";
    cin >> input;

    while (input < min || input > max)
    {
        cout << "Invalid entry." << endl;
        cout << "Enter a number between " << min << " and " << max << ": ";
        cin >> input;
    }
    return input;
}
