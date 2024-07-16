/* SetBinaryTree.h - Emulates a set in C++ using a binary tree as underlying structure
 * Author:     Chris Merrill
 * Module:     16
 * Project:    Demonstration
 * Problem statement:  Replace the definition of Set in the last Module by
 *     one using a binary tree
 */

#ifndef SET_BINARYTREE_H
#define SET_BINARYTREE_H

#include <vector>
#include "BinaryTree.h"
using namespace std ;

template<class T>
class Set {

    private:
        BinaryTree<T> *tree ;

    public:
        Set() ;                                // no-arg constructor
        bool contains(T search_item) const ;
        bool insert(T new_item) ;
        Set<T> setIntersect(Set<T> other_set) const ;
        Set<T> setUnion(Set<T> other_set) const ;
        void display() const ;
        vector<T> * toVector() const ;
} ;

// No-argument constructor creates an empty set (linked list)
template<class T>
Set<T>::Set() {
    tree = new BinaryTree<T> ;
}

// Returns true if the set contains a specified data element
template<typename T>
bool Set<T>::contains(T search_item) const {
    tree->search(search_item) ;
}

// Function to add a name to a sorted list.
template<typename T>
bool Set<T>::insert(T new_item) {

    tree->insert(new_item) ;
    return true ;
}

// Create a third set which is the intersection of two other sets
// Intersection will contain only those elements in both sets
template<typename T>
Set<T> Set<T>::setIntersect(Set<T> other_set) const {

    Set<T> common_set ;                     // New set to return
    vector<T> *vect1 = other_set.toVector() ;
    vector<T> *vect2 = this->toVector() ;
    for (auto val1 : *vect1) {
        for (auto val2 : *vect2) {
            if (val1 == val2) {
                common_set.insert(val1) ;
                break ;
            }
        }
    }
    return common_set ;
}

// Return the union of this set with another set
template<typename T>
Set<T> Set<T>::setUnion(Set<T> other_set) const {

    Set<T> union_set ;     // new set to be returned

    vector<T> *vect = tree->toVector() ;
    for (auto val : *vect)
        union_set.insert(val) ;

    vect = other_set.toVector() ;
    for (auto val : *vect)
        union_set.insert(val) ;

    return union_set ;
}

template<typename T>
void Set<T>::display() const {
    tree->showInorder() ;
}

template<typename T>
vector<T> * Set<T>::toVector() const {
    return tree->toVector() ;
}

#endif
