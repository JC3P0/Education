#include "Laptop.h"
#include <iomanip>
using namespace std;
 
Laptop::Laptop() : Laptop(" ", " ", 0.0, 0.0, 0.0){
    m_id = 0;
}

Laptop::Laptop(string make, string model, double price, double batteryLife, double weight) : Computer(make, model, price){
    this->m_batteryLife = batteryLife;
    this->m_weight = weight;
}

double Laptop::getBatteryLife() const{
    return m_batteryLife;
}

double Laptop::getWeight() const{
    return m_weight;
}

void Laptop::setBatteryLife(double batteryLife){
    this-> m_batteryLife = batteryLife;
}

void Laptop::setWeight(double weight){
    this->m_weight = weight;
}

ostream& operator<<(ostream& out, const Laptop& t){
    return out << "|" << setw(6) << left << t.m_id << "|" << setw(7) << t.m_make << "|" << setw(15) << t.m_model << "|"  << setw(8) << t.m_price << "|" << setw(15) << left << t.m_batteryLife << "|" << setw(15) << left << t.m_weight << "|\n"; 
}

bool operator==(Laptop a, Laptop b){
    return ((a.m_batteryLife == b.m_batteryLife) && 
         (a.m_weight == b.m_weight) && 
         (a.m_make == b.m_make) &&
         (a.m_model == b.m_model) &&
         (a.m_price == b.m_price));
}