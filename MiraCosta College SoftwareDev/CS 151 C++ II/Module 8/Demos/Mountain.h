/* Mountain.h - Describes the highest peak on a continent
 * Author:     Chris Merrill
 * Module:     8
 * Project:    Demonstration
 * Description:
 *
 *   Instance variables:
 *       name - name of the mountain
 *       continent - continent with the mountain
 *       peak - elevation of highest point on the mountain
 *
 *   Functions
 *       no-arg and full constructor
 *       getters and setters
 *       toString
 */

#ifndef MOUNTAIN_H
#define MOUNTAIN_H

#include <string>
using namespace std ;

class Mountain {

    private:
        string name ;
        string continent ;
        int elevation ;

    public:
        Mountain() ;
        Mountain(string, string, int) ;
        string getName() const ;
        string getContinent() const ;
        int getElevation() const ;
        void setName(string) ;
        void setContinent(string) ;
        void setElevation(int) ;
        void showInfo() ;
} ;

#endif
