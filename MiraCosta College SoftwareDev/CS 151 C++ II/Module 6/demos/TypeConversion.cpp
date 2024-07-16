/* TypeConversion.cpp - Show type conversion operator for Character -> char
 * Author:     Chris Merrill
 * Module:     6
 * Project:    Demonstration
 * Problem Statement:  Create a "wrapper" class for chars called "Character".
 *   Create several useful functions for characters.  Demonstrate use of the
 *   type conversion operator from Character -> char.
 *
 * Algorithm:
 *   1. Create a Character class
 *      1a. Data member will be one char
 *      1b. Constructor just takes a single char and stores in data member
 *      1c. Create conversion operator for char:   char()
 *          -- Just return the data member
 *      1d. Create bool functions isLowerCase, isUpperCase, isLetter, isDigit,
 *          isLetterOrDigit, and isWhiteSpace
 *      1e. Create functions toUpperCase and toLowerCase which return a new
 *          Character object with the data member converted to an upper-case or
 *          lower-case letter
 *   2. In main:
 *      2a. Create a Character object for an 'a'
 *      2b. Use the toUpperCase function and print the result
 *      2c. Create a string "Xm4- "
 *      2d. For each of the characters in that string show whether that character
 *          is upper case, is lower case, is a letter, is a digit, or is a
 *          white-space character
 *
 * Discussion
 *    * use of conversion operator in definition of stream extraction
 *      - toUpperCase and toLowerCase return a new object
 *    * also use of conversion operator in in first line of cout statement
 *    * uncomment first line in conversion operator to see how many times it's used
 *    * uncomment bottom of main to make sure that a char doesn't automatically get
 *      converter to a Character...
 */

#include <iostream>
#include <vector>
using namespace std ;

class Character {
    private:
        char value ;

    public:
        Character(char value) {                    // constructor
            this->value = value ;
        }
        operator char() {                          // conversion operator
            // cout << "In conversion operator for " << value << endl ;
            return value ;                         // name = destination type, no return value
        }
        friend ostream &operator<<(ostream &, Character &) ;     // stream extraction

        // Added functionality
        bool isLowerCase() {
            return value >= 'a' && value <= 'z' ;
        }
        Character toUpperCase() {
            return Character(isLowerCase() ? (char) (value - 32) : value) ;
        }
        bool isUpperCase() {
            return value >= 'A' && value <= 'Z' ;
        }
        Character toLowerCase() {
            return Character(isUpperCase() ? (char) (value + 32) : value) ;
        }
        bool isLetter() {
            return isLowerCase() || isUpperCase() ;
        }
        bool isDigit() {
            return value >= '0' && value <= '9' ;
        }
        bool isDigitOrLetter() {
            return isDigit() || isLetter() ;
        }
        bool isWhitespace() {
            return (value == '\t') || (value == ' ') || (value == '\n') ;
        }
} ;

// Stream extraction operator
ostream & operator<<(ostream &out, Character &output_object) {
    out << (char) output_object ;                   // conversion operator
    return out ;
}

int main() {

    Character my_char('a') ;
    char your_char = my_char.toUpperCase() ;       // conversion operator
    cout << "Upper-case of " << my_char << " is " << your_char << endl << endl ;

    // Perform some tests on the individual characters of a string
    string test = "Xm4-. " ;
    for (int i = 0 ; i < test.length() ; i++) {
        Character a_Character(test[i]) ;
        cout << "Is '" << (char) a_Character << "' a digit? " << (a_Character.isDigit() ? "yes" : "no")
             << "\ta letter? " << (a_Character.isLetter() ? "yes" : "no")
             << "\ta digit? " << (a_Character.isDigit() ? "yes" : "no")
             << "\ta letter or digit? " << (a_Character.isDigitOrLetter() ? "yes" : "no")
             << "\twhitespace? " << (a_Character.isWhitespace() ? "yes" : "no") << endl
             << "\t\t\tto lower: " << a_Character.toLowerCase()                      // conversion constructor
             << "\tto upper: " << a_Character.toUpperCase() << endl << endl ;        // conversion constructor
    }

    // Notice that automatic conversion doesn't go the other way:
    // char x ;
    // x.toUpperCase() ;

    return 0 ;
}


