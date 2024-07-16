#include "Line.h"
#include <iomanip>
#include <cmath>

//Line::Line():X1(0),Y1(0),X2(0),Y2(0){}

Line::Line(Point P1, Point P2){
    // this-> P1 = P1;
    // this-> P2 = P2;  
    this->X1 = P1.getX();
    this->X2 = P2.getX();
    this->Y1 = P1.getY();
    this->Y2 = P2.getY();
}

Line::Line(unsigned int X1, unsigned int Y1, unsigned int X2, unsigned int Y2){
    this-> X1 = X1;
    this-> Y1 = Y1;
    this-> X2 = X2;
    this-> Y2 = Y2;
}

const Point Line::getP1() const{
    return P1;   
}

const Point Line::getP2() const{
    return P2;   
}

unsigned int Line::getX1() const{
    return X1;   
}

unsigned int Line::getY1() const{
    return Y1;   
}

unsigned int Line::getX2() const{
    return X2;   
}

unsigned int Line::getY2() const{
    return Y2;   
}

double Line::getLength()const{
    double length;
    length = sqrt(pow(X2 - X1, 2) + pow(Y2 - Y1, 2));
    return length;
}

bool Line::setP1(const Point P1){
    this->P1 = P1;
    return true; 
}

bool Line::setP2(const Point P2){
    this->P2 = P2;
    return true; 
}

bool Line::setX1(unsigned int X1){
    this->X1 = X1;
    return true; 
}

bool Line::setY1(unsigned int Y1){
    this->Y1 = Y1;
    return true; 
}

bool Line::setX2(unsigned int X2){
    this->X2 = X2;
    return true; 
}

bool Line::setY2(unsigned int Y2){
    this->Y2 = Y2;
    return true; 
}

Line& Line::operator=(Line rhs){
    // Line result;
//    result.X1 = P1.getX();
//    result.X2 = P2.getX();
//    result.Y1 = P1.getY();
//    result.Y2 = P2.getY();
    this->X1 = rhs.getX1();
    this->Y1 = rhs.getY1();
    this->X2 = rhs.getX2();
    this->Y2 = rhs.getY2();
    return *this;
}

ostream& operator<<(ostream& out, const Line& t){
    
    return out << "Line [(x1=" << t.X1 << ",y1=" << t.Y1 << "), (x2=" << t.X2 << ",y2=" << t.Y2 << ")]\n";   
}

bool operator==(Line a, Line b){
    return (((a.X1 == b.X1) && (a.Y1 == b.Y1)) && 
            ((a.X2 == b.X2) && (a.Y2 == b.Y2)));  
}