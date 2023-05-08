//
// Created by Youssef on 5/8/2023.
//

#include "main.h"

/**
 * max_heapify - function to heapify the heap and sort it into a max heap
 *
 * @param students
 * @param size
 * @param i
 *
 * @return void
 *
 */

void max_heapify (vector<Student> students, int size, int i)
{
    int max = i;
    int left_node = 2 * i + 1;
    int right_node = 2 * i + 2;

    if (left_node < size && students[left_node].get_gpa() > students[max].get_gpa())
        max = left_node;

    if (right_node < size && students[right_node].get_gpa() > students[max].get_gpa())
        max = right_node;

    if (max != i)
    {
        swap (students[i], students[max]);
        max_heapify(students, size, max);
    }
}

void print_heap(vector<Student> students) {
    for (int i = 0; i < students.size(); i++) {
        students[i].print_info();
    }
}

/**
 * max_heap - driver function for max heap
 *
 * @param students
 *
 * @return void
 */

void max_heap(vector<Student> students)
{
    int size = students.size();
    for (int i = ((size / 2) - 1); i >= 0; i++)
        max_heapify(students, size, i);

}

/**
 * max_heap_menu function to tie all the max heap menus
 *
 * @param students
 *
 * @return void
 */

void max_heap_menu(vector<Student> students)
{
    int choice;
    int size;

    max_heap(students);

    // max heap option menu

    cout << "Choose one of the following options: " << endl;
    cout << "1. Add student" << endl;
    cout << "2. Print All (sorted by gpa)" << endl;

    cout << "Enter your choice: ";
    cin >> choice;

//    if (choice == 1)
//        add_student_max()
    if (choice == 2)
    {
        print_heap(students);

    }

}

