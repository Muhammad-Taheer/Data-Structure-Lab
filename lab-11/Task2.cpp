#include <iostream>

using namespace std;

struct node {
    int data;
    node* left;
    node* right;

    node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

void inorder(node* root) {
    if (root == nullptr) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(node* root) {
    if (root == nullptr) return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    node* root = new node(40);
    node* n20 = new node(20);
    node* n60 = new node(60);
    node* n10 = new node(10);
    node* n30 = new node(30);
    node* n50 = new node(50);
    node* n70 = new node(70);

    root->left = n20;
    root->right = n60;

    n20->left = n10;
    n20->right = n30;

    n60->left = n50;
    n60->right = n70;

    cout << "inorder traversal: ";
    inorder(root);
    cout << endl;

    cout << "preorder traversal: ";
    preorder(root);
    cout << endl;

    return 0;
}