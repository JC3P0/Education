/* StringReplace.cpp - Replace all occurrences of one C-String with another
 * Author:     <Josh Clemens>
 * Module:     10
 * Project:    Midterm Problem 1
 * Problem statement: Replace all occurrences of one C-String with another C-String
 *   in an original C-String
 */

#include <iostream>
#include <cstring>
using namespace std ;

// prototype
void replaceSubstring(char *, char *, char *) ;

int main() {

    // Define three C-strings, the original string, the one to replace, and the replacement
    char original[250] ;
    char source[50] ;
    char target[50] ;
    

    // Get the original C-string
    cout << "Enter the original string:   " ;
    cin.getline(original, 250) ;

    cout << "Enter the string to replace: " ;
    cin.getline(source, 50) ;

    cout << "Enter its replacement:       " ;
    cin.getline(target, 50) ;

    // Call the function to replace all occurrences of source with target, then print
    replaceSubstring(original, source, target) ;
    cout << "With all replacements made:  " << original ;
}

// Function to be defined
void replaceSubstring(char *original, char *source, char *target) {

    char *strPtr = strstr(original, source);
    if(strPtr){
        strncpy (strPtr, target, 4);
    }
}