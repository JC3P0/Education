//time
#include <iostream>
#include "Time.h"
using namespace std;


int main() {
    cout << "Hello World!\n";
    Time t1;
    cout << t1 << endl;
    t1--;
    cout << t1 << endl;
    t1++;
    cout << t1 << endl;
    Time t2;

    if (t1 == t2) {
        cout << "(Expected)Times objects are equal" << endl;
    } else {
        cout << "Times objects are NOT equal" << endl;
    }
    t2++;
    cout << t2 << endl;
    if (t1 == t2) {
        cout << "Times objects are equal" << endl;
    } else {
        cout << "(Expected)Times objects are NOT equal" << endl;
    }
    
    
    return EXIT_SUCCESS;
}