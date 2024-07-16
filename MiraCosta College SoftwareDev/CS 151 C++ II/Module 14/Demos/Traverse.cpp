/* Traverse.cpp - Traverse a simple linked list
 * Author:     <your name>
 * Module:     14
 * Project:    Exercise #1
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

            // Add code to move the names in the array
            // into an iostream

    // Add the names (in reverse order) into a linked list reading each
    // name from the stringstream
    LinkedNode *head = nullptr ;

           // Add nodes to the list from the iostream

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

             // Add code to print the rest of the list

    return 0 ;
}
