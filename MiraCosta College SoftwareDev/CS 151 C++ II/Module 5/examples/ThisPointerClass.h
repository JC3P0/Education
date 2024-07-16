/* ThisPointerClass.h - Header for class to demonstrate use of "this" pointer
 * Author:     Chris Merrill
 * Module:     5
 * Project:    Demonstration
 * Description:  Describes the ThisPointerClass class, including three
 *   instance variables and prototypes for 2 constructors and two other functions.
 */

#ifndef THIS_POINTER_CLASS_H
#define THIS_POINTER_CLASS_H

using namespace std ;

class ThisPointerClass {

    private:
        int x, y, z ;

    public:
        void set(int, int, int) ;
        void print() const ;

        ThisPointerClass updateXYZ() ;
        ThisPointerClass(int a = 0, int b = 0, int c = 0) ;     // default values

} ;

#endif


