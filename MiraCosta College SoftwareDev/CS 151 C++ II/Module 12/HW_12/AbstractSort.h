#ifndef ABSTRACTSORT_H
#define ABSTRACTSORT_H
using namespace std;

class AbstractSort{
protected:
    int compareCount; //count times a swap occurs
public:
    AbstractSort();
    int compare(int[], int, int);
    int getCompareCount();
    void print(int[], int);
    virtual void sort(int[], int) = 0;
};

AbstractSort::AbstractSort(){
    compareCount = 0;
}

int AbstractSort::getCompareCount() {
    return compareCount;
}

int AbstractSort::compare(int arr[], int k , int m) {

    if (arr[k] > arr[m]){
        //only count when swap should occur
        compareCount++;
        return 1;
    }
//    else if (arr[k] < arr[m]){ // combined with else if below to bool "if (compare(arr, i, x))" in selection sort
//        return -1;
//    }
    else if (arr[k] == arr[m] || arr[k] < arr[m]){
        //do nothing and return "false"
        return 0;
    }
}

void AbstractSort::print(int arr[], int size){
    for (int i = 0; i < size; i++){
        cout << arr[i];
        if (i < size - 1){ //don't add ", " after last array element
            cout << ", ";
        }
    }
    cout << endl;
}

#endif
