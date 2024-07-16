/* SortedList.cpp - Use a random list of student to add to a sorted list
 * Author:     <your name>
 * Module:     14
 * Project:    Exercise #2
 * Problem statement:  Take the list of students (in a random order), and place
 *     into a sorted list
 *
 * Algorithm:
 *   1. Use a LinkedNode class (node) from the lecture
 *   2. Create an "addSorted" function which inserts students into
 *      a LinkedList in sorted order
 *      -- Will have to handle inserting in the front, in the middle,
 *         and at the end of the list separately.
 *   3. Create a "show" function which traverses the linked list and
 *      displays the strings in that list on the console
 *   4. In main, create an array of strings representing student names
 *         in random order: "Hannah", "Jian", "Ian", "Yuan", 
 *         "Denny", "Zoey", "Sandy", "Bob", "Yoshi", "Xavier", 
 *         "Francis", "Charlene", "Alicia", "Giorgio", "Sam", "Ernesto"}
 *   5. Using the array, create a sorted linked list of students by
 *      using the addSorted function
 *   6. Using the "show" function, display the names of the students
 *      in the list (hopefully in sorted order)
 *
 * Discussion:
 *   * For strings in C++, can use the <=, ==, and >= operators for comparison
 */

#include <iostream>
#include <iomanip>
using namespace std ;

struct LinkedNode {
    string name ;
    LinkedNode *next ;

    // constructor
    LinkedNode(string n, LinkedNode *p = nullptr)
        { name = n ; next = p ; }
} ;

// Prototypes
LinkedNode * addSorted(LinkedNode *, string) ;     // add the name to a sorted list
void show(LinkedNode *) ;                          // show all names in the list

int main() {

    // Create an unsorted array of names to add to a sorted list
    string array[] {"Hannah", "Jian", "Ian", "Yuan", "Denny", "Zoey", "Sandy",
                    "Bob", "Yoshi", "Xavier", "Francis", "Charlene", "Alicia", "Giorgio",
                    "Sam", "Ernesto"} ;

    // Create empty linked list
    LinkedNode *head = nullptr ;

    // Add or insert the items from the array in sorted order.  Print the contents of the list
    // after each addition or insertion.
    int size = sizeof(array) / sizeof(*array) ;
    for (int i = 0 ; i < size ; i++) {
        head = addSorted(head, array[i]) ;       // may have to re-assign head if adding to front
        cout << "Adding " << setw(10) << left << array[i] << endl ;
        show(head) ;
    }

    return 0 ;
}

// Function to add a name to a sorted list.  (Need to return the new head if
// the name was added to the front of the list.)
LinkedNode * addSorted(LinkedNode *start, string name_to_add) {

    // Add your code here

    return start ;           // unchanged
}


// Show the names in the linked list on one line starting at parameter pointer
void show(LinkedNode *ptr) {

    // Add your code here
}

