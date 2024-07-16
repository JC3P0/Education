/* GetPutChars.cpp - Use the get() and put() stream functions
 * Author:     Chris Merrill
 * Module:     9
 * Project:    Demonstration
 * Problem statement:  Demonstrate the use of the stream functions get() and
 *    put().
 *
 * Algorithm:
 *   1. Create three char variables.
 *   2. Ask the user to enter 2 characters and press Enter
 *   3. Use get() to read in the two characters and the Enter key into the three
 *      variables
 *   4. Print the ASCII values of the three characters
 *   5. Define another char variable
 *   6. Ask the user to enter a sentence, then press Enter
 *   7. In a loop, use get() to read each character until hitting \n.
 *   8. Create an array of 80 chars and set to NULL
 *   9. Read the entire line of chars into the array using the third version
 *      of the get function.  Read up to (but not including) the \n char
 *  10. Use ignore() to ignore the \n character in the input buffer
 *  11. Assign a char value to any character
 *  12. Use the put() function to print that character on the console
 *
 * Discussion:
 *   - The get() function reads one character of input (the argument) and stores
 *     it in a variable of type char even if it is a whitespace char or a '\n'.
 *     --It is useful in place of cin which will skip over whitespace chars
 *       automatically. The get() can also be used with 3 parameters
 *  - The put() function is just like the get() except that it outputs one char rather
 *    than inputing it.
 */

#include <iostream>
#include <fstream>
using namespace std ;

int main() {

    char c1, c2, c3 ;
    cout << "Enter two characters and an Enter. I will echo them back: \n" ;
    cin.get(c1) ;
    cin.get(c2) ;
    cin.get(c3) ;                  // Notice that c3 reads the '\n' char
    cout << "c1: " << c1 << "  ASCII: " << (c1 + 0) << endl
         << "c2: " << c2 << "  ASCII: " << (c2 + 0) << endl
         << "c3: " << c3 << "  ASCII: " << (c3 + 0) << endl << endl ;

    char symbol ;
    cout << "Enter a line of input and I will echo it back: \n"
         << "(Reading one letter at a time using get()" << endl ;
    do {
        cin.get(symbol) ;
        cout << symbol ;
    } while (symbol != '\n') ;      // stops after detecting the '\n' char
    cout << "Notice that the new-line character was also read by cin.get() " << endl ;
    cout << endl ;

    char input[80] = {'\0'} ;       // no effect with null terminator
    cout << "Enter a string: " << endl ;
    cin.get(input, 80, '\n') ;     // stops before the \n in cin buffer, can be left off
    cout << "Your input is: \"" << input << "\"" << endl << endl ;
    cin.ignore() ;                 // flush linefeed char from buffer

    char c4 = 'a' ;
    cout << "Demonstrating use of put() with a single character:" << endl
         << "The character is: "  ;
    cout.put(c4) ;
    cout << endl ;

    return 0 ;
}

