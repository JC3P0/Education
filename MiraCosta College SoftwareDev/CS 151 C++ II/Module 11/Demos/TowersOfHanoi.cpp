/* TowersOfHanoi.cpp - Solve the puzzle of moving all disks from one peg to another
 * Author:     Chris Merrill
 * Module:     11
 * Project:    Demonstration
 * Project Statement: Using recursion, write a program that solves the Tower of
 *     Hanoi problem:
 *
 *        * Begin with a board having three pegs "A", "B", and "C"
 *        * On peg "A", put "n" disks of increasing size -- the tower
 *        * Move the disks from peg "A" to peg "C":
 *           - moving only one peg at a time
 *           - not placing a larger peg on a smaller peg
 *
 * Algorithm:
 *   1. Use the following recursive algorithm:
 *         a. Move n - 1 pegs to an intermediate tower
 *         b. Move the largest page to the target tower
 *         c. Move n - 1 pegs to the target tower
 */

#include <iostream>
using namespace std ;

void moveToTower(int, string, string, string) ;

// Global variables
int height,                   // height entered by user
    numberOfMoves ;           // total moves required


int main() {

     // Make sure the number of disks is between 1 and 6
     height = 0 ;
     while (height < 1 || height > 6) {

        cout << "Enter the height of the initial tower (1 - 6) : " ;
        cin >> height ;

        // Make sure the number is in range
        if (height < 1 || height > 6) {
            cout << "That is not between 1 and 6 -- retry..." << endl ;
        }
    }

    // Solve the puzzle using a recursive function
    numberOfMoves = 0 ;
    moveToTower(height, "A", "C", "B") ;  // move all disks from tower A to tower C

    // Show the total number of moves required
    cout << "\nTotal moves: " << numberOfMoves << endl << endl ;

    return 0 ;
}

/****************************************************************************
 * moveToTower() - a recursive function that moves the specified number of disks
 *    from tower (from_peg) to tower (to_peg).
 ****************************************************************************/
void moveToTower(int number_of_Disks, string from_peg, string to_peg, string with_peg) {

    // If we don't have any more disks to move, just return
    if (number_of_Disks < 1) {
        return ;
    }

    // Step 1: recursive call to move the top n-1 disks to the intermediate peg
    moveToTower(number_of_Disks - 1, from_peg, with_peg, to_peg) ;

    // Step 2: move disk "n" to its final destination
    if (number_of_Disks == height) {
        cout << "\n*** This is the largest disk ***" << endl ;
    }
    cout << "Moved disk from " << from_peg << " to " << to_peg << endl ;
    numberOfMoves++ ;
    if (number_of_Disks == height) {
        cout << endl ;
    }

    // Step 3: move the disks moved in Step 1 back to the target pole
    moveToTower(number_of_Disks - 1, with_peg, to_peg, from_peg) ;
}

