#include "Header.h"

void max_heap_menu(vector<Student> students)
{
    int student_id;
    float student_gpa;
    string student_name, student_dep;
    int choice;

    max_build_heap(students);

    while (choice != 3)
    {
        cout << "Choose one of the following options: " << endl;
        cout << "1. Add student" << endl;
        cout << "2. Print All (sorted by gpa)" << endl;
        cout << "3. Back" << endl;

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
            while (index > 0 && students[index].get_gpa() > students[(index - 1) / 2].get_gpa()) {
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
        else if (choice == 3)
            break;
        else {
            cout << "Invalid" << endl;
            continue;
        }
    }
}


void max_build_heap(vector<Student> &students) {

    for (int i = students.size() / 2 - 1; i >= 0; i--) {
        max_heapify(students, i, students.size());
    }
}

void max_heapify(vector<Student> &students, int i, int size) {int max = i;
    int left_node = 2 * i + 1;
    int right_node = 2 * i + 2;

    if (left_node < size && students[left_node].get_gpa() > students[max].get_gpa()) {
        max = left_node;
    }

    if (right_node < size && students[right_node].get_gpa() > students[max].get_gpa()) {
        max = right_node;
    }

    if (max != i) {
        Student::swap(students[i], students[max]);
        max_heapify(students, max, size);
    }
}


void min_heap_menu(vector<Student> students)
{
    int student_id;
    float student_gpa;
    string student_name, student_dep;
    int choice;

    min_build_heap(students);

    while (choice != 3)
    {
    cout << "Choose one of the following options: " << endl;
    cout << "1. Add student" << endl;
    cout << "2. Print All (sorted by gpa)" << endl;
    cout << "3. Back" << endl;
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

        } else if (choice == 2) {
            for (auto &student: students) {
                student.print_info();
            }
        }
        else if (choice == 3)
            break;
        else {
            cout << "Invalid" << endl;
            continue;
        }
    }
}


void min_build_heap(vector<Student> &students) {

    for (int i = students.size() / 2 - 1; i >= 0; i--) {
        min_heapify(students, i, students.size());
    }
}

void min_heapify(vector<Student> &students, int i, int size) {
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

void open_file(vector<Student>& students)
{
    int num_of_students;
    string first_line;
    fstream file;
    int id;
    string name;
    float gpa;
    string department;
    string temp;
    string path;

    cout << "Enter the file path" << endl;
    cin >> path;
    file.open(path, ios::in);

    if (file.is_open())
    {
        cout <<  path << " is opened" << endl;
        getline(file, first_line);
        num_of_students = stoi(first_line); // convert first line from string to int

        for (int i = 0; i < num_of_students; i++) // for loop to loop the whole file depending on how many students
        {
            // get data for each student and then push it into students vector
            getline(file,temp);
            id = stoi(temp);
            getline(file, name);
            getline(file, temp);
            gpa = stof(temp);
            getline(file, department);

            Student student(id, name, gpa, department);

            students.push_back(student);
        }
        file.close();
    }
    else
        cout << "Problem opening the file" << endl;

}
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
            Node* root = AV.load_vector(students);
            AV.AVL_menu(root);
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






