/****************************************************
* AUTHOR: <Josh Clemens>
* COURSE: CS 150: C++ Programming 1
* NC (PROJECT)#: <NC03_2>
* LAST MODIFIED: <02/05/22>
*****************************************************************************
* Restaurant Bill
*****************************************************************************
PROGRAM DESCRIPTION:
* Computes tax, tip, subtotal and total to a $88.67 restaurant bill with a tax rate of 7.75% and a tip rate of 20%
****************************************************************************
ALGORITHM:
* There is no variable to the meal
* CALCULATE meal * tax
* ADD meal + tax
* CALCULATE subtotal * tip
* OUTPUT totals
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

int main(int argc, char *argv[])
{

    /***** CONSTANT SECTION *****/
    // no constant
    
    /***** DECLARATION SECTION *****/
    
    double meal;
    double tax;
    double subtotal;
    double tip;
    double total;
    
    /***** INITIALIZATION SECTION *****/
    
    meal = 88.67;
    
    /***** INTRO SECTION *****/
    
    cout << "Welcome to the Restaurant Calculator!" << endl;
    
    /***** INPUT SECTION *****/
    // no variable
    
    /***** PROCESSING SECTION *****/
    
    tax = meal * 0.0775; //tax rate is 7.75%
    subtotal = meal +tax;
    tip = subtotal * 0.2; //tip rate is 20%
    total = subtotal + tip;

       
    /***** OUTPUT SECTION *****/
    
    cout << "Meal: \t\t\t$" << meal << endl;
    cout << "Tax (7.75%): \t$" << tax << endl;
    cout << "Subtotal: \t\t$" << subtotal << endl;
    cout << "Tip (20%): \t\t$" << tip << endl;
    cout << "Total: \t\t\t$" << total << endl;
    
    // system("PAUSE"); //for DevC++ on windows
    return EXIT_SUCCESS;

}