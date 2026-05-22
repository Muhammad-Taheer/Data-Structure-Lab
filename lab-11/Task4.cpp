#include <iostream>
#include <stack>

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

void dfs(node* root) {
    if (root == nullptr) return;

    stack<node*> s;

    s.push(root);

    while (!s.empty()) {
        node* current = s.top();
        s.pop();

        cout << current->data << " ";

        if (current->right != nullptr) {
            s.push(current->right);
        }

        if (current->left != nullptr) {
            s.push(current->left);
        }
    }
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

    cout << "dfs traversal: ";
    dfs(root);
    cout << endl;

    return 0;
}