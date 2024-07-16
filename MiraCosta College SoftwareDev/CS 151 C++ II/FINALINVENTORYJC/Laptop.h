#ifndef UNTITLED32_LAPTOP_H
#define UNTITLED32_LAPTOP_H

#include <iostream>
#include "Computer.h"
using namespace std;

//derived from Computer using polymorphism
class Laptop : public Computer {
private:
    double weight;

public:
    Laptop();
    Laptop(int quantity, double price, string description, double model, double weight);
    class QuantityEmpty {}; //exception class
    // virtual int getSize(); //
    virtual void sell(int);
    virtual void add(int);
    double getWeight() const;
    int getId() const;
    void setWeight(double weight);
    friend ostream& operator<<(ostream& out, const Laptop& t);
};

Laptop::Laptop() : Laptop(0, 0.0, " ", 0.0, 0.0){}

Laptop::Laptop(int quantity, double price, string description, double model, double weight) :
Computer(quantity, price, description, model){
    this -> weight = weight;
}

void Laptop::sell(int amount){
    if(amount > InventoryItem::getQuantity()){
        throw QuantityEmpty(); //throw exception if amount to sell is greater than quantity
    }
    for (int i = 0; i < amount; i++){
        quantity--;  //lower quantity on sale
    }
}

void Laptop::add(int amount){
    for (int i = 0; i < amount; i++){
        quantity++; //add quantity when adding to inventory
    }
}

double Laptop::getWeight() const{
    return weight;
}

int Laptop::getId() const{
    return id;
}

void Laptop::setWeight(double weight){
    this -> weight = weight;
}
//overloaded << output object
ostream& operator<<(ostream& out, const Laptop& t){
    return out << "|" << setw(6) << left << t.id << "|" << setw(10) << t.quantity << "|" << setw(9) << t.price << "|"  << setw(22) << t.description << "|" << setw(10) << t.model << "|" << setw(9)<< t.weight << "|\n";
}

#endif //UNTITLED32_LAPTOP_H