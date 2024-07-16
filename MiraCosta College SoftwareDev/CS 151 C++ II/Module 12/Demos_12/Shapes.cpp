/* Shapes.cpp - Create an abstract class Shape which serves as an interface
 * Author:     Chris Merrill
 * Module:     12
 * Project:    Demonstration
 * Problem statement:  Create an abstract class (interface) Shape with three
 *   pure virtual (abstract) functions:
 *
 *                      double getArea() const
 *                      double getPerimiter() const
 *                      void show() const
 *
 * Algorithm:
 *  1. Create a Shape class with a constructor, instance data member,
 *     getter, and setter -- just like any other class
 *     1a. In addition, it has the three virtual functions above which
 *         make it act as an "interface"
 *  2. Create Rectangle and Circle classes children of Shape
 *     2a. Rectangle has length and width data members
 *     2b. Circle has a radius data members
 *  3. Create Square class child of Rectangle
 *     3a. Constructortakes one variable for side, sets height and width
 *         in parent
 *  4. In main:
 *     4a. Create an array of Shapes (abstract), then add two Rectangles,
 *         two Squares, and two Circles.
 *     4b. Use for-each loop to display information for each object in
 *         the array.
 *
 * Discussion:
 *    - If we wanted to create a Triangle class, we have the framework from Shape.
 *    - Notice use of "override" in all child classes to verify that the
 *      "show" function is indeed being overridden
 */

#include <iostream>
using namespace std ;

// Abstract base class (interface)
class Shape {

    protected:
        string name ;

    public:
         // pure virtual function providing interface framework.
        virtual double getArea() const = 0 ;
        virtual double getPerimiter() const = 0 ;
        virtual void show() const = 0 ;

        // Constructor, setter, and getter
        Shape(string name) : name(name) {} ;
        void setName(string n)
            { name = n ; }
        string getName()
            { return name ; }

        // constants
        const double PI = 3.14159265358979323846 ;
} ;

// Derived classes

// Concrete Rectangles have a length and width, calculate area and perimiter
class Rectangle: public Shape {

    protected:
        double width ;
        double length ;

    public:
        Rectangle(string name, double length, double width) :
            Shape(name),
            length(length),
            width(width) {} ;
        void setWidth(double w)
            { width = w ; }
        void setLength(double l)
            { length = l ; }
        double getArea() const override
            { return length * width ; }
        double getPerimiter() const override
            { return 2.0 * (length + width) ; }
        void show() const override {
            cout << name << "   length: " << length
                 << "   width: " << width
                 << "   area: " << getArea()
                 << "   perimiter: " << getPerimiter() << endl ;
    }
} ;

// Child of Rectangle, has a side, sets both height and width in parent to side
// Inherits getPerimiter and getArea
class Square : public Rectangle {
    public:
        Square(string name, double side) : Rectangle(name, side, side) {} ;
        void setSide(double s)
            { length = width = s ; }
        double getSide()
            { return length ; }
        void show() const override {
            cout << name << "   side: " << length
                 << "   area " << getArea()
                 << "   perimiter: " << getPerimiter() << endl ;
        }
} ;

// Concrete Circle class has a radius, calculates everything else
class Circle : public Shape {
    protected:
        double radius ;

    public:
        Circle(string name, double radius) :
            Shape(name),
            radius(radius) {} ;
        void setRadius(double r)
            { radius = r ; }
        double getArea() const override
            { return PI * radius * radius ; }
        double getPerimiter() const override
            { return 2.0 * PI * radius ; }
        void show() const override {
            cout << name << "   radius: " << radius
                 << "   area: " << getArea()
                 << "   perimiter: " << getPerimiter() << endl ;
        }
} ;

int main() {

    // Create two Rectangles, two Squares, and two Circles, then display info
    // Note that type of array is an abstract class, but the actual objects
    // must all be concrete.
    Shape *shapes[] = { new Rectangle("Rectangle 1", 20.2, 15.8),
                        new Rectangle("Rectangle 2", 8.7, 132.4),
                        new Square("Square 1", 31.9),
                        new Square("Square 2", 63.2),
                        new Circle("Circle 1", 31.9),
                        new Circle("Circle 2", 63.2) } ;

    for (Shape *s : shapes) {
        s->show() ;
    }
    cout << endl ;

    return 0 ;
}

