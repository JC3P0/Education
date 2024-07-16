/*______________________________________
* FILE: HW_09_INVENTORY_ITEM_JC.cpp
* AUTHOR: Josh Clemens
* MODULE: 9
* PROJECT: 2
* LAST MODIFIED: October 30, 22
* PROBLEM STATEMENT: Uses a structure to store an inventory to a binary file and reads from the same binary file to output.
* ALGORITHM:
*    INITIALIZE output and input fstream for writing and reading a binary file.
*    LOOP menu option
*      PROMPT user to add inventory item, display the results or exit the program
*      VALIDATE menu input, negative item entries
*      CALCULATE write users input as struct to binary file
*      CALCULATE read item structs from file to output
*______________________________________*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Inventory{
    string itemDescription;
    int quantity;
    double wholeSale;
    double salePrice;
    string dateAdded;
};

void showItem(fstream &, int);

int main() {
    
    const string fileName = "inventory.dat";
    fstream inputFile;
    int countItems = 0;
    int input = 0;
    Inventory items[10]; //array to hold struct objects

    do{
        cout << "Please enter an option. \n1) Add a new record to file. \n2) Display a record from file \n3) Exit program \nOption: ";
        cin >> input;
        if(input != 1 && input != 2 || input == 3){//validate menu input
            break;
        }
        
        if(input == 1) {
            cout << "Add new record to file\n";
            //used to create temp struct obj
            string getDesc;
            int getQuantity = 0;
            double getSale = 0;
            double getPrice = 0;
            string getDate;

            //get users input for item
            cout << "Item Description: ";
            cin >> getDesc;
            cout << "Item Quantity: ";
            cin >> getQuantity;
            while (getQuantity < 0){ //validate for negative input
                cout << "Quantity cannot be negative, try again." << endl;
                cout << "Item Quantity: ";
                cin >> getQuantity;
            }
            cout << "Item Whole Sale price: ";
            cin >> getSale;
            while (getSale < 0){ //validate for negative input
                cout << "Whole sale price cannot be negative, try again." << endl;
                cout << "Item Whole Sale price: ";
                cin >> getSale;
            }
            cout << "Item Sale price: ";
            cin >> getPrice;
            while (getPrice < 0){ //validate for negative input
                cout << "Sale price cannot be negative, try again." << endl;
                cout << "Item Sale price: ";
                cin >> getPrice;
            }
            cout << "Item Date added: ";
            cin >> getDate;

            Inventory tempObj; //temp struct obj
            //fill temp struct obj with users input
            tempObj.itemDescription = getDesc;
            tempObj.quantity = getQuantity;
            tempObj.wholeSale = getSale;
            tempObj.salePrice = getPrice;
            tempObj.dateAdded = getDate;

            items[countItems] = tempObj; //add temp obj to items array at current count of items
            remove("inventory.dat"); //remove file to rewrite full array of struct objects
            inputFile.open(fileName, ios::binary | ios::out);
            if(!inputFile){ //validate if file can be opened
                cout << "Error, file not found\n";
                exit(1);
            }
            inputFile.write(reinterpret_cast<char *>(items), sizeof(items));
            inputFile.close();
            countItems++; //count for another item added
            cout << "Items added: " << countItems << endl;
        }
        if(input == 2) {

            inputFile.open(fileName, ios::binary | ios::in);
            if(!inputFile){ //validate if file can be opened
                cout << "Error, file not found\n";
                exit(1);
            }
            for(int i = 0; i < countItems; i++){
                showItem(inputFile, i);
            }
            inputFile.close();
        }

    }while (input != 3);

    return 0;
}
// print items
void showItem(fstream &inputStream, int index) {

    Inventory temp; //temp struct obj
    long offset = index * sizeof(Inventory); //create offset
    inputStream.clear();
    inputStream.seekg(offset, ios::beg); //set pointer in file
    inputStream.read(reinterpret_cast<char *>(&temp), sizeof(Inventory)); //read from file
    //output item
    cout << "Item #" << index + 1 << endl;
    cout << "Item Description: " << temp.itemDescription << endl;
    cout << "Quantity: " << temp.quantity << endl;
    cout << "Whole Sale Price: " << temp.wholeSale << endl;
    cout << "Sale Price: " << temp.salePrice << endl;
    cout << "Date Added: " << temp.dateAdded << endl;
}