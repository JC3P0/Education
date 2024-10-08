/* PersonAtMCC.h - Header for parent class of Instructor, Student, and Staff
 * Author:     <Josh Clemens>
 * Module:     7
 * Project:    Lab, Part 1
 * Description:
 *
 *    Instance members
 *       id (string)
 *       name (string)
 *       address (string)
 *       phone (string)
 *
 *    Functions
 *       default constructor
 *       partial constructor (id & name)
 *       full constructor
 *       all getters and setters
 *       showinfo
 */

#ifndef PERSON_AT_MCC_H
#define PERSON_AT_MCC_H

#include <iostream>
using namespace std ;

class PersonAtMCC {

    private:
        long id;
        string name;
        string address;
        string phone;

    public :
        PersonAtMCC();                                    // default constructor
        PersonAtMCC(long long, string);                   // id and name
        PersonAtMCC(long long, string, string, string);   // full constructor

        long long getId() const;                                // all getters and setters
        void setId(long long);
        string getName() const;
        void setName(string);
        string getAddress() const;
        void setAddress(string);
        string getPhone() const;
        void setPhone(string);

        void showInfo();
} ;

#endif