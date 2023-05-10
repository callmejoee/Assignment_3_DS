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
    static void swap (Student &first, Student &other);
    float get_gpa();


    int get_id();

    string get_name();

    string get_department();
};

#endif //STUDENT_H