#ifndef FACTORIAL_H
#define FACTORIAL_H

#include <iostream>
#include "AbstractSeq.h"
using namespace std;

class Factorial : public AbstractSeq{
public:
    virtual int fun(int k);
};

int Factorial::fun(int k){
    int temp = 1;
    for (int i = k; i > 1; i--){
        temp = temp * i;
    }
    if (k == 0){ //handles 0
        temp = 1;
    }
    return temp; //return the factorial from sequence of numbers called
}

#endif