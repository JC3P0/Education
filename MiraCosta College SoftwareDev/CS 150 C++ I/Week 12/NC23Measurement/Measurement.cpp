#include "Measurement.h"
using namespace std;

Measurement::Measurement(){}
        
Measurement::Measurement(unsigned int feet, unsigned int inches){}
        
unsigned int Measurement::getFeet() const {
    return 0;
}
        
unsigned int Measurement::getInches() const{
     return 0;   
}
        
bool Measurement::setFeet(unsigned int feet){
    return false;
}
        
bool Measurement::setInches(unsigned int inches){
    return false;
}
        
void Measurement::operator++(int){}

void Measurement::operator--(int){}
        
Measurement Measurement::operator+(Measurement rhs){
    return *this;
}
        
Measurement Measurement::operator-(Measurement rhs) {
    return *this;
}
        
ostream& operator<<(ostream& out, const Measurement& t){
    return out;
}
        
bool operator==(Measurement a, Measurement b){
    return false;
}

