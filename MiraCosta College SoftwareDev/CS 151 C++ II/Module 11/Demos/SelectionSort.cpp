/* SelectionSort.cpp - Sort the characters in a string using a Selection sort
 * Author:     Chris Merrill
 * Module:     11
 * Project:    Demonstration
 * Problem statement:  A recursive selection sort for characters in a string.
 *     It finds the LARGEST element in the string and places it LAST. It then
 *     finds the remaining largest element and places it next to last and
 *     so on until the list contains only one element.
 *
 *     Use the ASCII value of each character to determine relationships
 *
 * Algorithm:
 *    1. Create a function named "sort" with the following heading
 *
 *                      sort(string &, int high)
 *
 *       where the first parameter is the string of characters to be placed in
 *       sorted order, and "high" is the character currently being placed (decreases
 *       by one during each recursive call)
 *        1a. Use a loop to find the index of the "smallest" character starting at
 *            the beginning of the array up to (and including) the character
 *            at position "high"
 *        1b. Swap the character that that position with the character at
 *            position "high"
 *        1c. Call the function again with "high" decremented by 1
 *        1d. Stopping case is when high = 0 ;
 *
 *    2. Provide an "entry" function with a heading:
 *
 *                        sort(string &)
 *
 *       which calls the function defined in #1 above using the length of the
 *       string -1 as the value for high.
 *    3. In main,
 *       3a. Prompt for a string of characters
 *       3b. Call the function defined in #2 above
 *       3c. Print the value of the string after the sort
 *
 *  Discussion:
 *    - The function defined in #2 above is simply a nice way for other programmers
 *      to use this sorting function, hiding the recursive aspect of this
 *      solution
 *    - In this version, the highest character is placed last (rather than the
 *      smallest character placed first.)
 *    - What happens if the string is already sorted?
 */

#include <iostream>
#include <string>
using namespace std ;

// prototypes
void sort(string &str) ;            // Wrapper function
void sort(string &str, int high) ;

int main() {

    cout << "Enter a string: " ;
    string str ;
    getline(cin, str) ;

    //Use one sorting function here - your choice
    sort(str) ;                   // Use wrapper function for sorting
    //sort(str, str.size()-1) ;   // Use 2 arg function

    cout << "The sorted string is: " << str << endl ;

    return 0 ;
}

// Wrapper function for second sort function
void sort(string &str) {
     sort(str, str.size() - 1) ;
}

// Function that actually performs the sorting
void sort(string &str, int high) {

     if (high > 0) {

         // find the largest element and its index
         int maxIndex = 0 ;
         char max = str[0] ;
         for (int i = 1 ; i <= high ; i++)          {
             if (str[i] > max) {
                 max = str[i] ;
                 maxIndex = i ;
             }
         }

         // Swap the largest with the last element in the list
         str[maxIndex] = str[high] ;
         str[high] = max ;

         // Sort the remaining list
         sort(str, high - 1) ;
     }
}


