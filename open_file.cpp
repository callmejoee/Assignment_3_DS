//
// Created by Youssef on 5/8/2023.
//

#include "main.h"



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

