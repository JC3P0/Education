/* DeleteFromFront.cpp - Use the same list of students to add, then delete one-at-a-time
 * Author:     Chris Merrill
 * Module:     14
 * Project:    Demonstration
 * Problem statement:  Create a simple single linked list and demonstrate deleting
 *     students from the list (deleting from the front of the list)
 *
 * Algorithm:
 *   1. Use the LinkedList node from prior demos
 *   2. In main, use an array of names to add nodes to the list
 *   3. Use the "show" function to list the contents of the list
 *   4. Use a loop to delete each node from the head of the list
 *      4a. Print the list after each deletion
 *      4b. Create a node pointer to the current head of the list
 *      4c. Reset head to the "next" element in the current head of the list
 *          -- This works even if the current head of the list is at the end
 *             of the list
 *      4d. Delete the node referenced by the pointer in step 4b above
 *      4e. Stop deleting when head == nullptr
 *
 * Discussion
 *   * Just enter directly from array (no istringstream)
 *   * Start using functions to perform repetitive operations
 *   * Notice that to delete, we need to create another pointer to head, move head,
 *     then delete the old node?
 *     -- Would unique pointers work here?
 */

#include <iostream>
#include <iomanip>
using namespace std ;

// Same definition used in prior demos
struct LinkedNode {
    string name ;
    LinkedNode *next ;

    // constructor and destructor
    LinkedNode(string n, LinkedNode *p = nullptr)
        { name = n ; next = p ; }
} ;

// Prototypes
void show(LinkedNode *) ;

int main() {

    string array[] {"Alicia", "Bob", "Charlene", "Denny", "Ernesto",
                    "Francis", "Giorgio", "Hannah", "Ian", "Jian"} ;

    // Create empty linked list
    LinkedNode *head = nullptr ;

    // Add the items from the array in reverse order (so they are stored
    // in sorted order)
    int size = sizeof(array) / sizeof(*array) ;
    for (int i = size - 1 ; i >= 0 ; i--) {
        head = new LinkedNode(array[i], head) ;       // add to front of the list
    }

    // Show the contents of the array
    cout << "before deleting:     " ;
    show(head) ;

    // Start deleting from the front, showing the results after each deletion
    // Why do we have to create another pointer to the list, move head, then
    // delete the front node?
    while (head != nullptr) {
        cout << "deleting " << setw(12) << left << (head->name + ":") ;
        LinkedNode *student = head ;
        head = head->next ;
        delete student ;
        show(head) ;
    }
    cout << endl ;

    return 0 ;
}

// Show the names in the linked list on one line starting at parameter pointer
void show(LinkedNode *ptr) {
    while (ptr != nullptr) {
        cout << ptr->name << "  " ;
        ptr = ptr->next ;
    }
    cout << endl ;
}

