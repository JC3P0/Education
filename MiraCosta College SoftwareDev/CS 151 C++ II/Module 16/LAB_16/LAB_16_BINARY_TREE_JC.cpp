/*______________________________________
* FILE: LAB_16_BINARY_TREE_JC.cpp
* AUTHOR: Josh Clemens
* MODULE: 16
* PROJECT: 1
* LAST MODIFIED: December 10, 2022
* PROBLEM STATEMENT: Enhances the BinaryTree class to include recursive functions getHeight and getDiameter.
* ALGORITHM:
*    INITIALIZE EBinaryTree class to add functions getHeight and getDiameter.
*               recursive functions to stop at a leaf (end) created in private and recursively called from public in EBinaryTree class
*    INITIALIZE EBinaryTree string tree object in main
*    CALCULATE insert() names into tree
*    OUTPUT tree object showPreorder, showInorder, showPostorder
*    CALCULATE getHeight() and getDiameter on object
*    OUTPUT the height and diameter of object
*    REPEAT for trees 2-4
*______________________________________*/

#include <iostream>
using namespace std;
#include "EBinaryTree.h"

int main() {

    //intro
    cout << "Welcome to the binary tree program.\n\n";

    //build 5 binary search trees and determine heights and diameters

    //tree 1
    //create tree object
    EBinaryTree<string> treeOne;
    //insert names to tree object
    cout << "Inserting names to Tree One: Albert, Barbara, Charlie, Dexter, Eduardo, Frank, Georgio, Henrietta." << endl;
    treeOne.insert("Albert");
    treeOne.insert("Barbara");
    treeOne.insert("Charlie");
    treeOne.insert("Dexter");
    treeOne.insert("Eduardo");
    treeOne.insert("Frank");
    treeOne.insert("Georgio");
    treeOne.insert("Henrietta");
    //output tree in preorder, inorder, and postorder
    cout << "This is Tree One preorder:   ";
    treeOne.showPreorder();
    cout << "This is Tree One inorder:    ";
    treeOne.showInorder();
    cout << "This is Tree One postorder:  ";
    treeOne.showPostorder();
    //calculate height and diameter while output
    cout << "This is Height of Tree Three: " << treeOne.getHeight();
    cout << "\nThis is Diameter of Tree Three: " << treeOne.getDiameter();

    //tree 2
    EBinaryTree<string> treeTwo;
    cout << "\n\nInserting names to Tree Two: Henrietta, Georgio, Frank, Eduardo, Dexter, Charlie, Barbara, Albert." << endl;
    treeTwo.insert("Henrietta");
    treeTwo.insert("Georgio");
    treeTwo.insert("Frank");
    treeTwo.insert("Eduardo");
    treeTwo.insert("Dexter");
    treeTwo.insert("Charlie");
    treeTwo.insert("Barbara");
    treeTwo.insert("Albert");
    cout << "This is Tree Two preorder:   ";
    treeTwo.showPreorder();
    cout << "This is Tree Two inorder:    ";
    treeTwo.showInorder();
    cout << "This is Tree Two postorder:  ";
    treeTwo.showPostorder();
    cout << "This is Height of Tree Three: " << treeTwo.getHeight();
    cout << "\nThis is Diameter of Tree Three: " << treeTwo.getDiameter();

    //tree 3
    EBinaryTree<string> treeThree;
    cout << "\n\nInserting names to Tree Three: Charlie, Barbara, Eduardo, Albert, Dexter, Georgio, Frank, Henrietta." << endl;
    treeThree.insert("Charlie");
    treeThree.insert("Barbara");
    treeThree.insert("Eduardo");
    treeThree.insert("Albert");
    treeThree.insert("Dexter");
    treeThree.insert("Georgio");
    treeThree.insert("Frank");
    treeThree.insert("Henrietta");
    cout << "This is Tree Three preorder:   ";
    treeThree.showPreorder();
    cout << "This is Tree Three inorder:    ";
    treeThree.showInorder();
    cout << "This is Tree Three postorder:  ";
    treeThree.showPostorder();
    cout << "This is Height of Tree Three: " << treeThree.getHeight();
    cout << "\nThis is Diameter of Tree Three: " << treeThree.getDiameter();

    //tree 4
    EBinaryTree<string> treeFour;
    cout << "\n\nInserting names to Tree Four: Olivia, Josh, Quinn, Herb, Larry, Ryan, Kim, Mia, Violet, Theo, Willow, Sophia, Ursule" << endl;
    treeFour.insert("Olivia");
    treeFour.insert("Josh");
    treeFour.insert("Quinn");
    treeFour.insert("Herb");
    treeFour.insert("Larry");
    treeFour.insert("Ryan");
    treeFour.insert("Kim");
    treeFour.insert("Mia");
    treeFour.insert("Violet");
    treeFour.insert("Theo");
    treeFour.insert("Willow");
    treeFour.insert("Sophia");
    treeFour.insert("Ursule");
    cout << "This is Tree Four preorder:   ";
    treeFour.showPreorder();
    cout << "This is Tree Four inorder:    ";
    treeFour.showInorder();
    cout << "This is Tree Four postorder:  ";
    treeFour.showPostorder();
    cout << "This is Height of Tree Four: " << treeFour.getHeight();
    cout << "\nThis is Diameter of Tree Four: " << treeFour.getDiameter();

    //tree 5
    EBinaryTree<string> treeFive;
    cout << "\n\nInserting names to Tree Five: Ryan, Josh, Sophia, Herb, Kim, Theo, Asher, Ivy, Mia, Carter, Larry, Noah, Barry, Daniel, Olivia" << endl;
    treeFive.insert("Ryan");
    treeFive.insert("Josh");
    treeFive.insert("Sophia");
    treeFive.insert("Herb");
    treeFive.insert("Kim");
    treeFive.insert("Theo");
    treeFive.insert("Asher");
    treeFive.insert("Ivy");
    treeFive.insert("Mia");
    treeFive.insert("Carter");
    treeFive.insert("Larry");
    treeFive.insert("Noah");
    treeFive.insert("Barry");
    treeFive.insert("Daniel");
    treeFive.insert("Olivia");
    cout << "This is Tree Five preorder:   ";
    treeFive.showPreorder();
    cout << "This is Tree Five inorder:    ";
    treeFive.showInorder();
    cout << "This is Tree Five postorder:  ";
    treeFive.showPostorder();
    cout << "This is Height of Tree Five: " << treeFive.getHeight();
    cout << "\nThis is Diameter of Tree Five: " << treeFive.getDiameter();
    
    //outro
    cout << "\n\nThank you for using the Binary Tree program.\n";
    return 0;
}