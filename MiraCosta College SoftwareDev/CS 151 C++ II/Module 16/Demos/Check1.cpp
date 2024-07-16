/* Check1.cpp - Builds a binary tree with 5 nodes.
 * Author:     Textbook
 * Module:     16
 * Project:    Check 1 - From the textbook (pr19-02).
 * Problem statement: Use the IntBinaryTree.h and IntBinaryTree.cpp files from
 *     the Gaddis textbook to build a binary tree.  Enter the nodes in the
 *     order 5, 8, 3, 12, and 9., print the nodes when traversed
 *     in preorder, inorder, and preorder.
 *
 * Algorithm:
 *   1. Copy code from textbook for IntBinaryTree
 *   2. In main, add nodes 5, 8, 3, 12, and 9
 *   3. Print the tree in preorder, inorder, and preorder
 *
 * Note that inorder is sorted.
 */

#include <iostream>
#include "IntBinaryTree.h"
using namespace std ;

int main() {

    // Create the tree and insert the nodes
    IntBinaryTree tree ;
    cout << "Inserting the numbers 5 8 3 12 9 into the tree.\n\n" ;
    tree.insert(5) ;
    tree.insert(8) ;
    tree.insert(3) ;
    tree.insert(12) ;
    tree.insert(9) ;

    // Print in all three orders
    cout << "InOrder traversal:   " ;
    tree.showInOrder() ;

    cout << "\nPreOrder traversal:  " ;
    tree.showPreOrder() ;

    cout << "\nPostOrder traversal: " ;
    tree.showPostOrder() ;

    cout << "\nUsing treePrint():   " ;
    tree.treePrint() ;

    cout << "\n\n12 is" << (tree.search(12) ? "" : "not ") << " found in the tree" ;
    cout << "\n7 is " << (tree.search(4) ? "" : "not ") << "found in the tree" ;

    cout << "\n\nDeleting 8...\n" ;
    tree.remove(8) ;

    cout << "Deleting 12...\n\n" ;
    tree.remove(12) ;

    cout << "Here are the remaining elements: " ;
    cout << "\nUsing InOrder traversal: " ;
    tree.showInOrder() ;
    cout << "\nUsing treePrint():       " ;
    tree.treePrint() ;
    cout << endl << endl ;

    return 0 ;
}
