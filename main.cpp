#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using namespace std;

// Class to contain each student info

class Student
{

private:
    int id;
    string name;
    float gpa;
    string department;

public:


    Student(int id, string name, float gpa, string department)
    {
        this->id = id;
        this->name = name;
        this->gpa = gpa;
        this->department = department;
    }

    void print_info()
    {
        cout << "----------------------------------------" << endl;
        cout << "Student ID is: " << id << endl;
        cout << "Student name is: " << name << endl;
        cout << "Student gpa is: " << gpa << endl;
        cout << "Student department is: " << department << endl;
        cout << "----------------------------------------" << endl;

    }

    void swap (Student &other)
    {
        this->id = other.id;
        this->name = other.name;
        this->gpa = other.gpa;
        this->department = other.department;
    }

    float get_gpa()
    {
        return (gpa);
    }

};

/**
 * open_file - function that loads all the students in a file into a vector of type student
 *
 * @param students
 *
 * @return void
 */

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
    getline(cin,path);

    file.open(path, ios::in);

    if (file.is_open())
    {
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


int main() {

    vector<Student> students;


// menu

    print_menu(students);

// Simple interface that takes the path of the file from the user


//    Student s1(1, "Youssef", 3.0, "IS");
//    s1.print_info();

//    students[0].print_info();
//    students[1].print_info();

//    for (int i = 0; i < 10; i++)
//    {
//        students[i].print_info();
//    }


    return 0;
}
