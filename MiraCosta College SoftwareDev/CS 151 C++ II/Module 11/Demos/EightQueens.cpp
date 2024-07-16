/* EightQueens.cpp - Solves the eight queens problem using backtracking.
 * Author:     Chris Merrill
 * Module:     11
 * Project:    Demonstration
 * Problem statement: Solve the eight queens problem using recursion 
 *     and backtracking.
 *
 * Algorithm:
 *   1. Assume that each row on a chessboard will have one queen (otherwise
 *      they will threaten each other
 *   2. Create an n x n board and an array of "n" queens
 *      2a. Set a constant at top of the program to represent value of "n"
 *   3. Create a function named "play" which takes the queen at a specific
 *      row and tries to play the queen on that row on each column
 *   4. After placing the queen on that row:
 *      4a. If that's the last queen to be played, then print a solution
 *          (see step 6 below)
 *      4b. Otherwise call play() again using the queen on the next row
 *   5. In play, make sure that the queen being played is not threatened by
 *      any other queen on a lower row
 *      5a. No other queen can be in the same column
 *      5b. No other queen can be on a diagnal to the queen being played
 *      5c. If this queen is being threatened, then move to the next column
 *      5d. When out of columns, return to the queen in the previous row (backtrack)
 *   6. Create a function named "show" which shows the location of all queens
 *      on a board
 *      6a. Call this function for each solution found (from step 4a above)
 *
 * Discussion:
 *    - Use of recursion in solve
 *    - Examine, abandon, backtrack, accept
 *    - There are 92 solutions, but several are rotations or
 *      mirror solutions of others
 *    - Set SIZE down to 4 to find a solution to a 4 x 4 board
 */

#include <iostream>
using namespace std ;

// prototypes
void showAnswer() ;
bool playQueen(int) ;

const int SIZE = 8 ;         // The size of the board
int queens[SIZE] ;           // Each queen will occupy a row
int solution_number = 0 ;

/********************************************************************************
 * main function creates an array of "n" queens, then tries to place the first one
 * on row 0.  If successful, a solution is generated recursively via the playQueen
 * function, so print the solution.
  ********************************************************************************/
int main() {

    // Play the first queen in row 0.  The playQueen() function will then use
    // recursion to try and place the remaining queens.
    if (playQueen(0)) {
        showAnswer() ;
    } else {
        cout << "\nNo more solutions!" ;
    }
}

/*******************************************************************************
 * Try to place a queen safely in the specified row. Using recursion, this
 * function also tries to place all queens in higher-numbered rows.  If successful,
 * return true.  If no solution exists at this row, return false.
 *******************************************************************************/
bool playQueen(int row) {

    // Try placing the queen in every square in this row.
    for (int column = 0 ; column < SIZE ; column++) {

        queens[row] = column ;             // Put the queen on the square

        // Make sure that this queen is not threatened by checking all queens in
        // lower-numbered rows (examine)
        bool safe = true ;
        for (int which = 0 ; which < row ; which++) {

            // Is this column aleady occupied?
            if (queens[which] == column) {
                safe = false ;
                break ;
            }

            // Any threats on either diagonal?
            if ((abs(which - row) == abs(column - queens[which]))) {
                safe = false ;
                break ;
            }
        }

        // If this queen is threatened on this square, then continue to the
        // next square (abandon)
        if (!safe) {
            continue ;
        }

        // If this is the last queen to be placed safely on the board, then
        // this is a solution (accept)
        if (row == SIZE - 1) {
            showAnswer() ;
            continue ;
        }

        // Otherwise, use recursion to see if we can safely place the next queen
        // on the board (examine)
        if (playQueen(row + 1)) {
            return true ;
        }
    }

    // All squares for this row have been checked (backtrack).
    return false ;
}

/* Display the answer on the console.  Each element in the queen
 * array is the column she is occupying.
 */
void showAnswer() {

    cout << "\nSolution " << ++solution_number << " for "
         << SIZE << " rows and columns: \n" ;

    for (int row = 0 ; row < SIZE ; row++) {
        cout << "   row " << row << ":  " ;
        for (int column = 0 ; column < SIZE ; column++) {
            cout << (queens[row] == column ? "Q " : ". ") ;
        }
        cout << endl ;
    }
}

