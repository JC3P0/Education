/*____________________
* AUTHOR: Josh Clemens
* COURSE: CS 150: C++ Programming 1
* NC (PROJECT)#: NC_21_02
* LAST MODIFIED: April 16, 2022
*_______________
* Student Budget
*_____________________
* PROGRAM DESCRIPTION:
* This program uses one structure to store expense categories. Two variables will be stored; the target values, and the other (user's input). Two functions will then process and display a report showing the amounts under or over for each category, and the over/ under for the months total. 
*___________
* ALGORITHM:
* INITIALIZE budget structure
* PROMPT users budget per structure categories
* CALCULATE is user's budget is lower or over the initialized budget
* CALCULATE the total budget for both user and initialzed structures
* OUTPUT over or under per structure catergory and total budgets
*___________________________________________
* ALL IMPORTED LIBRARIES NEEDED AND PURPOSE:
* <cstdlib> Provides standard functions, including dynamic memory management,
* random number generation, communication with the environment,
* integer arithmetics, searching, sorting and converting.
* <iostream> Used for console input and output (cin and cout).
* <iomanip> setprecision(2)
*____________________________________________*/

#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

struct MonthlyBudget {
    double housing;
    double utilities;
    double houseExpenses;
    double transport;
    double food;
    double medical;
    double insurance;
    double entertainment;
    double clothing;
    double misc;

    //default constructor, needed since all-args constructor
    //was created, leverage that
    MonthlyBudget() {
        MonthlyBudget(0,0,0,0,0,0,0,0,0,0);
    }
    //all-args constructor
    MonthlyBudget(double h, double u, double o, double t, double f, double m, double i, double e, double c, double s) {
        housing = h;
        utilities = u;
        houseExpenses = o;
        transport = t;
        food = f;
        medical = m;
        insurance = i;
        entertainment = e;
        clothing = c;
        misc = s;
    }
};

//function prototypes
void displayBudget(const MonthlyBudget &budget, const MonthlyBudget &expenses);
void outputCategory(string category, double budget, double expense);

int main(int argc, char* argv[]) {

    /***** CONSTANT SECTION *****/
    //no const.
 
    /***** DECLARATION SECTION *****/ 

    MonthlyBudget expenses;
    
    /***** INITIALIZATION SECTION *****/

    MonthlyBudget budget (500, 150, 65, 50, 250, 30, 100, 150, 75, 50);
    double goalBudget = (500 + 150 + 65 + 50 + 250 + 30 + 100 + 150 + 75 + 50);
    double countBudget = 0;
    
    /***** INTRO SECTION *****/

    cout << "Welcome to the student budget planner.\n";
     
    /***** INPUT SECTION *****/

    cout << "\nLet's see how your budget worked out for the month.\n";

    cout << "\nEnter your housing costs: ";
    cin >> expenses.housing;
    countBudget += expenses.housing;

    cout << "Enter your utilities cost: ";
    cin >> expenses.utilities;
    countBudget += expenses.utilities;

    cout << "Enter your household expenses costs: ";
    cin >> expenses.houseExpenses;
    countBudget += expenses.houseExpenses;

    cout << "Enter your transport cost: ";
    cin >> expenses.transport;
    countBudget += expenses.transport;
    
    cout << "Enter your food costs: ";
    cin >> expenses.food;
    countBudget += expenses.food;

    cout << "Enter your medical cost: ";
    cin >> expenses.medical;
    countBudget += expenses.medical;
    
    cout << "Enter your insurance costs: ";
    cin >> expenses.insurance;
    countBudget += expenses.insurance;

    cout << "Enter your entertainment cost: ";
    cin >> expenses.entertainment;
    countBudget += expenses.entertainment;
    
    cout << "Enter your clothing costs: ";
    cin >> expenses.clothing;
    countBudget += expenses.clothing;

    cout << "Enter your misc. cost: ";
    cin >> expenses.misc;
    countBudget += expenses.misc;
    
    cout << endl;
    
    /***** PROCESSING SECTION *****/ /***** OUTPUT SECTION *****/
    
    displayBudget(budget, expenses);

    if (countBudget > goalBudget){
        countBudget -= goalBudget;
        cout << "\nYou spent $" << countBudget << " over budget ($" << goalBudget << ") for the entire month.\n";
    }
    else if (countBudget < goalBudget){
        countBudget -= goalBudget;
        countBudget *= -1; // converts negative to positive 
        cout << "\nYou saved $" << countBudget << " under budget ($" << goalBudget << ") for the entire month.\n";
    }
       
    // system("PAUSE"); //for DevC++ on windows
    return EXIT_SUCCESS;
}

    /***** Function Definitions *****/

void displayBudget(const MonthlyBudget &budget, const MonthlyBudget &expenses) {
    outputCategory("housing", budget.housing, expenses.housing);
    outputCategory("utilities", budget.utilities, expenses.utilities);
    outputCategory("houseExpenses", budget.houseExpenses, expenses.houseExpenses);
    outputCategory("transport", budget.transport, expenses.transport);
    outputCategory("food", budget.food, expenses.food);
    outputCategory("medical", budget.medical, expenses.medical);
    outputCategory("insurance", budget.insurance, expenses.insurance);
    outputCategory("entertainment", budget.entertainment, expenses.entertainment);
    outputCategory("clothing", budget.clothing, expenses.clothing);
    outputCategory("misc", budget.misc, expenses.misc);

}

void outputCategory(string category, double budget, double expense) {
    string spendState;
    string spent;
    if (budget >= expense) {
        spendState = "under";
        spent = "saved";
    } else  {
        spendState = "over";
        spent = "spent";
    }
    cout << fixed << setprecision(2);
    cout << "You " << spent << " $" << abs(budget - expense) 
        << " " << spendState << " budget on " << category << "." << endl; 
}





