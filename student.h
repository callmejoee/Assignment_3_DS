//
// Created by Youssef on 5/8/2023.
//

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

using namespace std;

class Student {

private:

    int id;
    string name;
    float gpa;
    string department;

public:

    Student(int id, string name, float gpa, string department);
    void print_info();
    void swap (Student &other);
    float get_gpa();


};

#endif //STUDENT_H
