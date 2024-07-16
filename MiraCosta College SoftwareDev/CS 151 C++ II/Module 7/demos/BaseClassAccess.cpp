/* BaseClassAccess.cpp - Demonstration of parent class access specifiers
 * Author:     Chris Merrill
 * Module:     7
 * Project:    Demonstration
 * Problem statement:  What happens to public, protected, and private members
 *    of a base class when using public, protected, and private base class
 *    specifiers?
 *
 * Algorithm:
 *   1.  In a "Top" class, create three variables, (public, protected, and private)
 *   2.  In a "Middle" class with parent "Top", try to access those variables
 *       with different  base class specifiers
 *   3.  In a "Bottom" class (with parent "Middle"), do the same
 *
 * Discussion:
 *   * Right away, the private variable z in Top is not accessible to lower classes
 *      - Comment out 'z' in Middle and Bottom classes
 *   * Initially base class access to Top is "public" by Middle
 *      - both the public and protected variables go through
 *   * Make access to Top "protected" by Middle
 *      - same thing (except x variable is now protected in Middle, not public)
 *   * Make access to Top "private" by Middle
 *      - now nothing goes through to Bottom
 *   * Make access to Top <default> (no modifier) by Middle
 *      - works the same as private
 *      - if no base class access modifier is present, the default is private
 *          -- similar to the default member access modifier
 */

#include <iostream>
using namespace std ;

class Top {
    public:    int x ;
    protected: int y ;
    private:   int z ;
} ;

class Middle : public Top {
    public :
        void alpha() {
            x++ ;              // public member
            y++ ;              // protected member
            z++ ;              // private member
        }
} ;

class Bottom : Middle {
    public :
        void beta() {
            x++ ;              // public member
            y++ ;              // protected member
            z++ ;              // private member
        }
} ;

int main() {

    return 0 ;
}
