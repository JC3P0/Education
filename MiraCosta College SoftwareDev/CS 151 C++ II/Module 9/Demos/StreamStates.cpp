/* StreamState.cpp - Show the state of the stream bits after certain operations
 * Author:     Chris Merrill
 * Module:     9
 * Project:    Exercise #1 (final version)
 * Problem statement: Demonstrate detecting the stream states.
 *
 * Algorithm:
 *   1. Continue with the initial version
 *   2. Open the stream for input using the "test.txt" file
 *   3. Read the text just written into an array of chars
 *   4. Call showState again (shouldn't be any errors)
 *   5. Close the stream
 *   6. Try to read from the file again (after it's been closed)
 *   7. Call showState again (the "bad" state should be on)
 *   8. Clear the flags
 *   9. Call showState again (the "good" state should be on)
 *  10. Open the "test.txt" file one more time for input
 *  11. Try to write to the file
 *  12. Call showState one final time (writing to a read-only file)
 *  13. Close the file
 */

#include <iostream>
#include <fstream>
using namespace std ;

void showState(fstream &) ;

int main() {
    
    char city[30] ;

    // Create ouput stream object, perform a write, and show status flags
    fstream in_out("test.txt", ios::out) ;
    in_out << "Dallas" ;
    cout << "Normal operation (no errors)" << endl ;
    showState(in_out) ;
    in_out.close() ;

    // Read the data back in (no errors)
    in_out.open("test.txt", ios::in) ;
    in_out >> city ;
    cout << "End of file (no errors)" << endl ;
    showState(in_out) ;
    in_out.close() ;

    // Attempt to read after file closed
    in_out >> city ;
    cout << "Operation (read after close)" << endl ;
    showState(in_out) ;

    // Clear all flags - goodbit set to true when operation successful
    in_out.clear() ;
    cout << "Clear all flags" << endl ;
    showState(in_out) ;

    // Try to write on a file open for read-only
    in_out.open("test.txt", ios::in) ;
    in_out << "Boston" ;
    cout << "Trying to write on read-only file" << endl ;
    showState(in_out) ;

    return 0 ;
}

// Function to display the values of the following bits
void showState(fstream & stream) {
    cout << "    eof(): " << stream.eof() << "    "      // eof reached
         << "    fail(): " << stream.fail() << "    "    // operation failed
         << "    bad(): " << stream.bad() << "    "      // invalid operation attempted
         << "    good(): " << stream.good() << endl      // operation successful
         << endl ;
}


