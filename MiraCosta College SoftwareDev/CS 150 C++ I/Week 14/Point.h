#ifndef POINT_H
#define POINT_H

#include <iostream>
using namespace std;

class Point{
private:
unsigned int x;
unsigned int y;

public:
    Point();
    Point(unsigned int x, unsigned int y);
    unsigned int getX() const;
    unsigned int getY() const;
    double distanceTo(const Point & other) const;
    bool setX(unsigned int X);
    bool setY(unsigned int Y);
    Point& operator=(Point rhs);
    friend ostream& operator<<(ostream& out, const Point& t);
    friend bool operator==(Point a, Point b);
};

#endif