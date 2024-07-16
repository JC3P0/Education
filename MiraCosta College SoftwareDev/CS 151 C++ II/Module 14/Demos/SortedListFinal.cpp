/* SortedListFinal.cpp - Use a random list of student to add to a sorted list
 * Author:     Chris Merrill
 * Module:     14
 * Project:    Exercise #2
 * Problem statement:  Take the list of students (in a random order), and place
 *     into a sorted list
 *
 * Algorithm:
 *   1. Use the programs provided as starting point in this lab
 *   2. Create an "addSorted" function with the following heading:
 *
 *                LinkedList * addSorted(LinkedList *ptr, string)
 *
 *      This function takes a string, and inserts a node in a LinkedList of
 *      strings in the proper order so the list is always sorted.
 *      Students can be added in the front, middle, and back of the list
 *       -- Will have to handle inserting at the front separately.
 *       -- Otherwise will need to use logic to insert somewhere in the
 *          middle or at the end of the list.
 *   3. If the string is less than the current head of the list (or if the
 *      list is empty), then use the addFirst method to add the string to
 *      the front of the list and return the new "head" of the list
 *   4. Otherwise use the logic to insert a node somewhere in the middle or
 *      end of the list
 *      4a. Create a node pointer called "after" which is assigned to the head
 *          of the list
 *      4b. Create another node pointer called "before" which is initially
 *          assigned to nullptr
 *      4c. Loop through the list until the string referenced by "after" comes
 *          before the string being inserted or if the node referenced by "after"
 *          is the last item in the list.
 *      4d. Create a new pointing with the string being inserted into the list
 *          and its "next" element set to "start"
 *      4e. Set the value of the "next" elemet referenced by the "before" pointer
 *          to the new node
 *      4f. Return the existing value of the current head of the list (unchanged)
 *
 *
 * Discussion
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
LinkedNode * addSorted(LinkedNode *, string) ;   // add the name to a sorted list
void show(LinkedNode *) ;                        // show all names in the list

int main() {

    // Create an unsorted array of names to add to a sorted list
    string array[] {"Hannah", "Jian", "Ian", "Yuan", "Denny", "Zoey", "Sandy",
                    "Bob", "Yoshi", "Xavier", "Francis", "Charlene", "Alicia",
                    "Giorgio", "Sam", "Ernesto"} ;

    // Create empty linked list
    LinkedNode *head = nullptr ;

    // Add or insert the items from the array in sorted order.  Print
    // the contents of the list after each addition or insertion.
    int size = sizeof(array) / sizeof(*array) ;
    for (int i = 0 ; i < size ; i++) {
        // Have to re-assign head if adding to front
        head = addSorted(head, array[i]) ;
        cout << "Adding " << setw(10) << left << array[i] ;
        show(head) ;
    }

    return 0 ;
}

// Function to add a name to a sorted list.  (Need to return the new head
// if the name was added to the front of the list.)
LinkedNode * addSorted(LinkedNode *start, string name_to_add) {

    // If the list is empty or if the name comes before the first name in
    // the list, then just add to the front
    if (start == nullptr || (start->name > name_to_add)) {
        start = new LinkedNode(name_to_add, start) ;
        return start ;                    // new head of the list
    }

    // Find the position to add/insert this new name.  Keep pointers to
    // the nodes before and after the insertion point.
    LinkedNode *after = start ;           // will come after the new node
    LinkedNode *before = nullptr ;        // node prior to the insertion point
    while (after != nullptr && after->name <= name_to_add) {
        before = after ;
        after = after->next ;
    }

    // Add to the end (if at end) or insert into the list
    before->next = new LinkedNode(name_to_add, after) ;
    return start ;                        // unchanged
}


// Show the names in the linked list on one line starting at parameter pointer
void show(LinkedNode *ptr) {
    while (ptr != nullptr) {
        cout << ptr->name << " " ;
        ptr = ptr->next ;
    }
    cout << endl ;
}

