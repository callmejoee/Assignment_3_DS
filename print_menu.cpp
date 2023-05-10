//
// Created by Youssef on 5/8/2023.
//


#include "main.h"


/**
 * print_menu - function to print the first user menu and switch for each function
 *
 * @param students
 *
 * @return int choice
 */

void print_menu(vector<Student> students) {

    int choice = 0;

    while (choice != 5) {
        cout << "Choose Data Structure:" << endl;
        cout << "1. BST" << endl;
        cout << "2. AVL" << endl;
        cout << "3. Min Heap" << endl;
        cout << "4. Max Heap" << endl;
        cout << "5. Exit Program" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch_option(choice, students);
    }
}

/**
 * switch_option - function to change between options
 *
 * @param choice
 */

void switch_option(int choice, vector<Student> students)
{
    switch (choice) {
        case 1:
//            open_file(students);
            // Handle BST choice
        {
            BST BT;
            BT.load_vector(students);
            BT.BST_menu();
            break;
        }
        case 2: {
            AVL AV;
            AV.load_vector(students);
            AV.AVL_menu();
            break;
        }
        case 3:

            min_heap_menu(students);
            break;
        case 4:

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