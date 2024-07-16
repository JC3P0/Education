/* SortedDoubleList.cpp - Use same list of students to add to a doubly-linked sorted list
 * Author:     Chris Merrill
 * Module:     14
 * Project:    Demonstration
 * Problem statement:  Take the list of students (in a random order), and
 *     place into a sorted doubly-linked list
 *
 * Algorithm:
 *  1. Create global variables for the "front" and "back" of a doubly-linked
 *     list
 *     1a. We'll just have a slimed-down version of a doubly-linked list in
 *         this demo
 *   2. Use TwoWayNode defined in lecture
 *     2a. Has a "previous" node (already has a "next" node)
 *     2b. Change constructor of TwoWayNode to take values of both
 *         previous and next pointers
 *     2c. Can now traverse (show) the list in ascending and descending order
 *         -- have a showForward function which starts at the front and uses
 *            the "next" nodes to traverse in ascending order
 *         -- Have a showReverse function which starts at the back and uses
 *            the "previous" nodes to traverse in descending order
 *     2d. Create an "addSorted" function which adds a string to the list
 *         so that the list is always in sorted (ascending) orer
 *         -- Don't need a "before" pointer to insert any more, since we
 *            can easily find the pointer preceding the insertion point.  Just
 *            use the "back" pointer (if adding to the end) or the
 *            previous node of the "after" pointer
 *         -- If the string to be inserted goes at the front of the list (or if
 *            the list is empty)
 *            -- Create a new TwoWayNode with the "next" node pointing to the
 *               old node at the front (or null if the list is empty) and the
 *               previous node pointing to nullptr
 *            -- If the old list was empty, then set the back pointer to tne
 *               new node
 *            -- If the old list wasn't empty, the set the previous pointer
 *               in the old node at the front to the new node
 *         -- Add to the end (if at end) or insert into the list.  Notice that since
 *            there is no "before" pointer, use either the back pointer (if inserting
 *            at the end of the list) or the previous node of the "after" pointer
 *  3. In main,
 *     3a. Create an array of student names to insert into the doubly-linked
 *         list
 *     3b. Loop through the names and add to the list using the addSorted
 *         function
 *     3c. Use the showForward function to list the students alphabetically
 *     3d. Use the showReverse function to the list in descending alphabetic
 *         order
 */

#include <iostream>
#include <iomanip>
using namespace std ;

struct TwoWayNode {
    string name ;
    TwoWayNode *previous ;
    TwoWayNode *next ;

    // constructor and destructor
    TwoWayNode(string new_name, TwoWayNode *new_prev, TwoWayNode *new_next) {
        name = new_name ;
        previous = new_prev ;
        next = new_next ;
    }
} ;

// Prototypes
void add_sorted(string) ;        // add the name to a sorted list
void show_forward() ;            // show all names in ascending order
void show_reverse() ;            // show all names in descending order

// Make the front and back global, since the "add_sorted" function can update both
TwoWayNode *front = nullptr ;
TwoWayNode *back = nullptr ;
int main() {

    // Create an unsorted array of names to add to a sorted list
    string array[] {"Hannah", "Jian", "Ian", "Yuan", "Denny", "Zoey", "Sandy",
                    "Bob", "Yoshi", "Xavier", "Francis", "Charlene", "Alicia",
                    "Giorgio", "Sam", "Ernesto"} ;

    // Add or insert the items from the array in sorted order.  Print contents of the
    // list after each addition or insertion in both forward and reverse direction.
    int size = sizeof(array) / sizeof(*array) ;
    for (int i = 0 ; i < size ; i++) {
        add_sorted(array[i]) ;
        cout << "Added " << setw(10) << left << array[i] ;
        show_forward() ;
        cout << " (reversed)     " ;
        show_reverse() ;
        cout << endl ;
    }

    return 0 ;
}

// Function to add a name to a sorted list.  (Need to return the new head if
// the name was added to the front of the list.)
void add_sorted(string name_to_add) {

    // If the list is empty or if the name to add goes at the front of the
    // list, then just add a new node and update back (if necessary)
    if (front == nullptr || front->name >= name_to_add) {
        TwoWayNode *new_node = new TwoWayNode(name_to_add, nullptr, front) ;
        if (front != nullptr) {
            front->previous = new_node ;
        }
        front = new_node ;
        if (back == nullptr) {
            back = new_node ;
        }
        return ;
    }

    // Find the position to add/insert this new name.  In this case, we just
    // need a pointer to the node after the insertion point.
    TwoWayNode *after = front ;           // will come after the new node

    while (after != nullptr && after->name <= name_to_add) {
        after = after->next ;
    }

    // Add to the end (if at end) or insert into the list.  Notice that since
    // there is no "before" pointer, use either the back pointer (if inserting
    // at the end of the list) or the previous node of the "after" pointer
    if (after == nullptr) {
        TwoWayNode *temp = new TwoWayNode(name_to_add, back, after) ;
        back->next = temp ;
        back = temp ;
    } else {
        TwoWayNode *temp = new TwoWayNode(name_to_add, after->previous, after) ;
        after->previous->next = temp ;
        after->previous = temp ;
    }
}

// Show the names in the linked list on one line starting at parameter pointer
void show_forward() {
    TwoWayNode *ptr = front ;
    while (ptr != nullptr) {
        cout << ptr->name << " " ;
        ptr = ptr->next ;
    }
    cout << endl ;
}

void show_reverse() {
    TwoWayNode *ptr = back ;
    while (ptr != nullptr) {
        cout << ptr->name << " " ;
        ptr = ptr->previous ;
    }
    cout << endl ;
}

