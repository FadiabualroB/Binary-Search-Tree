#include<iostream>
#include<string>
#include<fstream>
using namespace std;

const int max_size = 2;

struct node {
    int index;
    int data;
    int childCount;
    int children[max_size];
    int color;
    int bf;
    node* left;
    node* right;
};

node* createNode(int index, int data, int childCount, int children[max_size], int color, int bf)
{
    node* nnode = new node;

    nnode->index = index;
    nnode->data = data;
    nnode->childCount = childCount;
    for (size_t i = 0; i < childCount; i++)
    {
        nnode->children[i] = children[i];
    }
    nnode->color = color;
    nnode->bf = bf;
    nnode->left = NULL;
    nnode->right = NULL;

    return nnode;
}

void BSTBuild(node*& root, int index, int data, int childCount, int children[max_size], int color, int bf) {

    if (root == NULL)
    {
        root = createNode(index, data, childCount, children, color, bf);
        return;
    }
    if (data < root->data)
    {
        BSTBuild(root->left, index, data, childCount, children, color, bf);
    }
    else
    {
        BSTBuild(root->right, index, data, childCount, children, color, bf);
    }
}

void BSTPrint(node* root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->index;
    cout << " " << root->data;
    cout << " " << root->childCount;
    cout << " ";
    for (size_t i = 0; i < root->childCount; i++)
    {
        cout << root->children[i] << " ";

    }
    cout << root->color;
    cout << " " << root->bf;
    cout << endl;
    BSTPrint(root->left);
    BSTPrint(root->right);
}

int findClosest(node* root, double target)
{
    int closest = root->data;

    while (root != NULL)
    {
        if (abs(target - closest) > abs(target - double(root->data)))
        {
            closest = root->data;
        }
        else if (target < double(root->data))
        {
            root = root->left;
        }
        else if (target > double(root->data))
        {
            root = root->right;
        }
        else
        {
            break;
        }
    }
    return closest;
}

int BSTheight(node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + max(BSTheight(root->left), BSTheight(root->right));
}

void BFUpdate(node* root)
{
    if (root == NULL)
    {
        return;
    }
    root->bf = BSTheight(root->right) - BSTheight(root->left);
    BFUpdate(root->left);
    BFUpdate(root->right);
}

node* BSTMerge(node* root1, node* root2)
{
    if (root1 == NULL)
    {
        return root2;
    }
    if (root2 == NULL)
    {
        return root1;
    }
    node* root;
    root = new node{ root1->data + root2->data };
    root->left = BSTMerge(root1->left, root2->left);
    root->right = BSTMerge(root1->right, root2->right);
    return root;
}

void printMenu()
{
    cout <<"    1. Find Closest in Tree1 " << endl;
    cout <<"    2. Find Height in Tree1" << endl;
    cout <<"    3. Update Balance Factor in Tree1" << endl;
    cout <<"    4.Merge Two Trees" << endl;

}

int main() {
    int ch;
    //Reading Tree 1
    ifstream file("BST.txt");

    if (!file.is_open())
    {
        cout << "Error opening file!" << endl;
        return 1;
    }
    node* tree1 = NULL;

    int index;
    int data;
    int childCount;
    int children[max_size];
    int color;
    int bf;

    while (!file.eof())
    {
        file >> index;
        file >> data;
        file >> childCount;
        for (size_t i = 0; i < childCount; i++)
        {
            file >> children[i];
        }
        file >> color;
        file >> bf;
        BSTBuild(tree1, index, data, childCount, children, color, bf);
    }
    file.close();

    cout << "----------Tree1--------------" << endl;
    BSTPrint(tree1);
    cout << endl;

    //Reading Tree2.
    ifstream file2("BST2.txt");
    if (!file2.is_open()) {
        cout << "Error opening file!" << endl;
        return 1;
    }
    node* tree2 = NULL;
    int index2;
    int data2;
    int childCount2;
    int children2[max_size];
    int color2;
    int bf2;

    while (!file2.eof())
    {
        file2 >> index2;
        file2 >> data2;
        file2 >> childCount2;
        for (size_t i = 0; i < childCount2; i++)
        {
            file2 >> children2[i];
        }
        file2 >> color2;
        file2 >> bf2;
        BSTBuild(tree2, index2, data2, childCount2, children2, color2, bf2);
    }
    cout << "----------Tree2--------------" << endl;
    BSTPrint(tree2);
    cout << endl;

    int flag = true;
    while (flag)
    {
        cout << "Select from Menu!" << endl;
        printMenu();
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "-----------Find Closest-------------" << endl;
            double number;
            cout << "Enter Number! " << endl;
            cin >> number;
            cout<<"The closest number to "<<number <<"is:  "<< findClosest(tree1, number) << endl;
            cout << endl;
            break;
        case 2:
            cout << "----------Tree Height--------------" << endl;
            cout << "Tree Height is: " << BSTheight(tree1)<<endl;
            cout << endl;
            break;
        case 3:
            cout << "------------Update Balance Factor------------" << endl;
            BFUpdate(tree1);
            cout << endl;
            BSTPrint(tree1);  
            cout << endl;
            break;
        case 4:
            cout << "---------Merge Two Trees---------------" << endl;
            node* merged_tree = BSTMerge(tree1, tree2);
            BSTPrint(merged_tree);
            cout << endl;
            break;
        }
    }
    return 0;
}