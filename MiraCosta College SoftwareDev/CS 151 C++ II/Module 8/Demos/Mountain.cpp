/* Mountain.cpp - Function definitions for Mountain class
 * Author:     Chris Merrill
 * Module:     8
 * Project:    Demonstration
 */

#include <iostream>
#include "Mountain.h"
using namespace std ;

Mountain::Mountain() :
    name("no name"),
    continent("unassigned"),
    elevation(0) { }

Mountain::Mountain(string name, string continent, int elevation) :
    name(name),
	continent(continent),
	elevation(elevation) { }

// Getters
string Mountain::getName() const
    { return name ; }
string Mountain::getContinent() const
    { return continent ; }
int Mountain::getElevation() const 
    { return elevation ; }

// Setters
void Mountain::setName(string name) 
    { this->name = name ; }
void Mountain::setContinent(string continent) 
    { this->continent = continent ; }
void Mountain::setElevation(int elevation) 
    { this->elevation = elevation ; }

// showInfo
void Mountain::showInfo() {
    cout << "Name: " << name << "  Continent: " << continent
         << "   Elevation: " << elevation << endl ;
}
