#ifndef ABSTRACTSEQ_H
#define ABSTRACTSEQ_H

#include <iostream>
#include <iomanip>
using namespace std;

class AbstractSeq{
public:
    virtual int fun(int) = 0; //pure virtual member function to be used in Odds and Factorial classes
    void printSeq(int, int);
    int sumSeq(int, int);
};

void AbstractSeq::printSeq(int k, int m) {
    if (k < m){
        for (int i = k; i <= m; i++){
            //use setw to align columns
            cout << setw(11) << i << right << setw(12) << fun(i) << endl;
            //first output (n) then the result of fun(n)
        }
    }
}

int AbstractSeq::sumSeq(int k, int m) {
    int sum = 0;
    if (k < m){
        for (int i = k; i <= m; i++){
            sum += fun(i);
        }
    }
    return sum;
}

#endif