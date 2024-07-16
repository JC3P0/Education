//#ifndef LINE_H
//#define LINE_H
#pragma once
#include "Point.h"
#include <iostream>
using namespace std;

class Line{
private:
Point P1;
Point P2;
unsigned int X1;
unsigned int Y1;
unsigned int X2;
unsigned int Y2;

public:
 //   Line();
    Line(Point P1, Point P2);
    Line(unsigned int X1, unsigned int Y1, unsigned int X2, unsigned int Y2);
    const Point getP1() const;
    const Point getP2() const;
    unsigned int getX1() const;
    unsigned int getY1() const;
    unsigned int getX2() const;
    unsigned int getY2() const;
    double getLength()const;
    bool setP1(Point P1);
    bool setP2(Point P2);
    bool setX1(unsigned int X1);
    bool setY1(unsigned int Y1);
    bool setX2(unsigned int X2);
    bool setY2(unsigned int Y2);
    Line& operator=(Line rhs);
    friend ostream& operator<<(ostream& out, const Line& t);
    friend bool operator==(Line a, Line b);
};
    
//#endif