#include <iostream>
#include <string>
#include <stack>

using namespace std;

struct exprnode {
    string data;
    exprnode* left;
    exprnode* right;

    exprnode(string val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

void printinfix(exprnode* root) {
    if (root == nullptr) return;

    bool isop = (root->data == "+" || root->data == "-" || root->data == "*");

    if (isop) cout << "(";

    printinfix(root->left);

    cout << root->data;

    if (isop) cout << " ";

    printinfix(root->right);

    if (isop) cout << ")";
}

void printprefix(exprnode* root) {
    if (root == nullptr) return;

    cout << root->data << " ";

    printprefix(root->left);
    printprefix(root->right);
}

void printpostfix(exprnode* root) {
    if (root == nullptr) return;

    printpostfix(root->left);
    printpostfix(root->right);

    cout << root->data << " ";
}

int evaluate(exprnode* root) {
    if (root == nullptr) return 0;

    if (root->left == nullptr && root->right == nullptr) {
        return stoi(root->data);
    }

    int l = evaluate(root->left);
    int r = evaluate(root->right);

    if (root->data == "+") return l + r;
    if (root->data == "-") return l - r;
    if (root->data == "*") return l * r;

    return 0;
}

int main() {
    string postfixtokens[] = {"3", "5", "+", "8", "2", "-", "*"};

    int size = sizeof(postfixtokens) / sizeof(postfixtokens[0]);

    stack<exprnode*> s;

    for (int i = 0; i < size; i++) {
        string token = postfixtokens[i];

        if (token != "+" && token != "-" && token != "*") {
            exprnode* operandnode = new exprnode(token);

            s.push(operandnode);
        }

        else {
            exprnode* operatornode = new exprnode(token);

            exprnode* rightchild = s.top();
            s.pop();

            exprnode* leftchild = s.top();
            s.pop();

            operatornode->right = rightchild;
            operatornode->left = leftchild;

            s.push(operatornode);
        }
    }

    exprnode* root = s.top();
    s.pop();

    cout << "infix expression: ";
    printinfix(root);
    cout << endl;

    cout << "prefix expression: ";
    printprefix(root);
    cout << endl;

    cout << "postfix expression: ";
    printpostfix(root);
    cout << endl;

    cout << "final answer: " << evaluate(root) << endl;

    return 0;
}