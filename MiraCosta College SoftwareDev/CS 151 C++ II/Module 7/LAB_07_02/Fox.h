//
// Created by JoshC on 10/8/2022.
//

#ifndef FOX_H
#define FOX_H

#include "Animal.h"
#include <iostream>

using namespace std;

class Fox : public Animal{
//no private members for this class
private:


public :
    Fox(string);  // constructor

    void makeNoise();
    void showInfo();

};

//constructor
Fox::Fox(string name){
    setName(name);
}

void Fox::makeNoise(){
    cout << "The Fox " << getName() << " is yelping." << endl;
}

void Fox::showInfo(){
    cout << "The Fox " << getName() << endl;
}

#endif FOX_H