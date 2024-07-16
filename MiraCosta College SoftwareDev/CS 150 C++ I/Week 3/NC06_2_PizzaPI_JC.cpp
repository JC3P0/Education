/*______________________
* AUTHOR: <Josh Clemens>
* COURSE: CS 150: C++ Programming 1
* NC (PROJECT)#: <NC06_2>
* LAST MODIFIED: <02/12/22>
*_________
* PizzaPi
*_____________________
* PROGRAM DESCRIPTION:
* Calculate the number of slices a pizza of any size can be divided into. 
*___________
* ALGORITHM:
* CONSTANTS SLICE_AREA, SLICES_PER_PERSON
* PROMPTS Diameter, numPeople
* CALCULATE totalSlicesNeeded = numPeople * SLICES_PER_PERSON
* CALCULATE slicesPerPizza = area/SLICE_AREA
* CALCULATE area = M_PI * pow((diameter/2.0),2)
* CALCULATE slicesPerPizza = area/SLICE_AREA
* CALCULATE totalPizzas = ceil(totalSlicesNeeded / slicesPerPizza)
* OUTPUT slicesPerPizza, totalPizzas
*____________________________________________
* ALL IMPORTED LIBRARIES NEEDED AND PURPOSE:
* <cstdlib> Provides standard functions, including dynamic memory management,
* random number generation, communication with the environment,
* integer arithmetics, searching, sorting and converting.
* <iostream> Used for console input and output (cin and cout)
* <iomanip> update cout fixed setprecision(1)
* <cmath> for pow and processing M_PI
*____________________________________________*/

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(int argc, char *argv[])
{

    /***** CONSTANT SECTION *****/
    
    const double SLICE_AREA = 14.125;
    const double SLICES_PER_PERSON = 2.5;
       
    /***** DECLARATION SECTION *****/

    double diameter;
    int numPeople;
    
    /***** INITIALIZATION SECTION *****/
    //no init.
      
    /***** INTRO SECTION *****/
    //no intro
    
    /***** INPUT SECTION *****/
    
    cout << "What is the diameter of the pizza inches? ";
    cin >> diameter;
    cout << "How many people are coming to the party? ";
    cin >> numPeople;
    
    /***** PROCESSING SECTION *****/

    double totalSlicesNeeded = numPeople * SLICES_PER_PERSON;
    double area = M_PI * pow((diameter/2.0),2);
    double slicesPerPizza = area/SLICE_AREA;
    int totalPizzas = ceil(totalSlicesNeeded / slicesPerPizza); //to round up
    
    /***** OUTPUT SECTION *****/

    cout << fixed << setprecision(1);
    cout << "Each pizza has " << slicesPerPizza 
         << " slices and you will need " << totalPizzas 
         << " pizzas for your party." << endl;
    

    // system("PAUSE"); //for DevC++ on windows
    return EXIT_SUCCESS;

}