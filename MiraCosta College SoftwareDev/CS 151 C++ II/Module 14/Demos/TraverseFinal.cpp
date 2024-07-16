/* TraverseFinal.cpp - Traverse a simple linked list
 * Author:     Chris Merrill
 * Module:     14
 * Project:    Exercise #1 (Final version)
 * Problem statement:  Create a simple single linked list and demonstrate
 *    adding elements and traversing
 *
 * Algorithm:
 *   1. Use the LinkedList structure from the textbook
 *      - Has an outer structure LinkedNode
 *        -- has a string data element
 *        -- a pointer to the next LinkedNode structure
 *        -- a constructor which takes a string and pointer
 *   2. In main
 *      2a. Create an array of several names (strings) of students
 *      2b. Create a stringstream objecct and add each name from the array
 *          into the stringstream
 *      2c. Create an empty linked list
 *      2d. Simulating reading the names from a file, add each name to
 *          the linked list
 *      2e. Using the linked list, print a nicely-formatted report showing
 *          the address of the node, the name of the student in the node,
 *          and the address of the next node in the list
 *
 * Discussion
 *   * LinkedNode taken from lecture
 *     -- Use a list of student names instead of ints
 *   * Items are entered into a stringstream in reverse order to emulate
 *     adding items from a file
 *   * Items are then "read" from the stringstream and entered into a linked list
 *   * head is located in stack area, links are allocated from the heap
 */

#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std ;

struct LinkedNode {
    string data ;
    LinkedNode *next ;
    LinkedNode(string d, LinkedNode *p = nullptr)
        { data = d ; next = p ; }
} ;

int main() {

    string array[] {"Alicia", "Bob", "Charlene", "Denny", "Ernesto",
                    "Francis", "Giorgio", "Hannah", "Ian", "Jian"} ;

    // Add the items from the array a stringstream (in reverse order)
    // (Simulate reading from a file).
    int size = sizeof(array) / sizeof(*array) ;
    stringstream iostr ;
    for (int i = size - 1 ; i >= 0 ; i--) {
        iostr << array[i] << endl ;
    }

    // Add the names (in reverse order) into a linked list reading each
    // name from the stringstream
    LinkedNode *head = nullptr ;
    string name ;
    while (iostr >> name) {
        head = new LinkedNode(name, head) ;
    }

    // Print the contents of the list from head to its end
    cout << endl
         << "                    Addr. of" << endl
         << "       Name           Node          Link" << endl
         << "    ----------  ---------------  ----------" << endl ;
    LinkedNode *ptr = head ;

    // Information for head link
    cout << "    (head)    " << setw(17) << &head
         << setw(12) << head << endl ;

    // Information for each node in the linked list
    while (ptr != nullptr) {
        cout << "    " << setw(10) << left << ptr->data
             << setw(17) << right << ptr
             << setw(12) << ptr->next << endl ;
        ptr = ptr->next ;
    }
    cout << endl ;

    return 0 ;
}

