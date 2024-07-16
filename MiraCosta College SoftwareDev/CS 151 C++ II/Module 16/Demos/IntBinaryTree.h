/* IntBinaryTree.h - Tree node definition, root node, and functions in binary tree
 * Author:     Textbook
 * Module:     16
 * Project:    Check #1
 */

#include <iostream>
using namespace std ;

class IntBinaryTree {

    private:
        class TreeNode {                    // Nodes in the tree

            friend class IntBinaryTree ;    // Tree Functions can access members directly
            int value ;                     // Data member in this node
            TreeNode *left ;                // Pointer to left subtree
            TreeNode *right ;               // Pointer to right subtree

            // Constructor for a node in the tree
            TreeNode(int value1, TreeNode *left1 = nullptr, TreeNode *right1 = nullptr) {
                value = value1 ;
                left = left1 ;
                right = right1 ;
            }
        } ;

        TreeNode *root ;     // Pointer to the root of the tree

        // Helper member functions defined in IntBinaryTree.cpp file.
        void insert(TreeNode *&, int) ;
        void destroySubtree(TreeNode *) ;
        void remove(TreeNode * &, int) ;
        void makeDeletion(TreeNode * &) ;
        void displayInOrder(TreeNode *) const ;
        void displayPreOrder(TreeNode *) const ;
        void displayPostOrder(TreeNode *) const ;
        void treePrint(TreeNode *tree, ostream &) const ;

    public:
        // These member functions are the public interface.
        IntBinaryTree() {                         // Constructor
            root = nullptr ;
        }
        ~IntBinaryTree() {                        // Destructor
            destroySubtree(root) ;
        }

        // Many of these are provided because other classes don't have access to root
        bool search(int) const ;
        void insert(int num) {
           insert(root, num) ;
        }
        void remove(int num) {
            remove(root, num) ;
        }
        void showInOrder(void) const {
            displayInOrder(root) ;
        }
        void showPreOrder() const {
            displayPreOrder(root) ;
        }
        void showPostOrder() const {
            displayPostOrder(root) ;
        }
        void treePrint() {
             treePrint(root, cout) ;
        }
} ;
