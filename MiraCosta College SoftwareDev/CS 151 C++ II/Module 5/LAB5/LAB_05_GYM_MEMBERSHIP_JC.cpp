/*______________________________________
* FILE: LAB_05_GYM_MEMBERSHIP_JC
* AUTHOR: Josh Clemens
* MODULE: 5
* PROJECT: 1
* LAST MODIFIED: September 24, 2022
* PROBLEM STATEMENT: Use a Member struct to keep track of a GYMs visits, active members and create unique IDs for new memebers.
* ALGORITHM:
*     INITIALIZE Member class to create unique ID and increment for new memebers and decrement when members leave.
*     INITIALIZE customers to choose from basic and premium memberships.
*     DELETE a customer to test deconstructor and total active memebers after deleting .
*     CALCULATE generate random numbers to loop through each customer representing a visit each pass through the loop.
*     OUTPUT the customers IDs, names, membership types, visits and the GYMS total visits and active members.   
*______________________________________*/

#include <cstdlib>
#include <iostream>
#include <iomanip> //set precision 2, setw()
#include <vector>
#include <ctime> //random number

using namespace std;

const double BASIC_RATE = 28.50;
const double PREMIUM_RATE = 60.00;

struct Member {
    static int total_visits;
    static int active_members;
    static int last_id;

    int id = 0;
    string name = "";
    char type = ' ';
    int visits = 0;

    //constructor
    Member(string name, char type){
        this->name = name;
        this->type = type;
        visits = 0;
        id = last_id++; //creates a unique id when new member is added
        active_members++; //keeps count of total members
    }

    //deconstructor
    ~Member() {
        active_members-- ; //removes members by one once deleted
    }
};

int Member::total_visits = 0;
int Member::active_members = 0;
int Member::last_id = 100001;

void visit(Member &obj){
    obj.visits += 1;
    Member::total_visits += 1;
}

int main() {

    /***** DECLARATION & INITIALIZATION SECTION *****/

    int random = 0;
    double typeAmount = 0;
    string typeString = "";
    srand(time(NULL));
    vector<Member*> customer;

    //create customers and add them to vector
    Member *new_customer1 = new Member("Oprah Winfrey", 'P');
    customer.push_back(new_customer1);

    Member *new_customer2 = new Member("Fluffy Iglesias", 'P');
    customer.push_back(new_customer2);

    Member *new_customer3 = new Member("Charlie Sheen", 'B');
    customer.push_back(new_customer3);

    Member *new_customer4 = new Member("Bill Gates", 'B');
    customer.push_back(new_customer4);

    /***** INTRO SECTION *****/

    cout << "Welcome to the GYM Membership program!\n\n";

    // cout << "\nActive members: " << Member::active_members; //testing line
    // cout << "\n" << customer[2]->name; //testing line

    /***** PROCESSING SECTION *****/
    
    //remove Charlie sheen and care for pointer
    customer.erase(customer.begin()+2);
    delete new_customer3;
    new_customer3 = nullptr;

    // cout << "\nActive members: " << Member::active_members; //testing line
    // cout << "\n" << customer[2]->name; //testing line

    //create a random number for each remaining members to visit the GYM
    random = rand() % 16;
    random += 5;
    // cout << "\nRandom number is: " << random; //testing line
    //first customer to loop through for random number generated
    for (int i = 0; i < random; i++){
        visit(*customer[0]);
    }
    // cout << "\n" << customer[0]->visits;

    random = rand() % 16;
    random += 5;
    // cout << "\nRandom number is: " << random; //testing line
    //second customer to loop through for random number generated
    for (int i = 0; i < random; i++){
        visit(*customer[1]);
    }

    random = rand() % 16;
    random += 5;
    // cout << "\nRandom number is: " << random; //testing line
    //third customer to loop through for random number generated
    for (int i = 0; i < random; i++){
        visit(*customer[2]);
    }

    // cout << "\n" << customer[2]->visits; //testing line
    // cout << "\nTotal Visits: " << Member::total_visits; //testing line


    //loop through all customers and initialize type with propper $ amount, and output for each customer
    for (int i = 0; i < customer.size(); i++){
        if (customer[i]->type == 'B'){
            typeAmount = 28.50;
            typeString = "Basic";
        } else {
            typeAmount = 60.00;
            typeString = "Premium";
        }
        
        /***** OUTPUT SECTION *****/
        
        cout << fixed << setprecision(2) << "\n" << i + 1 << ". ID:" << customer[i]->id 
             << "  Name: " << left << setw(17) << customer[i]->name << "Visits: " << left << setw(5) << customer[i]->visits 
             << "Membership Type: " << left << setw(9) << typeString << "Monthly Rate: $" << typeAmount;
    }

    cout << endl;
    cout << "\nTotal Visits: " << Member::total_visits;
    cout << "\nActive members: " << Member::active_members;

    // system("PAUSE"); //for DevC++ on windows
    return EXIT_SUCCESS;
}