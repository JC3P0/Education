/* CircleDemo1.cpp - What happens when using the default copy constructor
 * Author:     Chris Merrill
 * Module:     5
 * Project:    Demonstration
 * Problem statement:  When using a default copy constructor, two objects
 *     inadvertantly can share the same piece of data.
 *
 * Algorithm:
 *    1. Create a Point structure with two doubles (representing the a point
 *       in an x-y plane) and a constructor
 *    2. Create a Circle structure with a Point object (representing the center
 *       of the circle in an x-y plane) and a double for the circle's radius
 *    3. Create a Circle object named "alpha" with a center at 8, 3 and a radius
 *       of 5
 *    4. Using an assignment statement, create a second Circle object named
 *       beta and assign to alpha
 *    5. Display the center point and radius of both alpha and beta
 *       -- They should look the same
 *    6. Change the center point of alpha to -2, 29
 *    7. Print the contents of both circles again -- they are both equal!
 *
 * Discussion:
 *     Two circles alpha and beta are created
 *     Alpha is created, then beta is created using the default constructor
 *        - only the pointer to the center for alpha is copied -- a new
 *          Point obbject SHOULD be created, but isn't
 *     In the show function, notice the use of -> (since "center" is a pointer)
 *        and . (since radius isn't pointers)
 *     Circle beta is called a "shallow" copy of Circle alpha, since they both
 *        share a pointer to a common object
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

    // Yikes!  Which one do we delete?
    delete alpha.center ;
    delete beta.center ;
}

// Show the important data for a Circle
void show(Circle &which, string name) {
    cout << "Information for Circle " << name << endl
         << "Center (x, y) = (" << which.center->x << ", " << which.center->y << ")"
         << "  Radius: " << which.radius << endl
         << "  Address of Center object: " << which.center << endl << endl ;
}
