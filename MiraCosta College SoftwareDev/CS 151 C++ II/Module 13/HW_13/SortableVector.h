#ifndef SORTABLEVECTOR_H
#define SORTABLEVECTOR_H

#include <iostream>
#include "SimpleVector.h"
#include <algorithm>

template<class T>
//derived from SimpleVector
class SortableVector : public SimpleVector<T> {

public:
    // exception class
    class ArrayIndex {};
    // constructor
    SortableVector(int s) : SimpleVector<T>(s) {}
    void sort(); //sort the object
    T &operator[](const int &);  // overloaded [] operator
};

template <class T>
void SortableVector<T>::sort() {
    bool test = true;

    while(test) {
        test = false;
        //calls SimpleVector for size and [] operator
        for (int i = 0; i < (SimpleVector<T>::getSize() - 1); i++){
            if (SimpleVector<T>::operator[](i) > SimpleVector<T>::operator[](i + 1)){
                //swap if next index is lower
                swap(SimpleVector<T>::operator[](i), SimpleVector<T>::operator[](i + 1));
                test = true;
            }
        }
    }
}

template <class T>
T &SortableVector<T>::operator[](const int &sub) {
    if (sub < 0 || sub >= SimpleVector<T>::getSize()){
        throw ArrayIndex(); //throw exception if negative or greater than size
    }
    return SimpleVector<T>::operator[](sub) ;
}

#endif