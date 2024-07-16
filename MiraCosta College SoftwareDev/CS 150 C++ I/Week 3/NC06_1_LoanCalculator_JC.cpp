/****************************************************
* AUTHOR: <Josh Clemens>
* COURSE: CS 150: C++ Programming 1
* NC (PROJECT)#: <NC06_1>
* LAST MODIFIED: <02/12/22>
*****************************************************************************
* Loan Calculator
*****************************************************************************
PROGRAM DESCRIPTION:
* Calculates the monthly payment on a loan. 
****************************************************************************
ALGORITHM:
* PROMPT annualInterestRate, n(numPayments), a(amountLoan)
* CALCULATE annualInterest = annualInterest / 100
* CALCULATE r(monthlyInterestRate) = annualInterestRate / 12
* CALCULATE numerator = (pow((1+r), n)-1)
* CALCULATE denominator = (r*(pow((1+r), n)))
* CALCULATE P(monthly payment) = a(amountLoan) / (numerator/denominator)
* CALCULATE amountPaid = P(monthly payment) * n(numPayments) 
* CALCULATE interestPaid = amountPaid - a(amountLoan)
* OUTPUT n(numPayments), P(monthlyPayments), amountPaid, interestPaid
*****************************************************************************
* ALL IMPORTED LIBRARIES NEEDED AND PURPOSE:
* <cstdlib> Provides standard functions, including dynamic memory management,
* random number generation, communication with the environment,
* integer arithmetics, searching, sorting and converting.
* <iostream> Used for console input and output (cin and cout)
* <iomanip> update cout fixed setprecision(2) for .00 in totals
* <cmath> for pow equations
*****************************************************************************/

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(int argc, char *argv[])
{

    /***** CONSTANT SECTION *****/
    // no constant
    
    /***** DECLARATION SECTION *****/

    double a; //loan amount
    double n; //number of payments
    double P; //monthly payment
    double annualInterestRate;
    double r; //monthly interest
    double amountPaid;
    double interestPaid;
    double numerator;
    double denominator;

    /***** INITIALIZATION SECTION *****/
    //no init.
    /***** INTRO SECTION *****/
    //no intro
    
    /***** INPUT SECTION *****/
    
    cout << "Loan Amount: \t\t\t$";
    cin >> a;
    cout << "Annual Interest Rate: \t";
    cin >> annualInterestRate;
    
    /***** PROCESSING SECTION *****/

    annualInterestRate = annualInterestRate / 100; //convert % to a decimal
    r = annualInterestRate / 12; //divide by 12 for monthly interest rate

    /*OUTPUT*/
    cout << "Monthly Interest Rate: \t" << r *100 << "%" << endl;

    /*INPUT*/
    cout << "Number of Payments: \t";
    cin >> n;
    
    /***** PROCESSING SECTION *****/
    
    numerator = (pow((1+r), n)-1);
    denominator = (r*(pow((1+r), n)));
    P = a / (numerator/denominator);
    amountPaid = P * n;
    interestPaid = amountPaid - a;
    
    /***** OUTPUT SECTION *****/ 
    
    cout << fixed << setprecision(2);   
    cout << "Monthly Payment: \t\t$" << P << endl;
    cout << "Amount Paid Back: \t\t$" << amountPaid << endl;
    cout << "Interest Paid: \t\t\t$" << interestPaid << endl;
    
        // system("PAUSE"); //for DevC++ on windows
    return EXIT_SUCCESS;

}