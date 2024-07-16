/* Instructor.h - Header for an Instructor, child of PersonAtMCC
 * Author:     <Josh Clemens>
 * Module:     7
 * Project:    Lab, Part 1
 * Description:
 *
 *    Child of PersonAtMCC
 *
 *    Instance members:
 *       department(string)
 *       is_permanent (bool)
 *       pay_rate (double)
 *       hours (double)
 *
 *    Functions:
 *       full constructor
 *       getters and setters for all instance members
 *       showInfo
 */

#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include "PersonAtMCC.h"
using namespace std;

class Instructor : public PersonAtMCC {     /*** MAKE A CHILD OF PERSONATMCC WITH PUBLIC ACCESS ***/

    private:
        string department;
        bool is_permanent;
        double pay_rate;
        double hours;

    public :
        Instructor(); //default
        Instructor(long long, string, string, string, string, bool, double, double);     // full
        string getDepartment() const;                       // getters and setters
        void setDepartment(string);
        bool getIsPermanent() const;
        void setIsPermanent(bool);
        double getPayRate() const;
        void setPayRate(double);
        double getHours() const;
        void setHours(double);
        void showInfo();                              // show all info for this Instructor
} ;

#endif
