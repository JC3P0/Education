/*______________________________________
* FILE: FINAL_INVENTORY_JC.cpp
* AUTHOR: Josh Clemens
* MODULE: FINAL
* PROJECT: FINAL
* LAST MODIFIED: December 14, 2022
* PROBLEM STATEMENT: Inventory program that uses an abstract InventoryItem class that is the base class for Snack and Computer. Laptop class is derived from Computer class. Add inventory items, quantity, display items and sell items keeping track of total items sold and total sales amount. Custom Exceptions thrown when trying to sell more of an item than available.
* ALGORITHM:
*    INITIALIZE Abstract InventoryItem class with pure virtual add and sell functions
*    INITIALIZE Computer and Snack classes derived from InventoryItem with custom exception for item quantities
*    INITIALIZE Laptop class derived from Computer with custom exception for item quantities
*    INITIALIZE in main, objects into vectors of their own class type
*        LOOP do while(input !=4)
*        OUTPUT main menu options 1. add inventory or quantity, 2. display inventory and sales, 3. sell inventory, 4. exit
*        PROMPT users input
*        CALCULATE input
*            1) PROMPT add new item or add quantity to existing item
*                PROMPT 1. add new item, 2. add quantity to existing item
*                    PROMPT 1. computer, 2. laptop, 3. snack
*            2) display inventory, total sales, total items sold
*            3) PROMPT to sell item
*                PROMPT 1. computer, 2. laptop, 3. snack
*                    PROMPT amount to sell
*            4) END loop exit program
*______________________________________*/

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <vector>
#include "Computer.h"
#include "Laptop.h"
#include "InventoryItem.h"
#include "Snack.h"

using namespace std;

//function prototypes
void finalMenu();
template <typename T>
void displayVector(vector<T> &array);
void disInv();
void snackInv();
Snack addSnack();
Computer addComputer();
Laptop addLaptop();

int main() {

    //declare and initialize variables
    int input = 0, countComp = 0, countLap = 0, countSnack = 0, quantity = 0, amount = 0, itemCount = 0, itemsSold = 0;
    double price = 0.0, model = 0.0, weight = 0.0, calc = 0, totalSales = 0;
    string description = " ", allergens = " ";

    //create vectors to hold objects
    vector<Computer> arrayComp(countComp);
    vector<Laptop> arrayLap(countLap);
    vector<Snack> arraySnack(countSnack);

    //load inventory with items
    //computers
    Computer compt = Computer(19, 599.99, "Dell Inspiron Desktop", 3891);
    arrayComp.push_back(compt);
    countComp++;
    Computer compt2 = Computer(9, 1449.99, "Lenovo Legion Tower 5i", 11751);
    arrayComp.push_back(compt2);
    countComp++;
    Computer compt3 = Computer(6, 6989.00, "Falcon Northwest Talon", 2022);
    arrayComp.push_back(compt3);
    countComp++;

    //snacks
    Snack nakt = Snack(37, 2.99, "Snickers", "Dairy, Nuts");
    arraySnack.push_back(nakt);
    countSnack++;
    Snack nakt2 = Snack(22, 3.99, "Sun Flower Seeds", "NA");
    arraySnack.push_back(nakt2);
    countSnack++;
    Snack nakt3 = Snack(32, 1.99, "Corn Nuts", "NA");
    arraySnack.push_back(nakt3);
    countSnack++;

    //laptops
    Laptop lapt = Laptop(16, 999.00, "Apple MacBook Air M1", 2020, 2);
    arrayLap.push_back(lapt);
    countLap++;
    Laptop lapt2 = Laptop(21, 749.98, "Dell XPS 13", 202013, 3);
    arrayLap.push_back(lapt2);
    countLap++;
    Laptop lapt3 = Laptop(9, 890.96, "HP Pavilion Aero 13", 2021, 3);
    arrayLap.push_back(lapt3);
    countLap++;
    Laptop lapt4 = Laptop(23, 1200.99, "Lenovo Yoga 7i Gen 7", 2022, 2);
    arrayLap.push_back(lapt4);
    countLap++;

    

    //menu / sale / add inventory loop
    do {

        //main menu
        finalMenu();

        cout << "Enter option: ";
        cin >> input;
        cout << endl;
        if (input != 4){
            switch (input){
                case 1:
                    //menu options
                    cout << "Enter 1) to add a new inventory item. \nEnter 2) to add quantity to an existing inventory item. \nChoice: ";
                    cin >> input;
                    if (input == 1){
                        //add new item to inventory
                        cout << "\nChoose an item category to enter \nEnter 1) for Computer \nEnter 2) for Laptop \nEnter 3) for Snack \nChoice: ";
                        cin >> input;
                        if (input == 1){
                            //add new computer
                            Computer comp = addComputer(); //create temp obj and call function to fill info
                            arrayComp.push_back(comp); //adds temp object into vector array to be stored
                            countComp++; //count items created
                            cout << "Inventory Updated: ID: " << comp.getId() << "| " << comp.getDescription() << endl;
                        }
                        else if (input == 2){
                            //add new laptop
                            Laptop lap = addLaptop();
                            // cout << lap; //testline
                            arrayLap.push_back(lap); //adds temp object into vector array to be stored
                            countLap++;
                            cout << "Inventory Updated: ID: " << lap.getId() << "| " << lap.getDescription() << endl;
                        }
                        else if (input == 3){
                            //add new snack
                            Snack S1 = addSnack();
                            // cout << lap; //testline
                            arraySnack.push_back(S1); //adds temp object into vector array to be stored
                            countSnack++;
                            cout << "Inventory Updated: ID: " << S1.getId() << "| " << S1.getDescription() << endl;
                        }
                        else {
                            //validate input
                            cout << "Must enter 1 - 3, press any key to continue...\n";
                            cin.ignore(); //ignore next input(void next input for user to continue the program)
                            cin.get(); //makes user enter any key to continue
                        }
                    }
                    else if (input == 2) {
                        //chose item to add quantity
                        amount = 0;//use amount and input to locate desired item to add quantity
                        itemCount = 0;
                        cout << "\nChoose an item category to enter \nEnter 1) for Computer \nEnter 2) for Laptop \nEnter 3) for Snack \nChoice: ";
                        cin >> input;
                        if (input == 1){
                            //chose computer item
                            cout << "\nChoose an item to add quantity: \n";
                            for (const auto& i : arrayComp){
                                cout << itemCount + 1 << ") " << "Id: " << i.getId() << " | " << i.getDescription() << " | Quantity: " << i.getQuantity() << endl;
                                itemCount++;
                            }
                            cout << "Choice: ";
                            cin >> input;

                            cout << "Enter the amount to add to " << arrayComp[input - 1].getDescription() << " | Currently: " << arrayComp[input - 1].getQuantity() << "\nAmount: ";
                            cin >> amount;
                            arrayComp[input - 1].add(amount);//add quantity to desired item
                            cout << "Quantity Updated: " << arrayComp[input - 1].getDescription() << " | New Quantity: " << arrayComp[input - 1].getQuantity() << endl;
                        }
                        else if (input == 2){
                            //chose laptop item
                            cout << "\nChoose an item to add quantity: \n";
                            for (const auto& i : arrayLap){
                                cout << itemCount + 1 << ") " << "Id: " << i.getId() << " | " << i.getDescription() << " | Quantity: " << i.getQuantity() << endl;
                                itemCount++;
                            }
                            cout << "Choice: ";
                            cin >> input;

                            cout << "Enter the amount to add to " << arrayLap[input - 1].getDescription() << " | Currently: " << arrayLap[input - 1].getQuantity() << "\nAmount: ";
                            cin >> amount;
                            arrayLap[input - 1].add(amount);//add quantity to desired item
                            cout << "Quantity Updated: " << arrayLap[input - 1].getDescription() << " | New Quantity: " << arrayLap[input - 1].getQuantity() << endl;
                        }
                        else if (input == 3){
                            //chose snack item
                            cout << "\nChoose an item to add quantity: \n";
                            for (const auto& i : arraySnack){
                                cout << itemCount + 1 << ") " << "Id: " << i.getId() << " | " << i.getDescription() << " | Quantity: " << i.getQuantity() << endl;
                                itemCount++;
                            }
                            cout << "Choice: ";
                            cin >> input;

                            cout << "Enter the amount to add to " << arraySnack[input - 1].getDescription() << " | Currently: " << arraySnack[input - 1].getQuantity() << "\nAmount: ";
                            cin >> amount;
                            arraySnack[input - 1].add(amount); //add quantity to desired item
                            cout << "Quantity Updated: " << arraySnack[input - 1].getDescription() << " | New Quantity: " << arraySnack[input - 1].getQuantity() << endl;
                        }
                        else {
                            cout << "Must enter 1 - 3, press any key to continue...\n";
                            cin.ignore(); //ignore next input(void next input for user to continue the program)
                            cin.get(); //makes user enter any key to continue
                        }

                    }
                    cout << "Press any key to continue...\n";
                    cin.ignore(); //ignore next input(void next input for user to continue the program)
                    cin.get(); //makes user enter any key to continue
                    cout << endl;

                    break;
                case 2:
                    //display inventory
                    disInv();
                    displayVector(arrayComp);//computer obj array
                    displayVector(arrayLap);//laptop obj array
                    cout << endl;
                    snackInv();
                    displayVector(arraySnack);//snack obj array
                    cout << "\n\nTotal Items sold today: " << itemsSold << endl;
                    cout << "Total sales amount: $" << totalSales << endl;
                    
                    cout << "\nPress any key to continue...\n";
                    cin.ignore(); //ignore next input(void next input for user to continue the program)
                    cin.get(); //makes user enter any key to continue
                    cout << endl;
                    cout << endl;

                    break;
                case 3:
                    //sell items
                    amount = 0; //used to calculate sale total
                    calc = 0; //used to calculate sale total
                    itemCount = 0; //used to loop through items
                    cout << "Enter an item to sell: " << endl;
                    cout << "\nChoose an item category to Sell \nEnter 1) for Computer \nEnter 2) for Laptop \nEnter 3) for Snack \nChoice: ";
                    cin >> input;
                    //sell computer
                    if (input == 1){
                        cout << "\nChoose an item to sell: \n";
                        for (const auto& i : arrayComp){
                            cout << itemCount + 1 << ") " << i.getDescription() << " | Id: " << i.getId() << " | Price: $" << i.getPrice() << " | Quantity: " << i.getQuantity() << endl;
                            itemCount++;                            
                        }
                    //choose computer to sell
                    cout << "Choice: ";
                    cin >> input;

                    try{   
                        //try catch exception
                        cout << "Enter the amount to sell: " << arrayComp[input - 1].getDescription() << " | Price: $" << arrayComp[input - 1].getPrice() << " | Quantity: " << arrayComp[input - 1].getQuantity() << "\nAmount: ";
                        cin >> amount;
                        arrayComp[input - 1].sell(amount);
                        cout << "Item sold: " << arrayComp[input - 1].getDescription() << " | Quantity left: " << arrayComp[input - 1].getQuantity() << endl;
                        calc = arrayComp[input - 1].getPrice(); //get item price
                        calc *= amount; //calculate total for sale
                        totalSales += calc; //add current sale to totalSales
                        itemsSold += amount; //track total items sold
                        cout << "Current Sale Amout: $" << calc << endl;
                    }
                    catch(Computer::QuantityEmpty){
                            cout << "Error: Amount entered is greater than available Quantity.\n";
                    }
                    }
                        //sell laptop
                    else if (input == 2){
                        cout << "\nChoose an item to sell: \n";
                        for (const auto& i : arrayLap){
                            cout << itemCount + 1 << ") " << i.getDescription() << " | Id: " << i.getId() << " | Price: $" << i.getPrice() << " | Quantity: " << i.getQuantity() << endl;
                            itemCount++;                           
                         }
                        //choose laptop to sell
                         cout << "Choice: ";
                         cin >> input;

                        try{   
                             //try catch exception
                             cout << "Enter the amount to sell: " << arrayLap[input - 1].getDescription() << " | Price: $" << arrayLap[input - 1].getPrice() << " | Quantity: " << arrayLap[input - 1].getQuantity() << "\nAmount: ";
                             cin >> amount;
                             arrayLap[input - 1].sell(amount);
                             cout << "Item sold: " << arrayLap[input - 1].getDescription() << " | Quantity left: " << arrayLap[input - 1].getQuantity() << endl;
                             calc = arrayLap[input - 1].getPrice();
                             calc *= amount;
                             totalSales += calc;
                             itemsSold += amount;
                             cout << "Current Sale Amout: $" << calc << endl;
                        }
                        catch(Laptop::QuantityEmpty){
                                cout << "Error: Amount entered is greater than available Quantity.\n";
                        }
                    }
                    //sell Snack
                    else if (input == 3){
                        cout << "\nChoose an item to sell: \n";
                        for (const auto& i : arraySnack){
                            cout << itemCount + 1 << ") " << i.getDescription() << " | Id: " << i.getId() << " | Price: $" << i.getPrice() << " | Quantity: " << i.getQuantity() << endl;
                            itemCount++;                           
                    }
                    cout << "Choice: ";
                    cin >> input;

                    try{    
                         //try catch exception
                         cout << "Enter the amount to sell: " << arraySnack[input - 1].getDescription() << " | Price: $" << arraySnack[input - 1].getPrice() << " | Quantity: " << arraySnack[input - 1].getQuantity() << "\nAmount: ";
                         cin >> amount;
                         arraySnack[input - 1].sell(amount);
                         cout << "Item sold: " << arraySnack[input - 1].getDescription() << " | Quantity left: " << arraySnack[input - 1].getQuantity() << endl;
                         calc = arraySnack[input - 1].getPrice();
                         calc *= amount;
                         totalSales += calc;
                         itemsSold += amount;
                         cout << "Current Sale Amout: $" << calc << endl;
                    }
                    catch(Snack::QuantityEmpty){
                            cout << "Error: Amount entered is greater than available Quantity.\n";
                    }
                    }
                    else {
                        cout << "Must enter 1 - 3, press any key to continue...\n";
                        cin.ignore(); //ignore next input(void next input for user to continue the program)
                        cin.get(); //makes user enter any key to continue
                    }
                    cout << "\nPress any key to continue...\n";
                    cin.ignore(); //ignore next input(void next input for user to continue the program)
                    cin.get(); //makes user enter any key to continue
                    cout << endl;
                    break;
                
                default:
                    //validate input
                    cout << "Error: Please enter a choice between 1-4.\n";
                    cout << endl;
                    break;
            }
        }
    } while (input != 4);  //condition to end do while loop

    //outro
    cout << "Thank you for using Josh's Final Inventory Program.\n";

    return 0;
}

//function definitions
//prints main menu
void finalMenu(){
    cout << "************************************************************************\n"
         << "**                                                                    **\n"
         << "**                        WELCOME TO Josh's                           **\n"
         << "**                     FINAL INVENTORY PROGRAM                        **\n"
         << "**                                                                    **\n"
         << "************************************************************************\n"
         << "** Please make a choice from the following options:                   **\n"
         << "** 1)  Add Item to Inventory                                          **\n"
         << "** 2)  Display Inventory                                              **\n"
         << "** 3)  Sell Inventory Item                                            **\n"
         << "** 4)  Exit                                                           **\n"
         << "************************************************************************\n";
    cout << endl;
}

//displays computer and laptop inventory
void disInv(){

    cout << "*************************************************************************\n"
         << "**                   Computer / Laptop Inventory                       **\n"
         << "*************************************************************************\n"
         << "| Id # | Quantity | Price   | Description          | Model #  | Weight  |\n"
         << "*************************************************************************\n";
//    cout << endl;
}

//displays snack inventory
void snackInv(){
    cout << "*************************************************************************\n"
         << "**                         Snack Inventory                             **\n"
         << "*************************************************************************\n"
         << "| Id # | Quantity | Price   | Description             | Allergens       |\n"
         << "*************************************************************************\n";
}

//prints vectors for all class objects
template <typename T>
void displayVector(vector<T> &array) {
    for (auto & count : array){
        cout << count;
    }
}

//add snack obj to inventory
Snack addSnack(){
    int quantity = 0; //used to create temp object
    double price = 0.0;
    string description = " ";
    string allergens = " ";
    Snack S1 = Snack(); // temp object to return
    //get users input
    cout << "\nEnter quantity: ";
    cin >> quantity;
    S1.setQuantity(quantity);
    cout << "Enter Price: $";
    cin >> price;
    S1.setPrice(price);
    cout << "Enter Description: ";
    cin.ignore();
    getline (cin, description);
    S1.setDescription(description);
    cout << "Enter Allergens: ";
    getline (cin, allergens);
    S1.setAllergens(allergens);
    return S1; //return temp object to add to array
}

//add computer obj to inventory
Computer addComputer(){
    int quantity = 0; //used to create temp object
    double price = 0.0;
    string description = " ";
    double model = 0.0;
    Computer comp = Computer(); // temp object to return
    //get users input
    cout << "\nEnter quantity: ";
    cin >> quantity;
    comp.setQuantity(quantity);
    cout << "Enter Price: $";
    cin >> price;
    comp.setPrice(price);
    cout << "Enter Description: ";
    cin.ignore();
    getline (cin, description);
    comp.setDescription(description);
    cout << "Enter Model: ";
    cin >> model;
    comp.setModel(model);
    return comp; //return temp object to add to array
}

//add laptop obj to inventory
Laptop addLaptop(){
    int quantity = 0; 
    double price = 0.0;
    string description = " ";
    double model = 0.0;
    double weight = 0;
    Laptop lap = Laptop(); // create temp object to return
    cout << "\nEnter quantity: ";
    cin >> quantity;
    lap.setQuantity(quantity);
    cout << "Enter Price: $";
    cin >> price;
    lap.setPrice(price);
    cout << "Enter Description: ";
    cin.ignore();
    getline (cin, description);
    lap.setDescription(description);
    cout << "Enter Model: ";
    cin >> model;
    lap.setModel(model);
    cout << "Enter Weight: ";
    cin >> weight;
    lap.setWeight(weight);
    return lap; //return temp object
}