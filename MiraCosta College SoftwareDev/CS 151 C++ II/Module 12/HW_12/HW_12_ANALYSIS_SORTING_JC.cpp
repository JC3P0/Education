/*______________________________________
* FILE: HW_12_ANALYSIS_SORTING_JC.cpp
* AUTHOR: Josh Clemens
* MODULE: 12
* PROJECT: 1
* LAST MODIFIED: November 13, 22
* PROBLEM STATEMENT: Uses AbstractSort class to sort an array of int and analyze the number of comparisons performed by SelectionSort.
* ALGORITHM:
*    INITIALIZE AbstractSort class to keep count of times compare returns true and print array
*    INITIALIZE SelectionSort class to sort array
*    INITIALIZE SelectionSort objects in main for sorting
*    INITIALIZE int array to print and sort
*    OUTPUT print array
*    CALCULATE sort array
*    OUTPUT print array
*______________________________________*/

#include <iostream>
#include "AbstractSort.h"
#include "SelectionSort.h"
using namespace std;

const int SIZE = 10;

int main() {

    AbstractSort *objOne = new SelectionSort;
    AbstractSort *objTwo = new SelectionSort;

    //arrays to be printed and sorted
    int arrOne[SIZE] {55, 22, 88, 11, 99, 66, 77, 33, 44, 110};
    int arrTwo[SIZE] {27, 54, 87, 92, 12, 34, 52, 67, 32, 89};

    cout << "First original array.\n";
    objOne->print(arrOne, SIZE);
    objOne->sort(arrOne, SIZE);
    cout << "\nFirst array after sorting.\n";
    objOne->print(arrOne, SIZE);
    //times a swap occurs
    cout << "Number of comparisons: " << objOne->getCompareCount() << endl;
    cout << endl;

    cout << "Second original array.\n";
    objTwo->print(arrTwo, SIZE);
    objTwo->sort(arrTwo, SIZE);
    cout << "\nSecond array after sorting.\n";
    objTwo->print(arrTwo, SIZE);
    //times a swap occurs
    cout << "Number of comparisons: " << objTwo->getCompareCount() << endl;

    return 0;
}
