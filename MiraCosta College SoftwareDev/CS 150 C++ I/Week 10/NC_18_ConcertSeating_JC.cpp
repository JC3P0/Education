/*____________________
* AUTHOR: Josh Clemens
* COURSE: CS 150: C++ Programming 1
* NC (PROJECT)#: NC_18
* LAST MODIFIED: April 06, 2022
*________________
* Concert Seating
*_____________________
* PROGRAM DESCRIPTION:
* This program sells tickets for a small theater. The auditorium has 15 rows of seats with 30 seats in each row. This program displays a screen that shows which seats are available and which are not available. The program uses nine functions to display; seating chart, count the total ticket and total ticket sale amount and update the seating chart as tickets are sold.
*___________
* ALGORITHM:
* INIT. GLOBAL CONST used for main() and functions. max rows, max seats per row, available seats, seats taken.
* INITILIZE pricing by row (read from file), all seats available = '#', seats[max row][max seat per row] array.
* PROMPT main menu
* VALIDATE inputs
* SWITCH loop between; selling tickets, viewing; total sales, total seats sold, seats left, seats left per row.
*___________________________________________
* ALL IMPORTED LIBRARIES NEEDED AND PURPOSE:
* <cstdlib> Provides standard functions, including dynamic memory management,
* random number generation, communication with the environment,
* integer arithmetics, searching, sorting and converting.
* <iostream> Used for console input and output (cin and cout).
* <iomanip> setprecision(2)
* <fstream> read files
*____________________________________________*/

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

//global const. used in main() and functions
const int MAX_ROWS = 15;
const int MAX_SEATS_PER_ROW = 30;
const char AVAILABLE_SEAT = '#';
const char TAKEN_SEAT = '*';

//function prototypes
void readPrices(double ticketPrices[]);
void initializeSeating(char seats[][MAX_SEATS_PER_ROW] );
void menuOptions();
void sellSeats(char seats[][MAX_SEATS_PER_ROW], double ticketPrices[MAX_ROWS]);
void displaySeating(char seats[][MAX_SEATS_PER_ROW] );
void displayTicketPrices(double prices[]);
int countSales(char seats[][MAX_SEATS_PER_ROW], const char SYMBOL);
int displayRowsLeft(int row, char seats[][MAX_SEATS_PER_ROW], const char AVAILABLE_SEAT);
double calculateTxSales(char seats[][MAX_SEATS_PER_ROW], double prices[]);
//void initializePricing(double seatPrices[][MAX_SEATS_PER_ROW] );//test function

int main(int argc, char* argv[]) {

    /***** CONSTANT SECTION *****/
    //only global const.

    /***** DECLARATION SECTION *****/  

    int input;
    
    /***** INITIALIZATION SECTION *****/

    char seats[MAX_ROWS][MAX_SEATS_PER_ROW];
    double ticketPrices[MAX_ROWS];
    readPrices(ticketPrices); //initializes row prices
    //test functions. initializes 'all' seats per row prices
    //initializePricing(seatPrices);
    //double seatPrices[MAX_ROWS][MAX_SEATS_PER_ROW];
    initializeSeating(seats); //initializes all seats to = AVAILABLE_SEAT
    
    /***** INTRO SECTION *****//***** INPUT SECTION *****/
    /***** PROCESSING SECTION *****/ /***** OUTPUT SECTION *****/

    do{
        menuOptions();
        cin >> input;
        if(input != 5){
            system("clear"); //clear the screen for next input
            switch (input){
                case 1:     
                    sellSeats(seats, ticketPrices);                
                    calculateTxSales(seats, ticketPrices);
                    countSales(seats, TAKEN_SEAT);
                    countSales(seats, AVAILABLE_SEAT);
                    system("clear");    
                    break;
                
                case 2:
                    system("clear");
                    displayTicketPrices(ticketPrices);
                    cout << "\nEnter any key to return to menu. . .\n";
                    cin.ignore(); //ignore next input(void next input for user to continue the program)
                    cin.get(); //makes user enter any key to continue
                    system("clear");
                    break;

                case 3:
                    system("clear");
                    displaySeating(seats);
                    cout << "\nTotal Sales: $" << calculateTxSales(seats, ticketPrices) << endl; 
                    cout << "\nEnter any key to return to menu. . .\n";
                    cin.ignore(); //ignore next input(void next input for user to continue the program)
                    cin.get(); //makes user enter any key to continue
                    system("clear");
                    break;

                case 4:
                    system("clear");
                    cout << "Total tickets sold: " << countSales(seats, TAKEN_SEAT);
                    cout << endl;
                    cout << "\nSeats left in auditorium: " << countSales(seats, AVAILABLE_SEAT);
                    cout << endl;
                    cout << "\nSeats Left per row: ";
                    cout << "\n\tRow 1:  " << displayRowsLeft(1,seats, AVAILABLE_SEAT);
                    cout << "\n\tRow 2:  " << displayRowsLeft(2,seats, AVAILABLE_SEAT);
                    cout << "\n\tRow 3:  " << displayRowsLeft(3,seats, AVAILABLE_SEAT);
                    cout << "\n\tRow 4:  " << displayRowsLeft(4,seats, AVAILABLE_SEAT);
                    cout << "\n\tRow 5:  " << displayRowsLeft(5,seats, AVAILABLE_SEAT);
                    cout << "\n\tRow 6:  " << displayRowsLeft(6,seats, AVAILABLE_SEAT);
                    cout << "\n\tRow 7:  " << displayRowsLeft(7,seats, AVAILABLE_SEAT);
                    cout << "\n\tRow 8:  " << displayRowsLeft(8,seats, AVAILABLE_SEAT);
                    cout << "\n\tRow 9:  " << displayRowsLeft(9,seats, AVAILABLE_SEAT);
                    cout << "\n\tRow 10: " << displayRowsLeft(10,seats, AVAILABLE_SEAT);
                    cout << "\n\tRow 11: " << displayRowsLeft(11,seats, AVAILABLE_SEAT);
                    cout << "\n\tRow 12: " << displayRowsLeft(12,seats, AVAILABLE_SEAT);
                    cout << "\n\tRow 13: " << displayRowsLeft(13,seats, AVAILABLE_SEAT);
                    cout << "\n\tRow 14: " << displayRowsLeft(14,seats, AVAILABLE_SEAT);
                    cout << "\n\tRow 15: " << displayRowsLeft(15,seats, AVAILABLE_SEAT);
                    cout << endl;
                    cout << "\nEnter any key to return to menu. . .\n";
                    cin.ignore(); //ignore next input(void next input for user to continue the program)
                    cin.get(); //makes user enter any key to continue
                    system("clear");
                    break;

                case 5:
                    break;

                //input validation
                default:
                    cout << "Error: Please enter a choice between 1-5\n";
                    cout << endl;
                    break;
            }            
            system("clear"); //clear the screen for next menu input
        }           
    }while (input != 5);

    system("clear");
    cout << "Thank you for using the seating chart program!!!\n";
      
    // system("PAUSE"); //for DevC++ on windows
    return EXIT_SUCCESS;
}

    /***** Function Definitions *****/

//initializes all seats to = AVAILABLE_SEAT
void initializeSeating(char seats[][MAX_SEATS_PER_ROW] ) {
    for(int i = 0; i < MAX_ROWS; i++) {
        for(int j = 0; j < MAX_SEATS_PER_ROW; j++) {
            seats[i][j] = AVAILABLE_SEAT;
        }
    }
}

//displays seating chart
void displaySeating(char seats[][MAX_SEATS_PER_ROW] ) {
    
    cout << "\t\t\t\tSeating Chart\n"; 
    cout << "\n\t\t123456789012345678901234567890\n";
    for(int i = 0; i < MAX_ROWS; i++) {
        cout << "Row " << i+1 <<"\t";
        for(int j = 0; j < MAX_SEATS_PER_ROW; j++) {
            cout << seats[i][j];
        }
        cout << endl;
    }
}

//menu option 2
void displayTicketPrices(double prices[]) {
    cout << fixed << setprecision(2) << setfill('0');
    cout << "\tTicket Prices\n";
    for(int i = 0; i < MAX_ROWS; i++) {
        cout << "Row " << i+1 << " - \t$" << prices[i] << endl;
    }
}

//calculates and updates total ticket sales
double calculateTxSales(char seats[][MAX_SEATS_PER_ROW], double prices[]) {
    double totalSales = 0;
    for(int i = 0; i < MAX_ROWS; i++) {
        for(int j = 0; j < MAX_SEATS_PER_ROW; j++) {
            if(seats[i][j] == TAKEN_SEAT) {
               totalSales += prices[i]; 
            }
        }
    }
    return totalSales;
}

//initializes ticket prices from ticketPrices.txt file
void readPrices(double ticketPrices[MAX_ROWS] ) {

    ifstream input;
    int count = 0;
    
    input.open("ticketPrices.txt");
        if (!input)
            cout << "Error opening ticketPrices.txt\n";
        else{
            while (count < MAX_ROWS && input >> ticketPrices[count])
                count++;

        input.close();
    }
}

void menuOptions(){//main menu options
    
    cout << "Welcome to the seating chart program!!!\n" << endl;
    cout << "Menu Options:\n";
    cout << "1. Sell tickets!\n";
    cout << "2. View ticket prices.\n";
    cout << "3. View total ticket sales.\n";
    cout << "4. View - total seats sold.\n \t\t- Seats left in auditorium.\n \t\t- Seats left per row.\n";
    cout << "5. Exit program\n" << "\nEnter menu option: ";
}

//displays seating chart, sells tickets, updates seating chart, re-initialize count and currentSale per group transaction
void sellSeats(char seats[][MAX_SEATS_PER_ROW], double ticketPrices[MAX_ROWS]) {

    int inputs;
    int col = 0;
    int row = 0;
    int count = 0;
    double currentSale = 0;
    
    do {
        system("clear");
        displaySeating(seats);
        cout << "\nEnter a seat that is not taken.";
        cout << "\nEnter row: ";
        cin >> row;
        cout << "Enter column: ";
        cin >> col;
        if (seats[row-1][col-1] != TAKEN_SEAT){
            for(int i = 0; i < MAX_ROWS; i++) {
                for(int j = 0; j < MAX_SEATS_PER_ROW; j++) {
                    if(seats[i][j] != TAKEN_SEAT) {
                        seats[row-1][col-1] = TAKEN_SEAT;             
                    }            
                }            
            }
            currentSale += ticketPrices[row-1];
            count++;
            system("clear"); //refresh the seating chart and display same inputs
            displaySeating(seats);
            cout << "\nEnter a seat that is not taken.";
            cout << "\nEnter row: " << row;;        
            cout << "\nEnter column: " << col;
            cout << "\nSeat[" << row << "][" << col << "] costs $" << ticketPrices[row-1] << ".\n";
            cout << "\nSale Options:";
            cout << "\n1. Sell more tickets!";
            cout << "\n2. Check out!";
            cout << "\n3. Return to Menu.\n";
            cout << "\nEnter sale option: ";
            cin >> inputs;
            switch (inputs){
                case 1:
                    break;
                case 2:
                    system("clear");
                    cout << count << " ticket(s) for a total of: $" << currentSale << endl;
                    cout << "\nEnter any key to return to menu. . .\n";
                    cin.ignore(); //ignore next input(void next input for user to continue the program)
                    cin.get(); //makes user enter any key to continue
                    break;
                case 3:
                    break;
                default:
                    cout << "Please enter a choice between 1-3.\n";
                    cout << endl;
                    cout << "Enter option: ";
                    cin >> inputs;
                    break;                    
            }
        }else {
            cout << "\n*************************";
            cout << "\n**This seat is taken!!!**\n";
            cout << "*************************\n";
            cout << endl;
            cout << count << " ticket(s) for a total of: $" << currentSale << endl;
            cout << "\nStart a new transaction to sell more tickets.\n";
            cout << "\nEnter any key to return to main menu. . .\n";
            cin.ignore(); //ignore next input(void next input for user to continue the program)
            cin.get(); //makes user enter any key to continue
            break;
        }                
    }while (inputs == 1);        
}

/* //test function. initializes all seats per row prices
void initializePricing(double seatPrices[][MAX_SEATS_PER_ROW] ) {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < MAX_SEATS_PER_ROW; j++) {
            seatPrices[i][j] = 28;
        }
    }
    for(int i = 6; i < 10; i++) {
        for(int j = 0; j < MAX_SEATS_PER_ROW; j++) {
            seatPrices[i][j] = 17;
        }
    }
    for(int i = 11; i < 15; i++) {
        for(int j = 0; j < MAX_SEATS_PER_ROW; j++) {
            seatPrices[i][j] = 10;
        }
    }
}
*/

int countSales(char seats[][MAX_SEATS_PER_ROW], const char SYMBOL) { //menu option 4
    
    int count = 0;
    
    for(int i = 0; i < MAX_ROWS; i++) {
                for(int j = 0; j < MAX_SEATS_PER_ROW; j++) {
                    if(seats[i][j] == SYMBOL) {
                        count++;             
                    }            
                }            
            }
    return count;
}

int displayRowsLeft(int row, char seats[][MAX_SEATS_PER_ROW], const char AVAILABLE_SEAT){ //menu option 4

    int countD = 0;
    for(int i = row-1; i < row; i++) {
        for(int j = 0; j < MAX_SEATS_PER_ROW; j++) {
            if(seats[i][j] == AVAILABLE_SEAT) {
               countD++;
            }
        }
    }
return countD;
}
