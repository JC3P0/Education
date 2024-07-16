#include "Student.h"
#include <iomanip>

Student::Student() : Student("", 0){}

Student::Student(string name, int score){
    this -> m_name = name;
    this -> m_score = score;   
}
Student::~Student(){
    
}

string Student::getName() const{
    return m_name;
}

int Student::getScore() const{
    return m_score;
}

void Student::setName(string name){
    this -> m_name = name;
}

void Student::setScore(int score){
    this -> m_score = score;
}

// Student& Student::operator=(Student rhs){
//     this -> m_name = rhs.m_name;
//     this -> m_score = rhs.m_score;
//     return *this;
// }

ostream& operator<<(ostream& out, const Student& t){
    return out << "Student: " << t.m_name << " Score: " << t.m_score << "\n";   
}

bool operator==(Student a, Student b){
    return ((a.m_name == b.m_name) && (a.m_score == b.m_score));
}