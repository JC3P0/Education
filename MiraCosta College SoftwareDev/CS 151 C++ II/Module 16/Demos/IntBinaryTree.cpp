/* IntBinaryTree.cpp - Function definitions for IntBinaryTree
 * Author:     Textbook
 * Module:     16
 * Project:    Check 1
 */

#include <iostream>
#include <sstream>
#include "IntBinaryTree.h"
using namespace std ;

/********************************************************************
 * Inserts a number into a given subtree of the binary search tree. *
 *******************************************************************/
void IntBinaryTree::insert(TreeNode * &tree, int num) {

    // If the tree is empty, make a new node and make it
    // the root of the tree.
    if (!tree) {
        tree = new TreeNode(num) ;
        return ;
    }

    // If num is already in tree, return.
    if (tree->value == num) {
        return ;
    }

    // The tree is not empty, insert new node into left or right subtree.
    if (num < tree->value) {
        insert(tree->left, num) ;
    } else {
        insert(tree->right, num) ;
    }
}

/**********************************************************
 * destroySubTree is called by the destructor. It deletes *
 * all nodes in the tree.                                 *
 *********************************************************/
void IntBinaryTree::destroySubtree(TreeNode *tree) {
    if (!tree) {
        return ;
    }
    destroySubtree(tree->left) ;
    destroySubtree(tree->right) ;
    delete tree ;                // Delete this node
}

//***************************************************
// searchNode determines if a value is present in   *
// the tree. If so, the function returns true.      *
// Otherwise, it returns false.                     *
//***************************************************
bool IntBinaryTree::search(int num) const {

    TreeNode *tree = root ;

    while (tree) {
        if (tree->value == num) {
            return true ;
        } else if (num < tree->value) {
            tree = tree->left ;
        } else {
            tree = tree->right ;
        }
    }
    return false ;
}

/**************************************************************
 * Delete the node in the given tree that has a value member  *
 *************************************************************/
void IntBinaryTree::remove(TreeNode *&tree, int num) {
    if (tree == nullptr) {
        return ;
    }
    if (num < tree->value) {
        remove(tree->left, num) ;
    } else if (num > tree->value) {
        remove(tree->right, num) ;
    } else {
        makeDeletion(tree) ;               // delete this node
    }
}

//***********************************************************
// makeDeletion takes a reference to a tree whose root      *
// is to be deleted. If the tree has a single child, the    *
// the tree is replaced by the single child after the       *
// removal of its root node. If the tree has two children   *
// the left subtree of the deleted node is attached at      *
// an appropriate point in the right subtree, and then      *
// the right subtree replaces the original tree.            *
//***********************************************************
void IntBinaryTree::makeDeletion(TreeNode *&tree) {
    // Used to hold node that will be deleted.
    TreeNode *nodeToDelete = tree ;

    // Used to locate the  point where the
    // left subtree is attached.
    TreeNode *attachPoint ;

    if (tree->right == nullptr) {
        tree = tree->left ;          // Replace tree with its left subtree
    } else if (tree->left == nullptr) {
        tree = tree->right ;         // Replace tree with its right subtree
    } else {
        //The node has two children, so move to right subtree.
        attachPoint = tree->right ;

        // Locate the smallest node in the right subtree
        // by moving as far to the left as possible.
        while (attachPoint->left != nullptr)
            attachPoint = attachPoint->left ;

        // Attach the left subtree of the original tree as the left subtree
        // of the smallest node in the right subtree.
        attachPoint->left = tree->left ;

        // Replace the original tree with its right subtree.
        tree = tree->right ;
    }

    // Delete root of original tree
    delete nodeToDelete ;
}

/**********************************************************
 * Display the values stored in a tree in inorder.        *
 *********************************************************/
void IntBinaryTree::displayInOrder(TreeNode *tree) const {
    if (tree) {
        displayInOrder(tree->left) ;
        cout << tree->value << "  " ;
        displayInOrder(tree->right) ;
    }
}

/**********************************************************
 * Display the values stored in a tree in inorder.        *
 *********************************************************/
void IntBinaryTree::displayPreOrder(TreeNode *tree) const {
    if (tree) {
        cout << tree->value << "  " ;
        displayPreOrder(tree->left) ;
        displayPreOrder(tree->right) ;
    }
}

/**********************************************************
 * Display the values stored in a tree in postorder.      *
 *********************************************************/
void IntBinaryTree::displayPostOrder(TreeNode *tree) const {
    if (tree) {
        displayPostOrder(tree->left) ;
        displayPostOrder(tree->right) ;
        cout << tree->value << "  " ;
    }
}

/**************************************************************
 * Display the values stored in a tree in prefix type display *                                *
 *************************************************************/
void IntBinaryTree::treePrint(TreeNode *tree, ostream& out) const {
    if (!tree) {
        out << "_" ;
        return ;
    } else {
        ostringstream left_strstream ;
        ostringstream right_strstream ;

        treePrint(tree->left, left_strstream) ;
        treePrint(tree->right, right_strstream) ;
        out << "(" << tree->value << left_strstream.str() << ","
            << right_strstream.str() << ")" ;
    }
}
