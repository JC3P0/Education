#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include "AbstractSort.h"
class SelectionSort : public AbstractSort {
public:
    virtual void sort(int[], int);
};

void SelectionSort::sort(int arr[], int size) {
    int index = 0;
    int value = 0;

    for (int i = 0; i < size; i++){
        index = i;
        value = arr[i];
	//store index and value for possible swap

        for (int x = i + 1; x < size; x++){

            if (compare(arr, i, x)){//test if current comparison needs to be swapped
                value = arr[x];
                index = x;
                //only swap array elements if compare returns true
                arr[index] = arr[i];
                arr[i] = value;
            }
        }
    }
}

#endif
