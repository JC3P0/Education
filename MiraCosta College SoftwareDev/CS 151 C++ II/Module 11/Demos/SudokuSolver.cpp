/* SudokuSolver.cpp - Solves Sudoku problems
 * Author:     Chris Merrill
 * Module:     11
 * Project:    Demonstration
 * Problem statement:  Create a Sudoku game solver using recursion.
 *    All empty squares will be filled with 0's.  Other squares are
 *    filled with numbers from 1-9 so that no column, no row, and no
 *    3 x 3 subsquare has any duplicate numbers
 *
 * Algorithm:
 *    * Create a 9 x 9 board of ints.  O's are unfilled squares, others
 *      have a number from 1 - 9
 *    * Also create a 9 x 9 matrix of boolean items.  Set those items to
 *      true if the number is permanent (non-zero), otherwise set to false
 *    * Create a function to show the board.  Use after each move or use
 *      only when a solution is found.
 *    * Create a function to test if the number just played at a specific
 *      row/column combination is valid
 *      -- Don't need to check every square, just the row, the column, and
 *         the 3 x 3 subsquare containing the row/column combination
 *    * Finally create a function named "solve" which will look at the next
 *      possible value to place at a row/column combination.
 *    * Set variable "step-by-step" to true if you want each move to be
 *      displayed on the console
 *
 * Discussion:
 *   - This is called "backtracking", where the program tries to fill each
 *     unoccupied square with a number from 1 to 9.
 *     -- If that number doesn't work, then try the next number.
 *     -- If that number works, then call "solve" again trying to fill the
 *        next available square
 *     -- When all numbers have been tried (1 to 9), then stop the recursion
 *        at this level and go back to the prior level
 */

#include <iostream>
using namespace std ;

// Cells where there is a 0 are open for play
// Cells where there is already a number from 1 - 9 are fixed (permanent)
int board[][9] = {
    { 0, 0, 0, 8, 0, 9, 0, 7, 0}, // row 1
    { 0, 0, 8, 0, 0, 0, 9, 4, 0}, // row 2
    { 0, 0, 9, 0, 5, 7, 0, 8, 0}, // row 3
    { 8, 9, 7, 0, 0, 5, 3, 2, 1}, // row 4
    { 1, 5, 4, 2, 9, 3, 8, 6, 7}, // row 5
    { 2, 0, 0, 7, 1, 8, 5, 9, 4}, // row 6
    { 0, 0, 5, 0, 8, 0, 2, 3, 6}, // row 7
    { 0, 8, 1, 0, 7, 2, 4, 5, 9}, // row 8
    { 0, 0, 2, 0, 3, 0, 7, 1, 8}  // row 9
} ;

// Fill this parallel with "true" if the number in the corresponding cell
// is fixed, or "false" if the number should be filled by the user
bool perm[9][9] = {0} ;

void showBoard() ;                // Displays the solution on the console
bool consistent(int, int) ;       // Checks if cell at row / column is ok to play
void solve(int, int) ;            // Solve the next available cell on the board

bool step_by_step = false ;

int main() {

    // Save perm matrix (true = square is fixed, false = can be changed)
    for (int row = 0 ; row < 9 ; row++) {
        for (int col = 0 ; col < 9 ; col++) {
            perm[row][col] = (board[row][col] > 0) ? true : false ;
        }
    }

    // Start putting in values
    solve(0, 0) ;                // Start at row 0, column 0

    exit(0) ;
}

// Solve the board at this position passed as a parameter.  If this is a permanent
// square, then check if we're done, otherwise go to the next square.  If its not
// a permanent square, check for each possible value in square, verify that it's
// a good move, and go to the next square if yes, otherwise back up to the last
// square.
void solve(int test_row, int test_col) {

    if (step_by_step) {
        cout << "Verifying board: " ;
        showBoard() ;
        char ch ;
        cin >> ch ;
    }

    // If this is a permanent square and we're at the end, show the solution and return
    if (perm[test_row][test_col]) {
        if ((test_row == 8) && (test_col == 8)) {
            showBoard() ;
            return ;
        } else {
            test_col++ ;
            if (test_col > 8) {
                test_col = 0 ;
                test_row++ ;
            }
            solve(test_row, test_col) ;
        }
    } else {

        // This square isn't permanent.  Test each possible value (1-9).
        // If the board is still consistent, then proceed to the next square
        for (int value = 1 ; value <= 9 ; value++) {
            board[test_row][test_col] = value ;
            if (consistent(test_row, test_col)) {

                if ((test_row == 8) && (test_col == 8)) {
                    showBoard() ;              // It's a solution!
                    return ;
                } else {
                    int next_row = test_row ;
                    int next_col = test_col + 1 ;
                    if (next_col > 8) {
                        next_col = 0 ;
                        next_row++ ;
                    }
                    solve(next_row, next_col) ;
                }
            }
        }

        // All done testing valid values for this square.  Back up one
        // square ("backtrack") and continue to the next value in that square.
        board[test_row][test_col] = 0 ;
    }
}

// Function to show the board
void showBoard() {

    static int solution = 0 ;

    solution++ ;
    cout << "Solution: " << solution << endl << endl ;

    cout << "Board col    0 1 2 3 4 5 6 7 8" << endl << endl ;
    for (int row = 0 ; row < 9 ; row++) {
        cout << "     row " << row << "   " ;
        for (int col = 0 ; col < 9 ; col++) {
            cout << board[row][col] << " " ;
        }
        cout << endl ;
    }
    cout << endl ;
}

// Test the board for consistency.  Ignore everything that hasn't been assigned.
// Make sure that no value appears twice in same row, twice in same column, or
// twice in the same sub-board using the square just updated in solve()
bool consistent(int verify_row, int verify_col) {

    int verify_value = board[verify_row][verify_col] ;           // value just played
    int col = 0, row = 0 ;                                       // counters

    int low_row = (verify_row / 3) * 3 ;             // boundaries for the group this row is in
    int high_row = low_row + 2 ;

    int low_col = (verify_col / 3) * 3 ;            // boundaries for the group this column is in
    int high_col = low_col + 2 ;

    // Any other square in this row that's the same?
    for (col = 0 ; col < 9 ; col++) {
        if ((verify_value == board[verify_row][col]) && (col != verify_col)) {
            return false ;
           }
    }

    // Anything else in this column that's the same?
    for (row = 0 ; row < 9 ; row++) {
        if ((verify_value == board[row][verify_col]) && (row != verify_row)) {
            return false ;
        }
    }

    // Anything else in this group?
    for (row = low_row ; row <= high_row ; row++) {
        for (col = low_col ; col <= high_col ; col++) {
            if ((col != verify_col) && (row != verify_row)) {
                if (verify_value == board[row][col]) {
                    return false ;
                }
            }
        }
    }

    // Everything checks out
    return true ;
}
