/* ReadCities.cpp - Use the geline() function to read file data into a char array.
 * Author:     Chris Merrill
 * Module:     9
 * Project:    Demonstration
 * Problem statement:  Use the getline() function to read cities from the 
 *    "city.txt" file using the '#' character as a delimiter.
 *
 * Algorithm:
 *   1. Open an input file named "city.txt" to an ifstream
 *      1a. If the file cannot be opened, print an error and stop
 *   2. Create an array of 40 chars named "city"
 *   3. Read the contents of the file up to the '#' character into
 *      the array
 *      3a. If already at the end of the file, close the file and stop
 *      3b. Print the name of the city just read
 *      3c. Go back to step 3.
 *   4. For the content of the city.txt file, use:
 *
 *             Sao Paulo#Mexico City#Lima#New York#Bogota#Rio de Janeiro
 *             Santiago#Los Angeles#Caracas#Buenos Aires#Salvador#Brasilia
 *             Toronto#Chicago#Fortaleza
 *
 *      (Note: These are the 15 largest cities in the Americas)
 *
 * Discussion:
 *    Use the version of the ifstream constructor that uses a single statement
 *    Notice that the getline function doesn't skip the new-line character before 
 *    a few of the city names.  How would we solve this?
 */

#include <iostream>
#include <fstream>
using namespace std ;

int main() {

    // Create stream object and open the "city.txt" file.  If file cannot be opened,
    // print an error message and leave.
    // (Use combined form of constructor for both declaration and definition
    ifstream input("city.txt") ;
    if (input.fail())   {
        cout << "File does not exist -- aborting program" << endl ;
        exit(1) ;
    }

    // Read characters to an array named "city" until it encounters the
    // delimiter, eof reached, or when 39 chars are read. Output the
    // city name to the screen
    char city[40] ;
    int city_number = 1 ;
    while (!input.eof())   {
        input.getline(city, 40, '#') ; // specifies # as the delimiter
        cout << "City: " << city_number++ << "  " << city << endl ;
    }

    input.close() ;
    cout << "Done" << endl ;

    return 0 ;
}

