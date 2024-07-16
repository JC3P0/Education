#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
using namespace std;

class Student{
private:
    string m_name;
    int m_score;
    
public:
    Student();
    Student(string name, int score);
    ~Student();
    string getName() const;
    int getScore() const;
    void setName(string m_name);
    void setScore(int m_score);
    // Student& operator=(Student rhs);
    friend ostream& operator<<(ostream& out, const Student& t);
    friend bool operator==(Student a, Student b);

};
  
#endif