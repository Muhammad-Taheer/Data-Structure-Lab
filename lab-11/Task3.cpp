#include <iostream>
#include <queue>

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

void bfs(node* root) {
    if (root == nullptr) return;

    queue<node*> q;

    q.push(root);

    while (!q.empty()) {
        node* current = q.front();
        q.pop();

        cout << current->data << " ";

        if (current->left != nullptr) {
            q.push(current->left);
        }

        if (current->right != nullptr) {
            q.push(current->right);
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

    cout << "bfs / level-order traversal: ";
    bfs(root);
    cout << endl;

    return 0;
}