#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H

#include <iostream>
#include <cstdlib>
using namespace std ;

template <class T>
class SimpleVector {

private:
    T *aptr; //template pointer
    int arraySize; //size of array
    int pos; //position of index
    void subError(); // handles subscripts out of range

public:
    // exception classes
    class ArrayIsFull {};
    class ArrayIsEmpty {};

    // default constructor
    SimpleVector() {
        aptr = 0;
        arraySize = 0;
    }

    SimpleVector(int); // Constructor
    SimpleVector(const SimpleVector &); // Copy constructor
    ~SimpleVector();  // Destructor
    int getSize() const; //holds arraySize
    virtual T &operator[](const int &); // Overloaded [] operator
    void print(); //print object
    void pushBack(T); //add element to object
    void popBack(); //remove element from object
};

template <class T>
int SimpleVector<T>::getSize() const {
    return arraySize;
}

//*************************************************************
//         Constructor for SimpleVector class                 *
// Sets the size of the array and allocates memory for it.    *
//*************************************************************
template <class T>
SimpleVector<T>::SimpleVector(int s) {

    arraySize = s;
    aptr = new T [s];

    for (int count = 0 ; count < arraySize; count++)
//        *(aptr + count) = T() ;
        aptr[count] = T();
}

//************************************************
// Copy Constructor for SimpleVector class       *
//************************************************
template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj) {

    arraySize = obj.array_size;
    aptr = new T [arraySize];
    for(int count = 0 ; count < arraySize; count++)
//        *(aptr + count) = *(obj.aptr + count);
        aptr[count] = obj[count];
}

//***************************************
// Destructor for SimpleVector class    *
//***************************************
template <class T>
SimpleVector<T>::~SimpleVector() {
    if (arraySize > 0){
        delete [] aptr;
    }
}

//*************************************************************
//              SubError function                             *
// Displays an error message and terminates the program when  *
// a subscript is out of range.                               *
//*************************************************************
template <class T>
void SimpleVector<T>::subError() {
    cout << "ERROR: Subscript out of range.\n";
    exit(0);
}

//*************************************************************
//             Overloaded [] operator                         *
// This function returns a reference to the element           *
// in the array indexed by the subscript.                     *
//*************************************************************
template <class T>
T &SimpleVector<T>::operator[](const int &sub) {
    if (sub < 0 || sub >= arraySize){
        subError() ;
    }
    pos = sub; //holds position
    return aptr[sub] ;
}

//*************************
// prints the array       *
//*************************
template <class T>
void SimpleVector<T>::print(){
    for (int i = 0; i < arraySize; i++){
        cout << aptr[i];
        if (i < arraySize - 1){ //only add ", " if not at last element
            cout << ", ";
        }
    }
    cout << endl;
}

//********************************************************
//              pushBack function                        *
// Inserts the value to the last element of SimpleVector *
// Exception thrown if array is full                     *
//********************************************************
template <class T>
void SimpleVector<T>::pushBack(T v) {
    if (pos + 1 >= arraySize){
        throw ArrayIsFull(); //throw exception if greater than arraySize
    }
    else{
        aptr[pos + 1] = v;
        pos++; //move position forward one
    }
}

//***************************************
//              popBack function        *
// Removes last element from array      *
// Throws exception if array is empty   *
//***************************************
template <class T>
void SimpleVector<T>::popBack(){
    if (pos < 0){
        throw ArrayIsEmpty(); //throw exception if array is empty
    }
    else{
        aptr[pos] = T();
        pos--; //move position back one
    }
}

#endif