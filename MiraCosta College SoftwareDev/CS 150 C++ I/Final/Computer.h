#ifndef COMPUTER_H
#define COMPUTER_H

#include <iostream>
using namespace std;

class Computer{
    protected:
        int m_id;
        string m_make;
        string m_model;
        double m_price;
        static int s_nextId;

    public:
        Computer();
        Computer(string make, string model, double price);
        int getId() const;
        string getMake() const;
        string getModel() const;
        double getPrice() const;
        void setMake(string m_make);
        void setModel(string m_model);
        void setPrice(double m_price);
        friend ostream& operator<<(ostream& out, const Computer& t);
        friend bool operator==(Computer a, Computer b);
};

#endif