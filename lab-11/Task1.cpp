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

void printleafnodes(node* root) {
    if (root == nullptr) {
        return;
    }

    if (root->left == nullptr && root->right == nullptr) {
        cout << root->data << " ";
        return;
    }

    printleafnodes(root->left);
    printleafnodes(root->right);
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

    cout << "root node: " << root->data << endl;
    cout << "left child of root: " << root->left->data << endl;
    cout << "right child of root: " << root->right->data << endl;

    cout << "leaf nodes: ";
    printleafnodes(root);
    cout << endl;

    return 0;
}