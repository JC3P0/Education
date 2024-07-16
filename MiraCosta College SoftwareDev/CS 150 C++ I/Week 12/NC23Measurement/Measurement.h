#ifndef MEASUREMENT_H
#define MEASUREMENT_H

#include <iostream>
using namespace std;

class Measurement {
    private:
        unsigned int feet;
        unsigned int inches;
    public:
        Measurement();
        Measurement(unsigned int feet, unsigned int inches);
        unsigned int getFeet() const;
        unsigned int getInches() const;
        bool setFeet(unsigned int feet);
        bool setInches(unsigned int inches);
        void operator++(int);
        void operator--(int);
        Measurement operator+(Measurement rhs);
        Measurement operator-(Measurement rhs);
        friend ostream& operator<<(ostream& out, const Measurement& t);
        friend bool operator==(Measurement a, Measurement b);

};


#endif