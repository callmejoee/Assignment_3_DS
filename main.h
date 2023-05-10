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
#include "AVL+BST/AVL.h"
#include "AVL+BST/BST.h"

using namespace std;

void open_file(vector<Student>& students);
void max_heapify(vector<Student> &students, int i, int size);
void min_heapify(vector<Student> &students, int i, int size);
void min_build_heap(vector<Student> &students);
void max_build_heap(vector<Student> &students);
void max_heap_menu(vector<Student> students);
void min_heap_menu(vector<Student> students);
void print_menu(vector<Student> students);
void switch_option(int choice, vector<Student> students);



#endif //MAIN_H
