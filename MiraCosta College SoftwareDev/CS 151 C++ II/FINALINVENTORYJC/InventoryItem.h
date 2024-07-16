#ifndef UNTITLED32_INVENTORYITEM_H
#define UNTITLED32_INVENTORYITEM_H

#include <cstdlib>
#include <string>
using namespace std;

//abstract class
class InventoryItem {
protected:
    static int totalInventory;
    static int lastId;
    int id;
    int quantity;
    double price;
    string description;

public:
    InventoryItem();
    InventoryItem(int quantity, double price, string description);
    ~InventoryItem();
    // virtual int getSize() = 0;
    virtual void sell(int) = 0; //sell items
    virtual void add(int) = 0; //add items to inventory
    int getQuantity() const;
    double getPrice() const;
    string getDescription() const;
    void setQuantity(int quantity);
    void setPrice(double price);
    void setDescription(string description);
    //calc total sales
};

int InventoryItem::totalInventory = 0;
int InventoryItem::lastId = 10001;

//default constructor
InventoryItem::InventoryItem() {
    id = 0;
    quantity = 0;
    price = 0;
    description = " ";
}

//parametrized constructor
InventoryItem::InventoryItem(int quantity, double price, string description){
    this -> quantity = quantity;
    this -> price = price;
    this -> description = description;
    id = lastId++; //create unique id on new object
    totalInventory++; //keep track of items entered into inventory
}

//de-constructor
InventoryItem::~InventoryItem(){
    totalInventory--;
}

//getters
int InventoryItem::getQuantity() const{
    return quantity;
}

double InventoryItem::getPrice() const{
    return price;
}

string InventoryItem::getDescription() const{
    return description;
}

//setters
void InventoryItem::setQuantity(int quantity){
    this -> quantity = quantity;
}

void InventoryItem::setPrice(double price){
    this -> price = price;
}

void InventoryItem::setDescription(string description){
    this -> description = description;
}

#endif //UNTITLED32_INVENTORYITEM_H