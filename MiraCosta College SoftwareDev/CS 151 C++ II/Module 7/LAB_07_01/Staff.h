/* Staff.h - Header for staff members at MCC
 * Author:     <Josh Clemens>
 * Module:     7
 * Project:    Lab
 * Description:
 *
 *    Child of PersonAtMCC
 *
 *    Instance members:
 *       extension (string)
 *       hire_date (string)
 *       pay_rate (double)
 *
 *    Functions:
 *       full constructor
 *       getters and setters for extension, hire_date, and pay_rate
 *       showInfo
 */

#ifndef STAFF_H
#define STAFF_H

#include "PersonAtMCC.h"
using namespace std;

class Staff : public PersonAtMCC  {          /*** MAKE A CHILD OF PERSONATMCC WITH PUBLIC ACCESS ***/
    private :
        string extension;
        string hire_date;
        double pay_rate;

    public :
        Staff(); //default
        Staff(long long, string, string, string, string, string, double);         // full constructor

        string getExtension() const;                       // all getters and setters
        void setExtension(string);
        string getHireDate() const;
        void setHireDate(string);
        double getPayRate() const;
        void setPayRate(double);

        void showInfo();
};

#endif