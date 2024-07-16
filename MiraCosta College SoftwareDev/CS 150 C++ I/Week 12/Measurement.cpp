#include "Measurement.h"
using namespace std;

Measurement::Measurement() : Measurement(0, 0){}
        
Measurement::Measurement(unsigned int feet, unsigned int inches){
    this->feet = feet;
    while(inches >= 12){//to display correct initialzed inches(over 12)
        inches -= 12;
        this->feet += 1;
    }
    this->inches = inches;
}
        
unsigned int Measurement::getFeet() const {
    return feet;
}
        
unsigned int Measurement::getInches() const{
     return inches;   
}
        
bool Measurement::setFeet(unsigned int feet){
    if (feet < 0){
        return false;
    }
    this->feet = feet;
    return true;
}
        
bool Measurement::setInches(unsigned int inches){
    if (inches < 0){
        return false;    
    }
    this->inches = inches;
    return true;
}
        
void Measurement::operator++(int){
    bool incrementFeet = false;
    while(inches >= 12){
        inches -= 12;
        this->feet += 1;
    }
    if(inches == 11){
        setInches(0);
        this->feet += 1;
        incrementFeet = true;
    }else{
        setInches(getInches()+1);
    }    
}

void Measurement::operator--(int){
    bool decrementFeet = false;
    while(inches >= 12){
        inches -= 12;
        this->feet += 1;
    }
    if(inches == 0){
        setInches(11);
        this->feet -= 1;
        decrementFeet = true;
    }else{
        setInches(getInches()-1);
    }
}

Measurement Measurement::operator+(Measurement rhs) {
    Measurement result;
    result.inches = this->inches + rhs.inches;
    result.feet = this->feet + rhs.feet;
    return result;
}
        
Measurement Measurement::operator-(Measurement rhs) {
    Measurement result;
    result.inches = this->inches - rhs.inches;
    result.feet = this->feet - rhs.feet;
    return result;
}
        
ostream& operator<<(ostream& out, const Measurement& t){
    string strFeet = " feet";
    string strInch = " inches";

    return out << "Measurement [" << t.feet << strFeet << ", " << t.inches << strInch << "]";  
}
        
bool operator==(Measurement a, Measurement b){
    return ((a.feet == b.feet) &&
         (a.inches == b.inches));
}

