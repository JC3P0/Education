#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <iomanip>
using namespace std;

class LinkedList {

protected:
    struct ListNode {
        double value; //value stored in node
        ListNode *next; //pointer to next node
        //constructor
        ListNode(double valueOne, ListNode *nextOne = nullptr) {
            value = valueOne;
            next = nextOne;
        }
    };
    ListNode *head; // LinkedList head pointer

public:
    LinkedList();	// Constructor
    void add(double x); //add value to list
    bool isMember(double x); //check if list contains a member
    void print(); //display list
    void reverse(); //reverse list
    int search(double x); //search for index of value
    void insert(double x, int pos); //insert member at index with value
};

LinkedList::LinkedList() {
    head = nullptr;
}

//add member to list
void LinkedList::add(double x){
    if (head == nullptr){
        head = new ListNode(x);
    }
    else{
        head = new ListNode(x, head);
    }
}

bool LinkedList::isMember(double x){
    ListNode *ptr = head; //set pointer to head
    while(ptr != nullptr){
        if (ptr -> value == x){
            return true; //return true if found
        }
        ptr = ptr -> next; //set pointer to next node
    }
    delete ptr;
    return false;
}

//display list
void LinkedList::print() {
    ListNode *ptr = head;
    cout << fixed << showpoint << setprecision(1);
    while (ptr != nullptr){
        cout << ptr -> value << " ";
        ptr = ptr -> next; //set pointer to next node
    }
    cout << endl;
    delete ptr;
}

//reverse the list
void LinkedList::reverse() {
    ListNode *ptr = head; //set pointer to head
    ListNode *previous = nullptr;
    ListNode *next = nullptr;
    while (ptr != nullptr){
        //store next
        next = ptr -> next;
        //reverse current node
        ptr -> next = previous;
        //move pointers ahead an index
        previous = ptr;
        ptr = next;
    }
    head = previous;
    delete ptr;
    delete next;
}

int LinkedList::search(double x) {
    if (head == nullptr){
        return -1; //return -1 if not found
    }
    else {
        int position = 0; //track position
        ListNode *ptr = head; //set pointer to head
        while (ptr != nullptr) {
            if (ptr -> value == x){
                return position; //return if found
            }
            ptr = ptr -> next; //set pointer to next node
            position++; //increment position each pass through loop
        }
	delete ptr;
        return -1; //return -1 if not found
    }
}

void LinkedList::insert(double x, int pos) {
    if (head == nullptr) {
        head = new ListNode(x); //if list is empty create new node
    }
    else if (pos == 0){
        add(x); //add element if index is 0
    }
    else {
        int count = 0;
        ListNode *ptr = head; //set pointer to head
        ListNode *previous = nullptr;
        while (ptr != nullptr && count != pos) {
            previous = ptr; //store pointer
            ptr = ptr -> next; // set pointer to next node
            count++; // increment count
        }
        previous -> next = new ListNode(x, ptr); //create new node to insert
    }
}

#endif