#include "Computer.h"
#include <iomanip>
using namespace std;
int Computer::s_nextId = 100;

Computer::Computer() : Computer(" ", " ", 0.0){
    m_id = 0;
}

Computer::Computer(string make, string model, double price){
    this->m_id = s_nextId;
    this->m_make = make;
    this->m_model = model;
    this->m_price = price;
    s_nextId++;
}

int Computer::getId() const{
    return m_id;
}

string Computer::getMake() const{
    return m_make;
}

string Computer::getModel() const{
    return m_model;
}

double Computer::getPrice() const{
    return m_price;
}

void Computer::setMake(string make){
    this->m_make = make;
}

void Computer::setModel(string model){
    this->m_model = model;
}

void Computer::setPrice(double price){
    this->m_price = price;
}

ostream& operator<<(ostream& out, const Computer& t){
    return out << "|" << setw(6) << left << t.m_id << "|" << setw(7) << t.m_make << "|"  << setw(15) << t.m_model << "|"  << setw(8) << t.m_price << "|\n";
}

bool operator==(Computer a, Computer b){
    return ((a.m_make == b.m_make) &&
         (a.m_model == b.m_model) &&
         (a.m_price == b.m_price));
}
