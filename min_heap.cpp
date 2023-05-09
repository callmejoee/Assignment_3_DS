//
// Created by Youssef on 5/9/2023.
//

#include "main.h"


/**
 * heap_menu - function to priint the heap menu
 *
 * @param students
 */

void min_heap_menu(vector<Student> &students)
{
    int student_id;
    float student_gpa;
    string student_name, student_dep;
    int choice;

    min_build_heap(students);


    cout << "Choose one of the following options: " << endl;
    cout << "1. Add student" << endl;
    cout << "2. Print All (sorted by gpa)" << endl;

    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {

        cout << "-- ADD NEW STUDENT --" << endl;
        cout << "Enter student ID" << endl;
        cin >> student_id;
        cout << "Enter student name" << endl;
        cin >> student_name;
        cout << "Enter student department" << endl;
        cin >> student_dep;
        cout << "Enter student gpa" << endl;
        cin >> student_gpa;

        Student student(student_id, student_name, student_gpa, student_dep);
        students.push_back(student);

        // put the new student in the right node
        int index = students.size() - 1;
        while (index > 0 && students[index].get_gpa() < students[(index - 1) / 2].get_gpa()) {
            std::swap(students[index], students[(index - 1) / 2]);
            index = (index - 1) / 2;
        }

    }
    else if (choice == 2)
    {
        for (auto & student : students) {
            student.print_info();
        }
    }
}


void min_build_heap(vector<Student>& students) {

    for (int i = students.size() / 2 - 1; i >= 0; i--) {
        min_heapify(students, i, students.size());
    }
}

void min_heapify(vector<Student>& students, int i, int size) {
    int min = i;
    int left_node = 2 * i + 1;
    int right_node = 2 * i + 2;

    if (left_node < size && students[left_node].get_gpa() < students[min].get_gpa()) {
        min = left_node;
    }

    if (right_node < size && students[right_node].get_gpa() < students[min].get_gpa()) {
        min = right_node;
    }

    if (min != i) {
        Student::swap(students[i], students[min]);
        min_heapify(students, min, size);
    }
}
