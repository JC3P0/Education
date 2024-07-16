/*______________________________________
* FILE: LAB_13_SEQUENCE_ACCUMULATION_JC.cpp
* AUTHOR: Josh Clemens
* MODULE: 13
* PROJECT: Lab 2
* LAST MODIFIED: November 20, 2022
* PROBLEM STATEMENT: Uses a template function to add the sum of the elements in a vector
* ALGORITHM:
*    INITIALIZE template function that accepts a vector to add the sum of all elements in the vector
*    INITIALIZE a vector of ints, doubles and strings
*    OUTPUT all vectors and the sum of their elements
*______________________________________*/

#include <iostream>
#include <vector>
using namespace std;

template <class T>
//template function to accept vector and add sum of elements
    T accum(vector <T> v){
        T sum = v[0];
        for (int i = 1; i < v.size(); i++){
            sum+= v[i];
        }
        return sum;
    }

int main(){

    vector<int> intVector {26, 55, 72}; // vector of ints
    vector<double> doubleVector {552, 62, 54, 23}; // vector of doubles
    vector<string> stringVector {"102", "55", "132", "504"}; // vector of strings

    cout << "Int Vector contains: ";
    for (int i = 0; i < intVector.size(); i++){ // display int vector
        cout << intVector[i];
        if (i < intVector.size() - 1){ //don't add ", " to last number
            cout << ", ";
        }
    }
    cout << endl;
    cout << "The sum of the Int Vector: " << accum(intVector); //calculate sum

    cout << "\n\nDouble Vector contains: ";
    for (int i = 0; i < doubleVector.size(); i++){ // display Double vector
        cout << doubleVector[i];
        if (i < doubleVector.size() - 1){ //don't add ", " to last number
            cout << ", ";
        }
    }
    cout << endl;
    cout << "The sum of the Double Vector: " << accum(doubleVector); //calculate sum

    cout << "\n\nString Vector contains: ";
    for (int i = 0; i < stringVector.size(); i++){ // display String vector
        cout << stringVector[i];
        if (i < stringVector.size() - 1){ //don't add ", " to last number
            cout << ", ";
        }
    }
    cout << endl;
    cout << "The sum of the String Vector: " << accum(stringVector); //calculate sum

    //exit message
    cout << "\n\nThank you for using the Sequence Accumulation program.\n";
    return 0;
}