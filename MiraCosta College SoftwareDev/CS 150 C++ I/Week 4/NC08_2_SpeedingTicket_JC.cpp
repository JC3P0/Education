/*______________________
* AUTHOR: <Josh Clemens>
* COURSE: CS 150: C++ Programming 1
* NC (PROJECT)#: <NC08_2>
* LAST MODIFIED: <02/16/22>
*________________
* Speeding Ticket 
*_____________________
* PROGRAM DESCRIPTION:
* Accepts a speed limit and a clocked speed and prints if speed was legal or the amount of the fine if illegal
*___________
* ALGORITHM:
* PROMPT clockSpeed, speedLimit
* CALCULATE if (clockSpeed > speedLimit)
* CALCULATE fine = ((clockSpeed - speedLimit) * FINE_PER_MPH$5) + fine$50
* CALCULATE if (clockSpeed >= PENALTY_SPEED90)
* CALCULATE fine += PENALTY_FINE$200
* OUTPUT legal speed or fine amount
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

    const double PENALTY_SPEED = 90;
    const double PENALTY_FINE = 200;
    const double FINE_PER_MPH = 5;
    
    /***** DECLARATION SECTION *****/

    int clockSpeed;
    int speedLimit;
    double fine = 50;
        
    /***** INITIALIZATION SECTION *****/
    //no init.
           
    /***** INTRO SECTION *****/

    cout << "This program will accept a clocked speed and a speed limit and will output a fine if the speed limit has been exceeded!" << "\n" << endl;
     
    /***** INPUT SECTION *****/

    cout << "Please enter the clocked speed of the vehichle: ";
    cin >> clockSpeed;
    cout << "Please enter a speed limit: ";
    cin >> speedLimit;
    cout << "" << endl;

    /***** PROCESSING SECTION *****/
    
    if (clockSpeed > speedLimit)
    { fine = ((clockSpeed - speedLimit) * FINE_PER_MPH) + fine; }
    if (clockSpeed >= PENALTY_SPEED)
    { fine += PENALTY_FINE; }
    
    /***** OUTPUT SECTION *****/
    
    if (clockSpeed > speedLimit)
    { cout << "Your fine is $" << fine << endl; }
    else
    { cout << "You were not speeding" << endl; }
 
    // system("PAUSE"); //for DevC++ on windows
    return EXIT_SUCCESS;

}
