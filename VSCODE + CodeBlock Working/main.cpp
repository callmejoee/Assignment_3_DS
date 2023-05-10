#include <iostream>
#include "Header.h"
#include "Functions.cpp"
using namespace std;

int main() {
    int choice;
    vector<Student> students;  // vector should store pointer to Student objects


    open_file(students);
    print_menu(students);

    return 0;
}
