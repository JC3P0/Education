/*____________________
* AUTHOR: Josh Clemens
* COURSE: CS 150: C++ Programming 1
* (PROJECT)#: CS 150 Final Exam
* LAST MODIFIED: May 26, 2022
*___________
* Final Exam
*_____________________
* PROGRAM DESCRIPTION:
* Keeps an invintory of two classes; Computer is the base class, Laptop is the derived class. The program will assign and increment a uniue id number as computer and laptop objects are entered into their separate vectors.
*___________
* ALGORITHM:
* INIT & CONSTRUCT computer(make, model, price) base class and derived laptop(battery life, weight) class
* INITIALIZE input, counts, vector arrays(one computer other laptop)
* OUTPUT menu
* PROMPT add inv., display inv. or exit program
* SWITCH user input 
* PROMPT 1 enter 1 for computer and 2 for laptop
* INITIALIZE temp object with user input and store in either computer or laptop array with the temp object and push_back
* INITIALIZE unique incremented id for each input to be displayed with inv.
* PROMPT 2 display inv.
* PROMPT 3 exit program
*___________________________________________
* ALL IMPORTED LIBRARIES NEEDED AND PURPOSE:
* <cstdlib> Provides standard functions, including dynamic memory management,
* random number generation, communication with the environment,
* integer arithmetics, searching, sorting and converting.
* <iostream> Used for console input and output (cin and cout).
* <iomanip> setw()
* <vector> holds two arrays from separate classes
*____________________________________________*/

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <vector>
#include "Computer.h"
#include "Laptop.h"

using namespace std;

void menu();
void disInv();
void displayVector(vector<Computer>);
void displayVector(vector<Laptop>);

int main(int argc, char* argv[]) {

    /***** CONSTANT SECTION *****/
    //no const.
 
    /***** DECLARATION SECTION *****/ /***** INITIALIZATION SECTION *****/

    int input = 0;
    int countComp = 0;
    int countLap = 0;
    
    //Computer *arrComp = new Computer[countComp];
    //Laptop *arrLap = new Laptop[countLap];
    vector<Computer> arrayComp(countComp);
    vector<Laptop> arrayLap(countLap);

    // testing lines
    // Computer C1("Apple", "Pro", 1499);
    // Computer C2("Apple", "Pro", 1499);
    // Laptop L1("Dell", "XP", 799, 10, 3);
    // Laptop L2("Dell", "XP", 799, 10, 3);
    // cout << C1 << endl;
    // cout << C2 << endl;
    // cout << L1 << endl;
    // cout << L2 << endl;

    /***** INTRO SECTION *****/ /***** INPUT SECTION *****/ /***** PROCESSING SECTION *****/ /***** OUTPUT SECTION *****/

    do{
        menu();
        cout << "Enter option: ";
        cin >> input;
        cout << endl;
        
        switch (input){
            case 1:
                cout << "Enter 1 for Computer or 2 for Laptop >> ";               
                cin >> input;   
                    if (input == 1){
                        string make_temp = " "; //reset temp object items each loop
                        string model_temp = " ";
                        double price_temp = 0;
                        Computer comp = Computer(make_temp, model_temp, price_temp); // temp object to pass into computer array with user's input
                        cout << "\nEnter Make               >> ";
                        cin.ignore();
                        getline (cin, make_temp);
                        comp.setMake(make_temp);
                        cout << "Enter Model              >> ";
                        // cin.ignore();
                        getline (cin, model_temp);
                        comp.setModel(model_temp);
                        cout << "Enter Price              >> $";
                        cin >> price_temp;
                        comp.setPrice(price_temp);
                        // cout << comp; //testline
                        arrayComp.push_back(comp); //adds temp object into vector array to be stored
                        countComp++;
                    }
                    else if (input == 2){
                        string make_temp = " "; //reset temp object items each loop
                        string model_temp = " ";
                        double price_temp = 0;
                        double battery_temp = 0;
                        double weight_temp = 0;
                        Laptop lap = Laptop(make_temp, model_temp, price_temp, battery_temp, weight_temp); // temp object to pass into laptop array with user's input
                        cout << "\nEnter Make               >> ";
                        cin.ignore();
                        getline (cin, make_temp);
                        lap.setMake(make_temp);
                        cout << "Enter Model              >> ";
                        // cin.ignore();
                        getline (cin, model_temp);
                        lap.setModel(model_temp);
                        cout << "Enter Price              >> $";
                        cin >> price_temp;
                        lap.setPrice(price_temp);
                        cout << "Enter BatteryLife (hrs)  >> ";
                        cin >> battery_temp;                        
                        lap.setBatteryLife(battery_temp);                        
                        cout << "Enter Weight (lbs)       >> ";
                        cin >> weight_temp;
                        lap.setWeight(weight_temp);
                        // cout << lap; //testline
                        arrayLap.push_back(lap); //adds temp object into vector array to be stored
                        countLap++;
                    }
                cout << endl;
                cout << "Enter any key to continue. . .\n";
                cin.ignore(); //ignore next input(void next input for user to continue the program)
                cin.get(); //makes user enter any key to continue

                cout << endl;
                break;
            
            case 2:
                disInv();  
                displayVector(arrayComp);
                displayVector(arrayLap);
                cout << endl;
                cout << "Enter any key to continue. . .\n";
                cin.ignore(); //ignore next input(void next input for user to continue the program)
                cin.get(); //makes user enter any key to continue
                break;

        }
        
    }while (input != 3);

    cout << "That's a wrap! :)\n";

    // system("PAUSE"); //for DevC++ on windows
    return EXIT_SUCCESS;
}

    /***** Function Definitions *****/

void menu(){
    
cout	<< "*************************************************************************\n"
		<< "**                 Welcome to the Computer Depot                       **\n"
		<< "*************************************************************************\n"
		<< "** Please enter choice :                                               **\n"
		<< "** 1) Add computer to inventory                                        **\n"
		<< "** 2) Display entire inventory                                         **\n"
		<< "** 3) Quit                                                             **\n"
		<< "*************************************************************************\n";
}

void disInv(){
    
cout    << "*************************************************************************\n"
		<< "**                          Entire Inventory                           **\n"
		<< "*************************************************************************\n"
		<< "| Id # | Make  | Model         | Price  | Battery (hrs) | Weight (lbs)  |\n"
		<< "*************************************************************************\n";
}

 void displayVector(vector<Computer> arrayComp) {
     
    for (unsigned count = 0; count< arrayComp.size(); count ++){
        cout << arrayComp[count]; 
    }
} 

 void displayVector(vector<Laptop> arrayLap) {

    for (unsigned count = 0; count< arrayLap.size(); count ++){
        cout << arrayLap[count]; 
    }
} 