#ifndef LAPTOP_H
#define LAPTOP_H

#include <iostream>
#include "Computer.h"
using namespace std;

class Laptop : public Computer {
    private:
        double m_batteryLife;
        double m_weight;

    public:
        Laptop();
        Laptop(string make, string model, double price, double batteryLife, double weight);
        double getBatteryLife() const;
        double getWeight() const;
        void setBatteryLife(double batteryLife);
        void setWeight(double weight);
        friend ostream& operator<<(ostream& out, const Laptop& t);
        friend bool operator==(Laptop a, Laptop b);
};

#endif