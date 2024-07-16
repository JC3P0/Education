//
// Created by JoshC on 10/8/2022.
//

#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
using namespace std ;

class Animal {

private:
//protected: //testing line

    string name;

public :
    Animal(); //default constructor
    Animal(string);  // constructor

    string getName() const;
    void setName(string new_name);
    void nap();
    void makeNoise();
    void showInfo();

};

//default constructor
Animal::Animal(){
    Animal("No Name.");
}

//constructor
Animal::Animal(string name) :
    name(name) {};

//getter
string Animal::getName() const{
    return name;
}

//setter
void Animal::setName(string new_name) {
    name = new_name;
}

void Animal::nap(){
    cout << "The Animal " << this -> name << " is napping." << endl;
}

void Animal::makeNoise(){
    cout << "The Animal " << this -> name << " is making noise." << endl;
}

void Animal::showInfo(){
    cout << "The Animal " << this -> name << endl;
}

#endif ANIMAL_H