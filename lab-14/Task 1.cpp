#include <iostream>
using namespace std;

struct node
{
    int data;
    node* left;
    node *right;

    node(int value)
    {
        data = value;
        left = right = nullptr;
    }
};

node* insert(node* root, int value)
{
    if (root == nullptr)
        return new node(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

node* findmin(node* root)
{
    while (root->left != nullptr)
        root = root->left;
    return root;
}

node* deletenode(node* root, int value)
{
    if (root == nullptr)
        return root;

    if (value < root->data)
        root->left = deletenode(root->left, value);
    else if (value > root->data)
        root->right = deletenode(root->right, value);
    else
    {
        if (root->left == nullptr)
        {
            node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            node* temp = root->left;
            delete root;
            return temp;
        }

        node* temp = findmin(root->right);
        root->data = temp->data;
        root->right = deletenode(root->right, temp->data);
    }

    return root;
}

void inorder(node* root)
{
    if (root != nullptr)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main()
{
    node* root = nullptr;

    int values[] = { 50, 30, 70, 20, 40, 60, 80 };

    for (int value : values)
        root = insert(root, value);

    cout << "after insertion: ";
    inorder(root);
    cout << endl;

    root = deletenode(root, 70);

    cout << "after deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}