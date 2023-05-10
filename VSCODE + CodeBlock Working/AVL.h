#ifndef AVL_H
#define AVL_H

// original code here

#include <iostream>
#include <algorithm>
#include "Student.h"
#include <map>
using namespace std;
struct Node{
    int height ;
    int ID ;
    string Name ;
    double GPA;
    string Department;
    Node * left  ;
    Node * right ;

    Node(int ID , string name , double GPA, string department)
    {
        this->ID = ID;
        this->Name= name;
        this->GPA= GPA;
        this->Department=department;
        this->height = 1;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class AVL {
private:
    Node* root ;
    int total_students;
    int height(Node* node)
    {
        if(node == nullptr)
            return 0;
        else
            return node->height;
            
    }
    int getBalance(Node* node)
    {
        if(node ==nullptr)
            return 0;
        else
            return height(node->left) - height(node->right);
    }
    Node* leftRotate(Node* node)
    {
        Node* x = node->right;
        Node* y = x->left;

        x->left = node;
        node->right = y;

        node->height = max(height(node->left),  height(node->right)) + 1;
        x->height = max(height(x->left),  height(x->right)) + 1;
        return x ;
    }
    Node* rightRotate(Node* node)
    {
        Node* x = node->left;
        Node* y = x->right;

        x->right = node;
        node->left = y;

        node->height = max(height(node->left),  height(node->right)) + 1;
        x->height = max(height(x->left),  height(x->right)) + 1;
        return x;
    }
    bool isLeaf(Node * tmp)
    {
        if(tmp->right == nullptr && tmp->left == nullptr)
        {
            return true;
        }
        return false;
    }
    bool hasOneChild(Node * tmp)
    {
        int cnt = 0;
        if(tmp->right != nullptr)
            cnt++;
        if(tmp->left != nullptr)
            cnt++;
        return(cnt==1);
    }
    void preOrder(Node *root , vector<string>& Departments)
    {
        if(root == NULL) {
            return;
        }
        preOrder(root->left,Departments);
        cout << "[" << root->ID << ", " << root->Name << ", " << root->GPA << ", " << root->Department << "]" << endl;
        Departments.push_back(root->Department);
        preOrder(root->right,Departments);
    }

    Node* addStudent(Node *node, int ID, string name, double GPA, string dept) 
    {
        if (node == nullptr) {
            Node *temp = new Node(ID, name, GPA, dept);
            cout << "Student Added" << endl;
            total_students++;
            return temp;
        }
        if (ID < node->ID)
            node->left = addStudent(node->left, ID, name, GPA, dept);
        else if (ID > node->ID)
            node->right = addStudent(node->right, ID, name, GPA, dept);
        else{
            return node;
        }

        node->height = 1 + max(height(node->left), height(node->right));
        int balance = getBalance(node);
        // LL rotation
        if(balance > 1 && ID < node->left->ID) {
            return rightRotate(node);
        }
        // RR rotation
        else if(balance < -1 && ID > node->right->ID) {
            return leftRotate(node);
        }
        // LR rotation
        else if(balance > 1 && ID > node->left->ID) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        // RL rotation
        else if(balance < -1 && ID < node->right->ID) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }

    Node* deleteNode(struct Node* node, int ID)
    {
    
        if (node == NULL)
            return node;
    
        if ( ID < node->ID )
            node->left = deleteNode(node->left, ID);
        else if( ID > node->ID )
            node->right = deleteNode(node->right, ID);
        else
        {
            // node with only one child or no child
            total_students--;
            cout << "Studnet removed :)" << endl;
            if( isLeaf(node) || hasOneChild(node))
            {
                Node *temp = node->left ? node->left :node->right;
    
                // No child case
                if (temp == NULL)
                {
                    temp = node;
                    node = NULL;
                }
                else // One child case
                *node = *temp; 
                                
                delete (temp);
            }
            else
            {
                Node* minNodeRightSubTree = node->right;
                while (minNodeRightSubTree->left != nullptr)
                {
                    minNodeRightSubTree = minNodeRightSubTree->left;
                }
    
                node->ID = minNodeRightSubTree->ID;
                node->Name = minNodeRightSubTree->Name;
                node->GPA = minNodeRightSubTree->GPA;
                node->Department = minNodeRightSubTree->Department;
                node->right = deleteNode(node->right, minNodeRightSubTree->ID);
            }
        }
        // check to see if there is any unbalanced node
        if(node== nullptr)
            return nullptr;

        node->height = 1 + max(height(node->left),height(node->right));
        int balance = getBalance(node);
        if (balance > 1 && getBalance(node->left) >= 0)
        {
            return rightRotate(node);

        }
 
        if (balance > 1 && getBalance(node->left) < 0)
        {
            node->left =  leftRotate(node->left);
            return rightRotate(node);
        }
    
        if (balance < -1 && getBalance(node->right) <= 0)
        {
            return leftRotate(node);
        }
    

        if (balance < -1 && getBalance(node->right) > 0)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    Node* isFound(Node* root ,int ID)
    {
        if( root == nullptr)
        {
            return nullptr;
        }
        else if (root->ID == ID)
        {
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
    void PrintAllAVL(Node* root)
    {
        vector<string> departments;
        map<string , int> dept_count;
        cout <<"print " << total_students << " Students" << endl;
        preOrder(root,departments);
          for(string s : departments)
        {
           dept_count[s] ++;
        }
        for(auto it : dept_count)
        {
            cout <<it.first << " " << it.second << " students\n"; 
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




public:
    AVL() : root(nullptr),total_students(0) {};
    
    

     void AVL_menu(Node * r)
    {
        Node * root = r;
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
                    root  = addStudent(root , ID , Name , GPA , Dept);
                    break;
                }
                case 2 :
                {
                    cout <<"removing..." << endl;
                    int ID;
                    cout <<"ID: ";
                    cin >> ID;
                    root = deleteNode(root , ID);
                    break;
                }
                case 3:
                {
                    int ID;
                    cout <<"ID: ";
                    cin >> ID;
                    Node * temp = isFound(root ,ID);
                    if(temp!= nullptr)
                    {
                        cout <<"Student is Found! ";
                        cout << "[" << root->ID << ", " << root->Name << ", " << root->GPA << ", " << root->Department << "]" << endl;
                    }
                    else
                        cout <<"Studnet was not Found :(" << endl;
                    break;
                }
                case 4:
                {
                    PrintAllAVL(root);
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


    // load vector to AVL
    // loads the correct total number of students but doesn't print any students <--------------- FIX --------------->
    Node *load_vector(vector<Student> students)
    {
        Node *root = nullptr;
        for (int i = 0; i < students.size(); i++)
        {
            root = addStudent(root, students[i].get_id(), students[i].get_name(),students[i].get_gpa(), students[i].get_department());

        }
        return (root);
    }



};



#endif
