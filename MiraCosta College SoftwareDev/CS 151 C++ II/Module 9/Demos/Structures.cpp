/* Structures.cpp - Write credit cards info onto a binary file, then read back
 * Author:     Chris Merrill
 * Module:     9
 * Project:    Demonstration
 * Problem statement:  Create a structure for a person with their credit card number,
 *    bank name, and card balance.  Write to a binary file, then read the binary
 *    file back to print the report on the screen.
 *
 * Algorithm:
 *   1. Start with the "FormattingDemo" project
 *   2. Change the string data members in the Account class to fixed-length
 *      arrays of chars (C-strings)
 *   3. Change the constructor of the Account class to use strcpy the strings
 *      into the arrays using strcpy
 *   4. Change the program to use an array of cards, rather than a vector
 *   5. Use the "open" statement to use a binary file named MyCard.dat
 *   6. Write the entire array onto the file using the reinterpret_cast logic
 *      and close the binary file
 *   7. Reopen the binary file for reading (not sure why I had to do this...)
 *   8. Change the showCard function to take an index into the MyCard.dat file
 *      8.1 - Position the seek pointer to the correct position in the file
 *      8.2 - Load an Account structure from the file
 *      8.3 - Print the Account data on the console
 *   9. Change main to print each Account separately.  Do Not print them in
 *      the order they are stored in the array
 *
 * Discussion:
 *   - Changed strings to character arrays in the structure
 *       -- Used strcpy to convert from string to C-string
 *   - Size of Account structure should be unchanging from one Account to
 *     another, since the size of each object is fixed
 *   - The 'double' element is moved out to an even multiple of 8 address
 *   - Data file has to be binary (not text)
 *   - Can also write out the entire array instead of using a loop...
 *   - Had to close, then reopen for input -- not sure why...
 *     ** Even tried a flush() -- but didn't work.
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std ;

const int CARD_NUMBER_SIZE = 23,
          CARD_NAME_SIZE = 15 ;

struct Account {

    char card_number[CARD_NUMBER_SIZE],
         card_name[CARD_NAME_SIZE] ;
    double balance ;                    // moved out to address divisible by 8

    Account(string number = "", string name = "", double bal = 0.0) {
        strcpy(card_number, number.c_str()) ;
        strcpy(card_name, name.c_str()) ;
        balance = bal ;
    }
} ;

// Prototype function, takes a stream (cout or a file) and index into array
void showCard(fstream &, int) ;

int main() {

    // Create an array of accounts (instead of a vector)
    Account cards[4] ;
    cards[0] = Account("5943 4932 4920 0017", "Shell", 42.87) ;
    cards[1] = Account("4920 8021 2946 3721", "Citibank", 721.95) ;
    cards[2] = Account("952 49214 4939 7012", "Master Card", 361.05) ;
    cards[3] = Account("0025 401 7915 243", "Walmart", 59.20) ;

    // Show the size of an individual Account and the size of the array
    cout << "Size of an Account object is    " << sizeof(Account) << " bytes." << endl
         << "Size of array of 4 Accounts is " << sizeof(cards) << " bytes."
         << endl << endl ;

    // Open a binary read/write stream and write the objects all at once
    remove("MyCards.dat") ;
    fstream card_file("MyCards.dat", ios::binary | ios::out) ;
    card_file.write(reinterpret_cast<char *>(cards), sizeof(cards)) ;

    // Flush and close
    card_file.close() ;

    // Reopen for input and read the cards in a random order
    card_file.open("MyCards.dat", ios::binary | ios::in) ;
    showCard(card_file, 2) ;
    showCard(card_file, 1) ;
    showCard(card_file, 0) ;
    showCard(card_file, 3) ;
    card_file.close() ;

    return 0 ;
}

// Function to print a card at a specified index in the file of cards
void showCard(fstream &io_stream, int index) {

    Account card ;
    long offset = index * sizeof(Account) ;
    io_stream.clear() ;
    io_stream.seekg(offset, ios::beg) ;
    io_stream.read(reinterpret_cast<char *>(&card), sizeof(Account)) ;
    cout << "Card #" << index << setprecision(2) << fixed
         << "   Number: " << left << setw(CARD_NUMBER_SIZE) << card.card_number
         << "   Name: " << setw(CARD_NAME_SIZE) << card.card_name
         << "   Balance: " << right << setw(12) << card.balance << endl << endl ;
}

