#include "Point.h"
#include <iomanip>
#include <cmath>

Point::Point() : Point(0, 0){}

Point::Point(unsigned int x, unsigned int y){
        this-> x = x;
        this-> y = y;
}

unsigned int Point::getX() const{
    return x;   
}

unsigned int Point::getY() const{
    return y;   
}

double Point::distanceTo(const Point& other) const{
    // const double x_diff = this->x - other.getX(); //getX()
    // const double y_diff = this->y - other.getY(); //getY()
    // return sqrt(x_diff * x_diff + y_diff * y_diff);

    // return sqrt(pow(x.first - y.first, 2) +
                // pow(x.second - y.second, 2));
    return sqrt(pow(other.getX() - this->x, 2) +
                pow(other.getY() - this->y, 2) * 1.0);
}
    
bool Point::setX(unsigned int x){
    this->x = x;
    return true; 
}

bool Point::setY(unsigned int y){
    this->y = y;
    return true; 
}

Point& Point::operator=(Point rhs){
    // Point result;
    this->x = rhs.x;
    this->y = rhs.y;
    return *this;
}

ostream& operator<<(ostream& out, const Point& t){
    
    return out << "Point [x=" << t.x << ",y=" << t.y << "]\n";   
}

bool operator==(Point a, Point b){
    return ((a.x == b.x) &&
            (a.y == b.y));  
}