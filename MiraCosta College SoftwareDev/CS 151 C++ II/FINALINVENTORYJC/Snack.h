#ifndef UNTITLED32_SNACK_H
#define UNTITLED32_SNACK_H

#include <iostream>
#include "InventoryItem.h"

using namespace std;

class Snack : public InventoryItem {
private:
    string allergens;

public:
    Snack();
    Snack(int quantity, double price, string description, string allergens);
    class QuantityEmpty {}; //exception class
    // virtual int getSize();
    virtual void sell(int);
    virtual void add(int);
    string getAllergens() const;
    int getId() const;
    void setAllergens(string allergens);
    friend ostream& operator<<(ostream& out, const Snack& t);

};

Snack::Snack() : Snack(0, 0.0, " ", " "){
    allergens = " ";
}

Snack::Snack(int quantity, double price, string description, string allergens) :
        InventoryItem(quantity, price, description){
    this -> allergens = allergens;
}

void Snack::sell(int amount){
    if(amount > InventoryItem::getQuantity()){
        throw QuantityEmpty(); //throw exception if amount to sell is greater than quantity
    }
    for (int i = 0; i < amount; i++){
        quantity--; //lower quantity on sale
    }
}

void Snack::add(int amount){
    for (int i = 0; i < amount; i++){
        quantity++; //add quantity when adding to inventory
    }
}

string Snack::getAllergens() const{
    return allergens;
}

int Snack::getId() const{
    return id;
}

void Snack::setAllergens(string allergens){
    this -> allergens = allergens;
}
//overloaded << output object
ostream& operator<<(ostream& out, const Snack& t){
    return out << "|" << setw(6) << left << t.id << "|" << setw(10) << t.quantity << "|" << setw(9) << t.price << "|"  << setw(25) << t.description << "|"  << setw(17) << t.allergens << "|\n";
}

#endif //UNTITLED32_SNACK_H