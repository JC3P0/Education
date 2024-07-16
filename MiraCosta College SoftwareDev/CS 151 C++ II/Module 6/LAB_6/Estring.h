#ifndef ESTRING_H
#define ESTRING_H

#include <cstring>
#include <iostream>
using namespace std;

class Estring{
private:
    char *string;
    int size;

public:
    Estring(const char *s = "");
    Estring(const Estring &); //copy constructor
    ~Estring(); //de constructor
    int getSize() const;
    void setSize(int size);
    void print();
    void change(const char *); 
    Estring &operator=(const Estring &original);
    Estring operator++(); //++prefix
    Estring operator++(int); //postfix++
    char &operator[](int i);
    friend Estring operator+(const Estring&, const Estring&);
    friend ostream& operator<<(ostream& out, const Estring& t);
};

//constructor
Estring::Estring(const char *original){
    size = strlen(original);
    string = new char[size + 1];
    strcpy(string, original);
}

//copy constructor
Estring::Estring(const Estring &original){
    size = original.size;
    string = new char[size +1];
    strcpy(string, original.string);
}

//deconstructor
Estring::~Estring() {
    delete [] string;
    size = 0;
}

int Estring::getSize() const{
    return size;
}

void Estring::setSize(int size){
    this->size = size;
}

//replace with other string object
void Estring::change(const char *original){
    delete [] string;
    size = strlen(original);
    string = new char[size + 1];
    strcpy(string, original);
}

//print the string objects
void Estring::print(){
    cout << string << endl;
}

//overloaded assignment operator
Estring &Estring::operator=(const Estring &original){
    delete [] string;
    size = original.size;
    string = new char[size + 1];
    strcpy(string,original.string);
    return *this;
}

//output stream
ostream& operator<<(ostream &out, const Estring &t){
    return out << t.string;
}

//overloaded ++prefix
Estring Estring::operator++(){

    for (int i = 0; i < size; i++){
        //change all element to uppercase
        string[i] = (char)toupper(string[i]);
//        cout << (char)toupper(string[i]); //testing line
    }
    return *this;
}

//overloaded postfix++
Estring Estring::operator++(int){

    //create copy of original calling string to return
    Estring temp;
    temp.change(string); //use change function for deep copy
    // cout << temp << endl; //testing line
    for (int i = 0; i < size; i++){
        //change all element to uppercase
        string[i] = (char)toupper(string[i]);
    }
    // cout << temp << endl; //testing line
    return temp;
}

//validates if size of string is still in reference
char &Estring::operator[](int i){

    if (this->size < 0 || this->size > getSize()){
        cout << "The size is out of reference, closing program.\n";
        exit(0);
    }
    return *(string + i);
}

//overloaded + to add two objects to equal one
Estring operator+(const Estring &one, const Estring&two){
//    Estring temp;
    int tempSize = 0;
    tempSize = one.size + two.size + 1;
    char tempChar[tempSize];

    strcpy(tempChar, one.string);
    strcat(tempChar, two.string);
    Estring temp= tempChar;
    return temp;
}

#endif ESTRING_H