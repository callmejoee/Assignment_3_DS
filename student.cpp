//
// Created by Youssef on 5/8/2023.
//

#include "student.h"


Student::Student(int id, string name, float gpa, string department)
{
    this->id = id;
    this->name = name;
    this->gpa = gpa;
    this->department = department;
}
void Student::print_info()
{
    cout << "----------------------------------------" << endl;
    cout << "Student ID is: " << id << endl;
    cout << "Student name is: " << name << endl;
    cout << "Student gpa is: " << gpa << endl;
    cout << "Student department is: " << department << endl;
    cout << "----------------------------------------" << endl;

}
void Student::swap (Student &first, Student &other){

    std::swap(first.id, other.id);
    std::swap(first.name, other.name);
    std::swap(first.gpa, other.gpa);
    std::swap(first.department, other.department);
}
float Student:: get_gpa(){
    return (gpa);
}
