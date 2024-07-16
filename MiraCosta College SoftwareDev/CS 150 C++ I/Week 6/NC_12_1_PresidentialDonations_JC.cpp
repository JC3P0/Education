/*______________________
* AUTHOR: <Josh Clemens>
* COURSE: CS 150: C++ Programming 1
* NC (PROJECT)#: NC12_1
* LAST MODIFIED: 03/04/22
*_______________________
* Presidential Donations
*_____________________
* PROGRAM DESCRIPTION:
* Opens files from 2020 election donations per Oceanside area code. Calculates the average donation, smallest and largest donations per file.
*___________
* ALGORITHM:
* READ numbers from two files
* CALCULATE largest, lowest, and average from each file
* OUTPUT largest, lowest and average numbers from each file
*____________________________________________
* ALL IMPORTED LIBRARIES NEEDED AND PURPOSE:
* <cstdlib> Provides standard functions, including dynamic memory management,
* random number generation, communication with the environment,
* integer arithmetics, searching, sorting and converting.
* <iostream> Used for console input and output (cin and cout).
* <iomanip> Used for setprecision.
* <fstream> to open and read files
*____________________________________________*/

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
int main(int argc, char *argv[]) 
{
    /***** CONSTANT SECTION *****/
    //no constant
 
    /***** DECLARATION SECTION *****/

    ifstream inFileD;
    ifstream inFileJ;
    double inputD;
    double inputJ;
    double avg;
    
    /***** INITIALIZATION SECTION *****/

    double smallD = 0;
    double largestD = 0;
    double small = 0;
    double largest = 0;
    double totalD = 0;
    double countD = 0;
    double total = 0;
    double count = 0;
    inFileD.open("trump2020donation_simple-1.txt");
    inFileJ.open("biden2020donation_simple-1.txt");
 
    /***** INTRO SECTION *****/ 

    cout << "Donation Figures for 2020 Presidental Election!@\n";
    cout << endl; 

    /***** INPUT SECTION *****/
    
    inFileD >> inputD;
    inFileJ >> inputJ;

    /***** PROCESSING SECTION *****/ /***** OUTPUT SECTION *****/
    
    do 
    {
        if (inputD > largestD)
        {
            largestD = inputD;
        }
        else if (inputD < smallD)
        {
            smallD = inputD;
        }
    countD++;
    totalD += inputD;
    }while (inFileD >> inputD);
    avg = totalD / countD;
    cout << fixed << setprecision(2);
    cout << "Donald Trump" << endl;
    cout << "Average Donation: $" << avg << " Smallest: $" << smallD << " Largest: $" << largestD << endl; 
    //testing    cout << "total " << totalD << " count " << countD << endl;
    cout << endl;

    do 
    {
        if (inputJ > largest)
        {
            largest = inputJ;
        }
        else if (inputJ < small)
        {
            small = inputJ;
        }
    count++;
    total += inputJ;
    }while (inFileJ >> inputJ);
    
    avg = total / count;
    cout << fixed << setprecision(2);
    cout << "Joe Biden" << endl;
    cout << "Average Donation: $" << avg << " Smallest: $" << small << " Largest: $" << largest << endl;
    //testing    cout << "total " << total << " count " << count << endl;
    
    // system("PAUSE"); //for DevC++ on windows
    return EXIT_SUCCESS;
}
