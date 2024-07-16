/* BinaryTreeTest.cpp - Use a generic version of the BinaryTree class from textbook
 * Author:     Chris Merrill
 * Module:     16
 * Project:    Demonstration
 * Problem statement: Demonstrate a generic version of the BinaryTree
 *    class from the textbook
 *
 * Algorithm:
 *   1. Download and include BinaryTree.h
 *   2. In main, create an array of characters f, 7, L, A, x, 3, n, 4, A, y
 *   3. Create a BinaryTree of chars
 *   4. Using a for-each loop, insert the 10 characters into the tree
 *   5. List the contents of the tree in preorder, inorder, and postorder
 *   6. Display whether the characters 'A' and 'm' are in the tree
 *   7. Delete nodes containing 'A' and 'f'
 *   8. Display the nodes in inorder again
 *   9. Create new trees with numbers 1 - 9 entered in ascending order
 *      and in descending order
 *  10. Show both trees in preorder, inorder, and postorder
 *
 * Discussion:
 *  - treeNode is now an internal structure - no need to make generic in
 *    definitions of functions that access a node.
 *     -- treeNode is private, so it is not accessible outside of BinaryTree
 *  - public interface includes versions of insert, remove, etc. which
 *    are recursive, and which call their private counterparts which
 *    take "root" as a starting point
 */
#include <iostream>
#include "BinaryTree.h"
using namespace std ;

int main() {

    // Create a binary tree of char elements.  Show the values, then display
    // in preorder, inorder, and postorder
    BinaryTree<char> char_tree ;

    char values[] {'f', '7', 'L', 'A', 'x', '3', 'n', '4', 'A', 'y'} ;
    cout << "Inserting the characters: " ;
    for (auto val : values) {
        char_tree.insert(val) ;
        cout << val << "  " ;
    }

    cout << "\n\nHere are the values in the tree:\n" ;
    cout << "Preorder:  " ;
    char_tree.showPreorder() ;
    cout << "Inorder:   " ;
    char_tree.showInorder() ;
    cout << "Postorder: " ;
    char_tree.showPostorder() ;

    cout << "\nDoes list contain " << values[3] << "? "
         << (char_tree.search(values[3]) ? "yes" : "no") << endl
         << "Does list contain M? "
         << (char_tree.search('M') ? "yes" : "no") << endl << endl ;

    cout << "Deleting " << values[3] << "..." << endl ;
    char_tree.remove(values[3]) ;
    cout << "Deleting " << values[0] << "..." << endl ;
    char_tree.remove(values[0]) ;

    cout << "\nNow here are the nodes (inorder):\n" ;
    char_tree.showInorder() ;

    cout << "\nDoes list contain " << values[3] << "? "
         << (char_tree.search(values[3]) ? "yes" : "no") << endl << endl ;

    // Create a tree of doubles, first by inserting in ascending oder, then
    // by inserting in descending order
    BinaryTree<int> ascending ;
    for (int i = 1 ; i < 10 ; i++)
        ascending.insert(i) ;

    cout << "For numbers 1 - 9 entered in ascending order:\n" ;
    cout << "Preorder:  " ;
    ascending.showPreorder() ;
    cout << "Inorder:   " ;
    ascending.showInorder() ;
    cout << "Postorder: " ;
    ascending.showPostorder() ;

    BinaryTree<int> descending ;
    for (int i = 9 ; i >= 1 ; i--)
        descending.insert(i) ;

        cout << "\n\nFor numbers 1 - 9 entered in descending order:\n" ;
    cout << "Preorder:  " ;
    descending.showPreorder() ;
    cout << "Inorder:   " ;
    descending.showInorder() ;
    cout << "Postorder: " ;
    descending.showPostorder() ;

    cout << endl ;
    return 0 ;
}

