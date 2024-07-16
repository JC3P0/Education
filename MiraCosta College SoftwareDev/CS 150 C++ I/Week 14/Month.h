#ifndef MONTH_H
#define MONTH_H

#include <iostream>
using namespace std;

class Month{
private:
    string name;
    int month;
    
public:
    Month();
    Month(string name, int month);
    string getName() const;
    int getNumber() const;
    void setName(int month);
    void setNumber(int month);
    void operator++(int);
    void operator--(int);
    Month& operator=(Month rhs);
    friend ostream& operator<<(ostream& out, const Month& t);
    friend bool operator==(Month a, Month b);
};
  
#endif







