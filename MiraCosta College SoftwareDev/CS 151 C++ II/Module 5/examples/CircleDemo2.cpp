/* CircleDemo2.cpp - Add an appropriate copy constructor to Circle1Demo
 * Author:     Chris Merrill
 * Module:     5
 * Project:    Demonstration
 * Problem statement:  Change the CircleDemo1 program to have a programmer-defined
 *     copy constructor
 *
 * Algorithm (almost the same as CircleDemo1)
 *    1. Create a Point structure with two doubles (representing the a point
 *       in an x-y plane) and a constructor
 *    2. Create a Circle structure with a Point object (representing the center
 *       of the circle in an x-y plane) and a double for the circle's radius
 *       -- Difference:  This time also provide a copy constructor which creates
 *          a new center point
 *    3. Create a Circle object named "alpha" with a center at 8, 3 and a radius
 *       of 5
 *    4. Using an assignment statement, create a second Circle object named
 *       beta and assign to alpha
 *    5. Display the center point and radius of both alpha and beta
 *       -- They should look the same
 *    6. Change the center point of alpha to -2, 29
 *    7. Print the contents of both circles again -- this time they are different!
 *
 * Discussion:
 *    - The copy constructor takes a constant reference to another Circle
 *    - It also makes a new center Point
 *    - In this case, Circle beta is called a "deep" copy of alpha, since they
 *        do not share any pointers to common objects
 *    - To be REALLY safe, should the constructor for Circle also make a copy
 *      of the center point?
 *       ?? Would that eliminate the need for a copy constructor?
 */

#include <iostream>
using namespace std ;

// A Structure of a x-y point in a two-dimensional plane
struct Point {
    double x ;              // the x-coordinate
    double y ;              // the y-coordinate
    Point(double x, double y) {
        this->x = x ;
        this->y = y ;
    }
} ;

// A Circle that has a radius and a Point
struct Circle {
    Point *center ;
    double radius ;
    Circle(Point *newCenter, double newRadius) {
        center = newCenter ;
        radius = newRadius ;
    }

    // Here's the new copy constructor
    Circle(const Circle &another) {
        radius = another.radius ;
        double newX = another.center->x ;
        double newY = another.center->y ;
        center = new Point(newX, newY) ;       // should put in heap, not stack!
    }
} ;

// Prototypes
void show(Circle &, string) ;

int main() {

    // Create a point at (8, 3), then create a circle with radius 5 using that
    // Point as its center
    Circle alpha = Circle(new Point(8, 3), 5) ;

    // Use the default constructor to make a memberwise copy of Circle alpha
    Circle beta = alpha ;

    show(alpha, "alpha") ;
    show(beta, "beta") ;

    // Change the center point for alpha
    cout << "Changing the center for alpha to (-2, 29)" << endl << endl ;
    alpha.center->x = -2 ;
    alpha.center->y = 29 ;

    // Show what happens to both circles again!
    show(alpha, "alpha") ;
    show(beta, "beta") ;

    // Much better.
    delete alpha.center ;
    delete beta.center ;

    return 0 ;
}

// Show the important data for a Circle
void show(Circle &which, string name) {
    cout << "Information for Circle " << name << endl
         << "Center (x, y) = (" << which.center->x << ", " << which.center->y << ")"
         << "  Radius: " << which.radius << endl
         << "  Address of Center object: " << which.center << endl << endl ;
}
