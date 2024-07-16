/* CustomerSort.cpp - Create a sorted index of pointers into an array of Customer structures
 * Author:     <Josh Clemens>
 * Module:     10
 * Project:    Midterm Problem 3
 * Problem statement:  Create an array of 10 Customer structures, then create an array of
 *    pointers to those structures when traversed by index, will list the customers sorted
 *    by descending balance due (highest balance first).
 *
 */

#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std ;

struct Customer {
    string name ;
    double balance ;
    Customer (string inputName, double inputBalance){
        name = inputName;
        balance = inputBalance;
    }
    // <add a constructor>
} ;

bool compare( Customer a, Customer b){

	if(a.balance < b.balance){
        return 1;
    }
	else {
        return 0;
    }
		
}

int main() {

    // Create an array of 10 Customer objects in random order
    Customer data[] = {
        Customer("XYZ Company", 2043.51),
        Customer("Diddy Daddy", 5178.31),
        Customer("Everready", 29240.25),
        Customer("Washburn Ltd.", 13195.40),
        Customer("Joe Jackson", 1442.00),
        Customer("BubbleWorks", -295.40),
        Customer("Alex P. Jones", 6110.68),
        Customer("Sammy Sosa", 999.99),
        Customer("Timberworks", 17201.89),
        Customer("Microvision", 14040.71)
    } ;

    Customer* array = data;
    for (int i = 0; i < 10; i++){
        array[i].name = data[i].name;
        array[i].balance = data[i].balance;
    }

    // Create an array pData of pointers into the data array and initialize
    // so that pData[k] points to data[k]

    // Sort the pData array so that the Customer with the largest balance is
    // first, and the Customer with the smallest balance is last

    // Print the Customer structures in the order in which they appear in pData
    cout << "\nOriginal array\n";
    cout << "      Name          Balance" << endl
         << "----------------  -----------" << endl
         << fixed << setprecision(2) ;
    for (int i = 0; i < 10; i++){
        cout << left << setw(15) <<  data[i].name << right << setw(12) << data[i].balance << endl;
    }

    sort(array, array+10, compare);

    
    cout << "\nSorted pointer array\n";
    cout << "      Name          Balance" << endl
         << "----------------  -----------" << endl
         << fixed << setprecision(2) ;
    for (int i = 0; i < 10; i++){
        cout << left << setw(15) << array[i].name << right << setw(12) << array[i].balance << endl;
    }

}

