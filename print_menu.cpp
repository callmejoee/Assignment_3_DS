//
// Created by Youssef on 5/8/2023.
//


#include "main.h"


/**
 * print_menu - function to print the first user menu and switch for each function
 *
 * @param students
 *
 * @return void
 */

void print_menu(vector<Student> students) {

    int choice = 0;

    while (choice != 5)
    {
        cout << "Choose Data Structure:" << endl;
        cout << "1. BST" << endl;
        cout << "2. AVL" << endl;
        cout << "3. Min Heap" << endl;
        cout << "4. Max Heap" << endl;
        cout << "5. Exit Program" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                open_file(students);
                // Handle BST choice
                break;
            case 2:
                open_file(students);
                // Handle AVL choice
                break;
            case 3:
                open_file(students);
                // Handle Min Heap choice
                break;
            case 4:
                open_file(students);
                // Handle Max Heap choice
                max_heap_menu(students);
                break;
            case 5:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }


    }

}

