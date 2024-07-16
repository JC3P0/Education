//
// Created by JoshC on 10/8/2022.
//

#ifndef UNTITLED5_OWL_H
#define UNTITLED5_OWL_H

#include "Animal.h"
#include <iostream>

using namespace std;

class Owl : public Animal{

private:

    string breed;

public :
    Owl(string, string);  // constructor

    string getBreed() const;
    void setBreed(string);
    void makeNoise();
    void showInfo();

};

//constructor
Owl::Owl(string name, string breed){
    setName(name);
    this -> breed = breed;
}

//getter
string Owl::getBreed() const{
    return breed;
}

//setter
void Owl::setBreed(string new_breed) {
    breed = new_breed;
}

void Owl::makeNoise(){
    cout << "The Owl " << getName() << " is hooting." << endl;
}

void Owl::showInfo(){
    cout << "The owl " << getName() << endl;
}

#endif //UNTITLED5_OWL_H