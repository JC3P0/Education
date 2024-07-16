#ifndef STRING_H
#define STRING_H

#include <cstring>
#include <iostream>
using namespace std;

class String{
    private:
        char *string;
        int size;

    public:
        String(const char *s = "");
        String(const String &); //copy constructor
        ~String();
        void print();
        void change(const char *);
};

//constructor
String::String(const char *original){
    size = strlen(original);
    string = new char[size + 1];
    strcpy(string, original);
}

//copy constructor
String::String(const String &original){
    size = original.size;
    string = new char[size +1];
    strcpy(string, original.string);
}

//deconstructor
String::~String() { 
    delete [] string; 
    size = 0;
}

//replace with other string object
void String::change(const char *original){
    delete [] string;
    size = strlen(original);
    string = new char[size + 1];
    strcpy(string, original);
}

//print the string objects
void String::print(){
    cout << string << endl;
}

#endif