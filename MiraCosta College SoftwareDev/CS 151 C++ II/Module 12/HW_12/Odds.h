#ifndef ODDS_H
#define ODDS_H

#include <iostream>
#include "AbstractSeq.h"
using namespace std;

class Odds : public AbstractSeq{
public:
    virtual int fun(int k);
};

int Odds::fun(int k){
    return 2 * k + 1;//return odd number from sequence of numbers called
}

#endif