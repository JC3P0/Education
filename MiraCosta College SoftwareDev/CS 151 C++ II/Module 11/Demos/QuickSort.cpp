/* QuickSort.cpp - Use the quick sort algorithm to sort an array of numbers
 * Author:     Textbook
 * Module:     11
 * Project:    Demonstration
 * Problem statement:  Use the quick sort (recursive) algorithm to sort
 *    an array of integers
 *
 * Algorithm:
 *   1. In this algorithm, the pivot point is selected first number in
 *      the subrange (part) of the array being sorted.
 *   2. The algorithm for the quick sort is:
 *      2a. Pick a "pivot"
 *      2b. Move all of the numbers in the subrange being sorted which are less
 *          than the pivot to the left of the pivot in the array
 *      2c. Move all of the numbers in the subrange being sorted which are greater
 *          than the pivot to the right of the pivot in the array
 *      2d. Put the pivot in its correct spot
 *      2e. Recursively sort the subarray to the left of the pivot
 *      2f. Recursively sort the subarray to the right of the pivot
 *      2g. The heading of the function to perform the quick sort:
 *
 *              quickSort(int* array, int low_index, int high_index)
 *
 *          where array is the start of the array being sorted, and low_index and
 *          high_index identify the low and high of the subarray to sort
 *
 *   3. Steps 2b and 2c are performed by the "partion" function
 *      3a. The partition function performs a series of swaps, swapping items
 *          that are less than the pivot with the pivot, and swapping items
 *          that are greater than the pivot with the pivot.
 *   4. In main:
 *      4a. Create an array of ints in unsorted order
 *      4b. Print the contents of the array
 *      4c. Call the quickSort function using the array to be sorted, 0 for
 *          the low index, and the size of the array - 1 for the high index.
 *
 * Discussion:
 *   1. Picking the pivot point as the first number in the subrange works well
 *      if the array is poorly sorted -- great performer
 *   2. If the array is already sorted, this algorithm degenerates into a
 *      selection sort -- poor performer
 *      2a. Other functions for picking the pivot point are to pick the middle
 *          element, and to pick the average of the first, middle, and last
 *          element in the array
 *   3. On average, this algorithm is an O(n log n) performer
 *   4. Space requirements are only size of the original array, since sorting
 *      is done in place
 */

#include <iostream>
#include <algorithm>   //needed for swap function
using namespace std ;

// Function prototypes
void quickSort(int [], int, int) ;
int partition(int [], int, int) ;

int main() {

    // Array to be sorted
    const int SIZE = 10 ;
    int array[SIZE] = {17, 53, 95, 49, 30, 1, 82, 64, 26, -5} ;

    // Echo the array to be sorted
    for (int k = 0 ; k < SIZE ; k++)
        cout << array[k] << " " ;
    cout << endl ;

    // Sort the array using Quicksort
    quickSort(array, 0, SIZE-1) ;

    // Print the sorted array
    for (int k = 0 ; k < SIZE ; k++)
        cout << array[k] << " " ;
    cout << endl ;

    return 0 ;
}

//************************************************
// quickSort uses the QuickSort algorithm to     *
// sort arr from arr[start] through arr[end].    *
//************************************************
void quickSort(int arr[], int start, int end) {

    if (start < end) {
        // Partition the array and return the index of the pivot point
        int pivot = partition(arr, start, end) ;

        // Sort the portion before the pivot point
        quickSort(arr, start, pivot - 1) ;

        // Sort the portion after the pivot point
        quickSort(arr, pivot + 1, end) ;
    }
}

//***********************************************************
// partition rearranges the entries in the array arr from   *
// start to end so all values greater than or equal to the  *
// pivot are on the right of the pivot and all values less  *
// than are on the left of the pivot.                       *
//***********************************************************
int partition(int arr[], int start, int end) {

    // The pivot element is taken to be the element at
    // the start of the subrange to be partitioned
    int pivotValue = arr[start] ;
    int pivotPosition = start ;

    // Rearrange the rest of the array elements to
    // partition the subrange from start to end
    for (int pos = start + 1 ; pos <= end ; pos++) {

        if (arr[pos] < pivotValue) {

            // arr[pos] is the "current" item.
            // Swap the current item with the item to the
            // right of the pivot element
            swap(arr[pivotPosition + 1], arr[pos]) ;

            // Swap the current item with the pivot element
            swap(arr[pivotPosition], arr[pivotPosition + 1]) ;

            // Adjust the pivot position so it stays with the
            // pivot element
            pivotPosition ++ ;
       }
   }
   return pivotPosition ;
}
