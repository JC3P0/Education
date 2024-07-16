/*______________________
* AUTHOR: <Josh Clemens>
* COURSE: CS 150: C++ Programming 1
* NC (PROJECT)#: <NC11_1>
* LAST MODIFIED: <03/02/22>
*_________________
* Average Rainfall
*_____________________
* PROGRAM DESCRIPTION:
* Uses nested loops and input validation loops to collect date and calculate the average rainfall over a period of years.
*___________
* ALGORITHM:
* PROMPT years to calculate rainfall
* OUTPUT invalid entries < 1
* PROMPT rainfall per month
* OUTPUT invalid entries < 0
* CALCULATE average rainfall
*____________________________________________
* ALL IMPORTED LIBRARIES NEEDED AND PURPOSE:
* <cstdlib> Provides standard functions, including dynamic memory management,
* random number generation, communication with the environment,
* integer arithmetics, searching, sorting and converting.
* <iostream> Used for console input and output (cin and cout).
* <iomanip> Used for setprecision.
*____________________________________________*/

#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;
int main(int argc, char *argv[]) {

    /***** CONSTANT SECTION *****/
    
    const int MONTHS = 12;
 
    /***** DECLARATION SECTION *****/

    int years;
    double rainfall;
    double average;

    /***** INITIALIZATION SECTION *****/

    int monthCount = 0;
    double totalRainfall = 0;
 
    /***** INTRO SECTION *****/ 

    cout << "Welcome to the average rainfall calculator.\n";
    cout << endl; 

    /***** INPUT SECTION *****/

    cout << "How many years would you like to calculate your average rainfall for? ";
    cin >> years;
    while (years  < 1)
    {   
        cout << "Invalid entry, press enter a number greater than 1.\n";
        cout << "How many years would you like to calculate your average rainfall for? ";
        cin >> years;
    }
    
    /***** PROCESSING SECTION *****/
        
    for (int y = 1; y <= years; y++)
    {
        for (int i = 1; i <= MONTHS; i++)
        {
            string monthStr;
            if (i == 1)
            {
                monthStr = "January";
            } 
            else if (i == 2)
            {
                monthStr = "February";
            }
            else if (i == 3)
            {
                monthStr = "March";
            }
            else if (i == 4)
            {
                monthStr = "April";
            }
            else if (i == 5)
            {
                monthStr = "May";
            }
            else if (i == 6)
            {
                monthStr = "June";
            }
            else if (i == 7)
            {
                monthStr = "July";
            }
            else if (i == 8)
            {
                monthStr = "August";
            }
            else if (i == 9)
            {
                monthStr = "September";
            }
            else if (i == 10)
            {
                monthStr = "October";
            }
            else if (i == 11)
            {
                monthStr = "November";
            }
            else if (i == 12)
            {
                monthStr = "December";
            }
            cout << "Enter rainfall in inches for " << monthStr << "? ";
            cin >> rainfall;
            while (rainfall < 0)
            {   
                cout << "Invalid entry, you must enter a value greater than or equal to 0.\n";
                cout << "Enter rainfall in inches for " << monthStr << "? ";
                cin >> rainfall;
            } 
            totalRainfall += rainfall;
            monthCount++;
        }
            
    }
    average = totalRainfall / static_cast<double>(monthCount);

    /***** OUTPUT SECTION *****/

    cout << fixed << setprecision(2);
    cout << "Your average rainfall is " << average << " inches for " << monthCount 
         << " months for a total of " << totalRainfall << " inches of rain." << endl;

    // system("PAUSE"); //for DevC++ on windows
    return EXIT_SUCCESS;
}
