//
// Created by Youssef on 5/8/2023.
//

#ifndef MAIN_H
#define MAIN_H


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "student.h"

using namespace std;

void open_file(vector<Student>& students);
void max_heapify (vector<Student> students, int size, int i);
void print_heap(vector<Student> students);
void max_heap(vector<Student> students);
void max_heap_menu(vector<Student> students);
void print_menu(vector<Student> students);




#endif //MAIN_H
