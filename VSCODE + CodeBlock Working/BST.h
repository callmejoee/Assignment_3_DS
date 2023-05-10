#ifndef BST_H
#define BST_H
#include <iostream>
#include<string>
#include <vector>
#include "Student.h"

using namespace std;
struct NODE{
    int ID ;
    string Name ;
    double GPA;
    string Department;
    NODE * left =nullptr ;
    NODE * right = nullptr;

    NODE(int ID , string name , double GPA, string department)
    {
        this->ID = ID;
        this->Name= name;
        this->GPA= GPA;
        this->Department=department;
    }
};

class BST {
private:
    NODE* root;
    int Student_number;
    void BSTInorder(NODE* root) {
        if(root == NULL) {
            return;
        }
        BSTInorder(root->left);
        cout << "[" << root->ID << ", " << root->Name << ", " << root->GPA << ", " << root->Department << "]" << endl;
        BSTInorder(root->right);
    }
    bool isLeaf(NODE * tmp)
    {
        if(tmp->right == nullptr && tmp->left == nullptr)
        {
            return true;
        }
        return false;
    }
    bool hasOneChild(NODE * tmp)
    {
        int cnt = 0;
        if(tmp->right != nullptr)
            cnt++;
        if(tmp->left != nullptr)
            cnt++;
        return(cnt==1);
    }
    NODE* getParent(NODE* node, int ID) {
        if(root->ID == ID)
        {
            return nullptr;
        }

        if (node == nullptr) {
            return nullptr;
        }
        if (node->right != nullptr && node->right->ID == ID) {
            return node;
        }
        if (node->left != nullptr && node->left->ID == ID) {
            return node;
        }
        if (node->ID > ID) {
            return getParent(node->left, ID);
        }
        else {
            return getParent(node->right, ID);
        }
    }
    void option()
    {
        cout << " 1 to add new student"
            "\n 2 to remove student"
            "\n 3 to search for student"
            "\n 4 print all student(sorted by IDs)"
            "\n 5 return to main menue: ";
    }
    void addStudent( NODE*& node  ,int ID , string name , double GPA , string dept)
    {
       
        if(node == nullptr)
        {
            node = new NODE(ID, name ,GPA ,dept);
            Student_number++;
            cout << "Student Added" << endl;
            return;
        }
        if(ID > node->ID)
        {
            addStudent(node->right , ID ,name , GPA , dept);
        }
        else
        {
            addStudent(node->left , ID ,name , GPA , dept);
        }
    }
    void printAllBST()
    {
        cout <<"print " << Student_number << " Students" << endl;
        BSTInorder(root);
    }

    void removeStudent(int ID)
    {
        NODE* toBeRemoved = isFound(root ,ID);
        if(toBeRemoved!= nullptr)
        {
            if(isLeaf(toBeRemoved))
            {
                if(root == toBeRemoved)
                {
                    root = nullptr;
                }
                else
                {
                    NODE * parent = getParent(root , toBeRemoved->ID);
                    if (parent->right == toBeRemoved) {
                        parent->right = nullptr;
                    } else {
                        parent->left = nullptr;
                    }
                }
                delete toBeRemoved;
            }
            else if(hasOneChild(toBeRemoved))
            {
                NODE * parent = getParent(root , toBeRemoved->ID);
                if(parent == nullptr)
                {
                   if(toBeRemoved->right != nullptr)
                   {
                       root = toBeRemoved->right;
                   }
                   else
                   {
                       root = toBeRemoved->left;
                   }
                }
                else
                {
                    NODE * child ;
                    if(toBeRemoved->right != nullptr)
                    {
                        child = toBeRemoved->right;
                    }
                    else
                    {
                        child = toBeRemoved->left;
                    }

                    if(parent ->right == toBeRemoved)
                    {
                        parent->right = child;
                    }
                    else
                    {
                        parent->left = child;
                    }
                    toBeRemoved->right = nullptr;
                    toBeRemoved->left = nullptr;

                }
                delete toBeRemoved; // Delete the node from memory
                toBeRemoved = nullptr;

            }
            else // node has two children
            {
                NODE* minNodeRightSubTree = toBeRemoved->right;
                while (minNodeRightSubTree->left != nullptr)
                {
                    minNodeRightSubTree = minNodeRightSubTree->left;
                }
                int ID = minNodeRightSubTree->ID;
                toBeRemoved->Name = minNodeRightSubTree->Name;
                toBeRemoved->GPA = minNodeRightSubTree->GPA;
                toBeRemoved->Department = minNodeRightSubTree->Department;
                removeStudent(ID);
                toBeRemoved->ID = ID;
                return;
            }
            Student_number--;
            cout << "Student is Deleted" << endl;
        }
    }

    NODE* isFound(NODE* root ,int ID)
        {
            if( root == nullptr)
            {
                cout <<"Student was not found" << endl;
                return nullptr;
            }
            else if (root->ID == ID)
            {
                cout <<"Student is found" << endl;
                cout << "[" << root->ID << ", " << root->Name << ", " << root->GPA << ", " << root->Department << "]" << endl;
                return root;
            }
            else if(root->ID > ID)
            {
                isFound(root->left , ID);
            }
            else
            {
                isFound(root->right , ID);
            }
        }

    NODE*& Get_Root()
    {
        return root;
    }

public:

    BST():root (nullptr) , Student_number(0){};
    void BST_menu()
    {
        int choice = 0;
         do
        {
            option();
            cin>>choice;
            switch (choice) {
                case 1:
                {
                    int ID;
                    cout <<"ID: ";
                    cin >> ID;
                    string Name;
                    cout <<"Name: ";
                    getline(cin>>ws , Name);
                    double GPA;
                    cout <<"GPA: ";
                    cin >> GPA;
                    string Dept;
                    cout <<"Department: ";
                    cin >> Dept;
                    addStudent(Get_Root(),ID,Name,GPA,Dept);
                    break;
                }
                case 2 :
                {
                    cout <<"removing..." << endl;
                    int ID;
                    cout <<"ID: ";
                    cin >> ID;
                    removeStudent(ID);
                    break;
                }
                case 3:
                {
                    int ID;
                    cout <<"ID: ";
                    cin >> ID;
                    if(isFound(Get_Root(), ID))
                        cout << "Student exists." << endl;
                    else 
                        cout << "Student does not exist." << endl;
                    break;
                }
                case 4:
                {
                    printAllBST();
                    break; // added break statement
                }
                case 5:
                    break;
                default:
                    cout <<"invalid input try again:) " << endl;
                    break; // added break statement

            }
        }while (choice !=5); // do-while loop to ensure the loop runs at least once
    }

    // function to load the data to the BST class

    void load_vector(vector<Student> students)
    {
        for (int i = 0; i < students.size(); i++)
        {
            this->addStudent(this->Get_Root(), students[i].get_id(), students[i].get_name(),students[i].get_gpa(), students[i].get_department());

        }
    }

    
};


#endif