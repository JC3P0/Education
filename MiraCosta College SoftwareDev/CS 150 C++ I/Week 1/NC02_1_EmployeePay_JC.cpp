/****************************************************
* AUTHOR: Josh Clemens
* COURSE: CS 150: C++ Programming 1
* NC (CalculatingPaycheck)#: NC #02_1
* LAST MODIFIED: 01/29/2022
*****************************************************************************
* Calculating Paycheck
*****************************************************************************/

#include <iostream>
using namespace std;

int main() {
    //Declaration of Variables
    double payPeriodWages;
    int numberOfPayPeriods;
    double annualSalary;

    //Assignment Section
    payPeriodWages = 1070.69;
    numberOfPayPeriods = 26;

    //Introduction
    cout << "Annual Salary Calculation" << endl;

    //Processing Statements
    annualSalary = payPeriodWages * numberOfPayPeriods;

    //Output
    cout <<"Your Annnual Salary is $" << annualSalary << endl;

    return EXIT_SUCCESS;
}