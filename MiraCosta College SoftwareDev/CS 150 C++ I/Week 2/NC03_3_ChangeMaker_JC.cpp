/****************************************************
* AUTHOR: <Josh Clemens>
* COURSE: CS 150: C++ Programming 1
* NC (PROJECT)#: <NC03_3>
* LAST MODIFIED: <02/05/22>
*****************************************************************************
* Change Maker
*****************************************************************************
PROGRAM DESCRIPTION:
* Determines the dollar and change to be dispensed from a register at a grocery store. Includes amount of $10, $05, and $1 bills along with quarters, dimes, nickels and pennies. Change for $20 bills only.
****************************************************************************
ALGORITHM:
* Enter change amount
* CALCULATE totalCents = change * 100
* CALCULATE tensNeeded = totalCents / 1000
* CALCULATE tensNeeded = totalCents % 1000
* REPEATE for fives, ones, quarters, dimes, nickels and pennies
* OUTPUT how many of each required for exact change
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

    double change;
    int totalCents;
    int tensNeeded; //1000 cents
    int fivesNeeded; //500 cents
    int onesNeeded; //100 cents
    int quartersNeeded; //25 cents
    int dimesNeeded; //10 cents
    int nickelsNeeded; //5 cents
    int penniesNeeded; //1 cent
    
    /***** INITIALIZATION SECTION *****/
    
    change = 19.98;
       
    /***** INTRO SECTION *****/

    cout << "Change Maker" << endl;
    
    /***** INPUT SECTION *****/
    //no input
    
    /***** PROCESSING SECTION *****/

    totalCents = change * 100; //1406 cents
    tensNeeded = totalCents / 1000; //1000 cents = $10
    totalCents = totalCents % 1000;
    fivesNeeded = totalCents / 500; //500 cents = $5
    totalCents = totalCents % 500;
    onesNeeded = totalCents / 100; //100 cents = $1
    totalCents = totalCents % 100;
    quartersNeeded = totalCents / 25; //25 cents = 1 quarter
    totalCents = totalCents % 25;
    dimesNeeded = totalCents / 10; //10 cents = 1 dime
    totalCents = totalCents % 10;
    nickelsNeeded = totalCents / 5; //5 cents = 1 nickel
    totalCents = totalCents % 5;
    penniesNeeded = totalCents / 1; //1 cent = 1 pennie
    totalCents = totalCents % 1;
  
    /***** OUTPUT SECTION *****/
    
    cout << "Change to Compute $" << change << endl;
    cout << "$10   - " << tensNeeded << endl;
    cout << "$5    - " << fivesNeeded << endl;
    cout << "$1    - " << onesNeeded << endl;
    cout << "$0.25 - " << quartersNeeded << endl;
    cout << "$0.10 - " << dimesNeeded << endl;
    cout << "$0.05 - " << nickelsNeeded << endl;
    cout << "$0.1  - " << penniesNeeded << endl;
   
    // system("PAUSE"); //for DevC++ on windows
    return EXIT_SUCCESS;

}