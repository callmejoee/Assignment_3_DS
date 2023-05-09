#include <queue>
using namespace std;
struct Node{
    int ID ;
    string Name ;
    double GPA;
    string Department;
    Node * left =nullptr ;
    Node * right = nullptr;

    Node(int ID , string name , double GPA, string department)
    {
        this->ID = ID;
        this->Name= name;
        this->GPA= GPA;
        this->Department=department;
    }

};

class BST
{
private:
    Node* root;
    int Student_number;
public:

    BST():root (nullptr) , Student_number(0){};


    void addStudent( Node*& node  ,int ID , string name , double GPA , string dept)
    {
       
        if(node == nullptr)
        {
            node = new Node(ID, name ,GPA ,dept);
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
    void BSTInorder(Node* root) {
        if(root == NULL) {
            return;
        }
        BSTInorder(root->left);
        cout << "[" << root->ID << ", " << root->Name << ", " << root->GPA << ", " << root->Department << "]" << endl;
        BSTInorder(root->right);
    }
    void printAllBST()
    {
        cout <<"print " << Student_number << " Students" << endl;
        BSTInorder(root);
    }

    void removeStudent(int ID)
    {
        Node* toBeRemoved = isFound(root ,ID);
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
                    Node * parent = getParent(root , toBeRemoved->ID);
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
                Node * parent = getParent(root , toBeRemoved->ID);
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
                    Node * child ;
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
                Node* minNodeRightSubTree = toBeRemoved->right;
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
Node* isFound(Node* root ,int ID)
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
Node* getParent(Node* node, int ID) {
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



    Node*& Get_Root()
    {
        return root;
    }
};


