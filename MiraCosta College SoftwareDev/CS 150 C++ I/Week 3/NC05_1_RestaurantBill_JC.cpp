/****************************************************
* AUTHOR: <Josh Clemens>
* COURSE: CS 150: C++ Programming 1
* NC (PROJECT)#: <NC05_1>
* LAST MODIFIED: <02/10/22>
*****************************************************************************
* Restaurant Bill and Change Maker
*****************************************************************************
PROGRAM DESCRIPTION:
* Combines two previous programs, restaurant bill and change maker to prompt for three menu items to get a total with tax, subtotal and tip. Then prompts for amount paid in values of 20$ bills to calculate the change in denominations of tens, fives, ones, quarters, dimes, nickles, and pennies.
****************************************************************************
ALGORITHM:
* PROMPT item1, item2, item3
* CALCULATE meal = item1 + item2 + item3
* CALCULATE tax = meal * taxRate(7.75%)
* CALCULATE subtotal = meal + tax
* CALCULATE tip = subtotal * tipRate(20%)
* CALCULATE total = subtotal + tip
* OUTPUT meal, tax, subtotal, tip, total
* PROMPT amountPaid
* amountPaid in values of 20$ bills
* CALCULATE total -= amountPaid (amountPaid = amountPaid - total)
* CALCULATE totalCents = amountPaid * 100 (to convert to all cents for processing)
* CALCULATE tensNeeded = totalCents / 1000
* CALCULATE totalCents = totalCents % 1000
* REPEAT for fivesNeeded, ones, quarters, dimes, nickles and pennies
* OUTPUT amountPaid, tensNeeded, fives, ones, quarters, dimes, nickles, pennies
*****************************************************************************
* ALL IMPORTED LIBRARIES NEEDED AND PURPOSE:
* <cstdlib> Provides standard functions, including dynamic memory management,
* random number generation, communication with the environment,
* integer arithmetics, searching, sorting and converting.
* <iostream> Used for console input and output (cin and cout)
* <iomanip> update cout fixed setprecision(2) for .00 in totals
*****************************************************************************/

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char *argv[])
{

    /***** CONSTANT SECTION *****/
    // no constant
    
    /***** DECLARATION SECTION *****/
    
    //restaurant bill
    double item1;
    double item2;
    double item3;
    double meal;
    double tax;
    double subtotal;
    double tip;
    double total;
    
    //change maker
    double amountPaid;
    int totalCents;
    int tensNeeded; //1000 cents
    int fivesNeeded; //500 cents
    int onesNeeded; //100 cents
    int quartersNeeded; //25 cents
    int dimesNeeded; //10 cents
    int nickelsNeeded; //5 cents
    int penniesNeeded; //1 cent
    
    /***** INITIALIZATION SECTION *****/
    // no init.
    
    /***** INTRO SECTION *****/
    
    cout << "Enter up to three menu items then amount paid for change" << endl << endl;

    //restraunt bill *INPUT SECTION*
    cout << "Enter Menu item #1: $";
    cin >> item1;
    cout << "Enter Menu item #2: $";
    cin >> item2;
    cout << "Enter Menu item #3: $";
    cin >> item3;
    cout << endl;
   
    //restaurant bill *PROCESSING SECTION*
    meal = item1 + item2 + item3;
    tax = meal * 0.0775; //tax rate is 7.75%
    subtotal = meal +tax;
    tip = subtotal * 0.2; //tip rate is 20%
    total = subtotal + tip;

    //restaurant bill *OUTPUT SECTION*
    cout << fixed << setprecision(2);
    cout << "Meal: \t\t\t$" << meal << endl;
    cout << "Tax (7.75%): \t$" << tax << endl;
    cout << "Subtotal: \t\t$" << subtotal << endl;
    cout << "Tip (20%): \t\t$" << tip << endl;
    cout << "Total: \t\t\t$" << total << endl << endl;

    //change maker *INPUT SECTION*
    cout << "Amount paid for meal in 20's: $";
    cin >> amountPaid;
    amountPaid -= total; // amountPaid = amountPaid - total;
    
    //change maker *PROCESSING SECTION*
    totalCents = amountPaid * 100; // converts amountPaid to all cents for processing
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

    //change maker *OUTPUT SECTION*
    cout << "Change: $" << amountPaid << endl;
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