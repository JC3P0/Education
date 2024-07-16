/* FormattingData.cpp - Create a formatted report of people and their credit balances
 * Author:     Chris Merrill
 * Module:     9
 * Project:    Demonstration
 * Problem statement:  Create a structure for a person with their credit card number,
 *    bank name, and card balance.  Create a formatted report routed first to the
 *    console, then to a file.
 *
 * Algorithm:
 *   1. Create a structure named Account
 *      1a. Data members (string) card name, (string) bank name, (double) balance
 *      1b. Full constructor
 *   2. Create a function named showBalances
 *      2a. Parameters are an ofstream and an array of Accounts.  Both parameters
 *          should be passed by reference (this includes all streams)
 *      2b. Print a heading on the report showing the card name, bank name,
 *          and open balance on the card
 *      2c. Print a nicely-formatted report (columnar) showing each card in
 *          the vector parameter
 *      2d. Define the actual function after main, so use a prototype of the
 *          function at the top of the program
 *   3. In main, create a vector of Accounts
 *   4. Create 4 Account objects and push onto the vector
 *   5. Call the showBalances function routing a nicely-formatted report
 *      to the console
 *      5a. Use I/O manipulators to make sure each column in the report
 *          occupies the same number of characters
 *      5b. Make sure that text is left-aligned and numbers are right-aligned
 *      5c. At the bottom of the report show a total of all card balances
 *   6. Create an output file named "MyCards.txt" and assign to an fstream
 *      (or ofstream)
 *   7. Call showBalances again routing the same report to MyCards.txt
 *   8. Close the output file
 *
 * Discussion:
 *   - All IO manipulators (setw, right, left, setprecision) work on fstreams
 *   - Passing ostreams (cout and an fstream) as a parameter by reference
 */

#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
using namespace std ;

struct Account {

    string card_number,
           lender_name ;
    double balance ;

    Account(string number, string name, double bal) {
        card_number = number ;
        lender_name = name ;
        balance = bal ;
    }
} ;

// Prototype function
void showBalances(ostream &, vector<Account> &) ;

int main() {

    // Create a vector of accounts
    vector<Account> cards ;
    cards.push_back(Account("5943 4932 4920 0017", "Shell", 42.87)) ;
    cards.push_back(Account("4920 8021 2946 3721", "Citibank", 721.95)) ;
    cards.push_back(Account("952 49214 4939 7012", "Master Card", 361.05)) ;
    cards.push_back(Account("0025 401 7915 243", "Walmart", 59.20)) ;

    // Print report on console
    showBalances(cout, cards) ;

    // Route report to a file
    ofstream card_file("MyCards.txt") ;
    showBalances(card_file, cards) ;
    card_file.close() ;

    return 0 ;
}

// Function to print a formatted report of all credit cards on an output stream
void showBalances(ostream &out_stream, vector<Account> &cards) {

    // Print heading
    out_stream << fixed << setprecision(2)
               << "     Card Number         Lender       Balance" << endl
               << "--------------------  ------------  -----------" << endl ;

    // Print body of the report using for-each loop
    double total = 0.0 ;
    for (Account my_card : cards) {
        out_stream << left << setw(22) << my_card.card_number
                   << setw(12) << my_card.lender_name
                   << setw(13) << right << my_card.balance << endl ;
        total += my_card.balance ;
    }

    // And finally the total damages
    out_stream << setw(47) << "------------" << endl
               << setw(47) << total << endl ;
}
