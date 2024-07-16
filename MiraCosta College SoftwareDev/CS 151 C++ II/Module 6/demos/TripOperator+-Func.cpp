/* TripOperator+-Func.cpp - Demonstrate overloading the + and - operators
 * Author:     Chris Merrill
 * Module:     6
 * Project:    Demonstration
 * Problem statement:  Create a Trip class which tracks the trip destination and
 *    total cost of several business trips made over the course of a year.  Create
 *    overloading functions which add or subtract the costs of two Trip objects, then
 *    return a new object with the result.
 *
 * Algorithm:
 *   1. Create a Trip class with two data members, a string describing the destination
 *      city and a double for the total cost of the trip
 *      1a.  Create constructor, and all getters and setters
 *      1b.  Also define overloaded + and - operators as friend functions to this class
 *   2. Outside the Trip class, define the overloaded + and - operators using a total
 *      of the costs, and a new description concatenating the two destinations
 *   3. In main
 *      3a.  Create four trip objects to various locations and costs
 *      3b.  Demonstrate the use of the + operator by adding two trips together and
 *           printing the result using  operator+()
 *      3c.  Do the same thing using the + operator
 *      3d.  Calculate a total of all trips using the + operator
 *      3e.  Subtract one of the trips from the total and display
 *      3f.  Subtract one trip from another using the operator-() and display the difference
 *      3g.  Do the same thing using the - operator
 *
 * Discussion:
 *    Addition and subtraction operators are separate functions (not members of Trip)
 *     -- must be declared as friends to access private members of Trip
 *    Both operators returns another Trip object, so can cascade three trips
 *    together such as trip1 + trip2 + trip3...
 */

#include <iostream>
#include <iomanip>
using namespace std ;

class Trip {

    private:
        string destination ;                // New York, Atlanta, and Catalina
        double cost ;                       // total cost of the trip

    public:
        Trip(string, double) ;              // constructor (not inline)

        string getDestination()             // getters and setters (all inline)
            { return destination ; }
        void setDestination(string new_destination)
            { destination = new_destination ; }
        double getCost()
            { return cost ; }
        void setCost(double new_cost)
            { cost = new_cost ;  }

        friend Trip operator+(Trip, Trip) ;  // Overloaded + in separate function
        friend Trip operator-(Trip, Trip) ;  // Overloaded - in separate function
} ;

// Constructor (member function)
Trip::Trip(string destination, double cost) {
    this->destination = destination ;
    this->cost = cost ;
}

// Overloaded + function (outside of class, so must be a friend to access private members)
Trip operator+(Trip dest1, Trip dest2) {
    double sum = dest1.cost + dest2.cost ;               // Don't need to use getCost()
    return Trip(dest1.destination + " and " + dest2.destination, sum) ;
}

// Overloaded - function
Trip operator-(Trip dest1, Trip dest2) {
    double difference = dest1.cost - dest2.cost ;
    return Trip(dest1.destination + " minus " + dest2.destination, difference) ;
}

int main() {

    // Create Trip objects for New York, Atlanta, Tokyo, and Fresno
    Trip new_york("New York", 3560.13) ;
    Trip atlanta("Atlanta", 2897.04) ;
    Trip tokyo("Tokyo", 5194.79) ;
    Trip fresno("Fresno", 1420.51) ;

    cout << fixed << setprecision(2) ;

    cout << "Trip to " << left << setw(10) << new_york.getDestination()
         << " cost $" << right << setw(8) << new_york.getCost() << endl
         << "Trip to " << left << setw(10) << atlanta.getDestination()
         << " cost $" << right << setw(8) << atlanta.getCost() << endl
         << "Trip to " << left << setw(10) << tokyo.getDestination()
         << " cost $" << right << setw(8) << tokyo.getCost() << endl
         << "Trip to " << left << setw(10) << fresno.getDestination()
         << " cost $" << right << setw(8) << fresno.getCost() << endl << endl ;

    // Calculate the total of two trip costs using operator+
    Trip sum = operator+(new_york, atlanta) ;
    cout << "Using operator+() function, " << sum.getDestination()
         << " total cost is $" << sum.getCost() << endl ;

    // Do the same thing using +
    cout << "Adding " << new_york.getDestination() << " to "
         << atlanta.getDestination() << " using +, the sum of costs is        $"
         << (new_york + atlanta).getCost() << endl << endl ;

    // Calculate the costs of all trips
    Trip all = new_york + atlanta + tokyo + fresno ;
    all.setDestination("All trips") ;
    cout << "Costs for all trips: " << all.getCost() << endl << endl ;

    // Calculate the difference in trip costs using operator-
    // (The international trip was an optional expense)
    Trip difference = operator-(all, tokyo) ;
    cout << "Using operator-() function " << difference.getDestination()
         << " costs $" << difference.getCost() << endl << endl ;

    difference = tokyo - new_york ;
    cout << difference.getDestination() << " cost $" << difference.getCost() << endl << endl ;

    return 0 ;
}
