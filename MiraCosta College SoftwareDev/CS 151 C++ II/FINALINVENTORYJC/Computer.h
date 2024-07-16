#ifndef UNTITLED32_COMPUTER_H
#define UNTITLED32_COMPUTER_H

#include <cstdlib>
#include <iostream>
#include "InventoryItem.h"

using namespace std;
//derived from InventoryItem
class Computer : public InventoryItem {
protected:
    double model;

public:
    Computer();
    Computer(int quantity, double price, string description, double model);
    class QuantityEmpty {}; //exception class
    // virtual int getSize();
    virtual void sell(int);
    virtual void add(int);
    double getModel() const;
    int getId() const;
    void setModel(double model);
    friend ostream& operator<<(ostream& out, const Computer& t);

};

Computer::Computer() : Computer(0, 0.0, " ", 0.0){
    model = 0;
}

Computer::Computer(int quantity, double price, string description, double model) :
InventoryItem(quantity, price, description){
    this -> model = model;
}

void Computer::sell(int amount){
    if(amount > InventoryItem::getQuantity()){
        throw QuantityEmpty(); //throw exception if amount to sell is greater than quantity
    }
    for (int i = 0; i < amount; i++){
        quantity--; //lower quantity on sale
    }
}

void Computer::add(int amount){
    for (int i = 0; i < amount; i++){
        quantity++; //add quantity when adding to inventory
    }
}

double Computer::getModel() const{
    return model;
}

int Computer::getId() const{
    return id;
}

void Computer::setModel(double model){
    this->model = model;
}
//overloaded << output object
ostream& operator<<(ostream& out, const Computer& t){
    return out << "|" << setw(6) << left << t.id << "|" << setw(10) << t.quantity << "|" << setw(9) << t.price << "|"  << setw(22) << t.description << "|"  << setw(10) << t.model << "|N\\A      |\n";
}

#endif //UNTITLED32_COMPUTER_H