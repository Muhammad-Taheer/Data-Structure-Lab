#include <iostream>
#include <string>

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

    bool isoperator = (root->data == "+" || root->data == "-" || root->data == "*");

    if (isoperator) cout << "(";

    printinfix(root->left);

    cout << root->data;

    if (root->data == "+" || root->data == "-" || root->data == "*") {
        cout << " ";
    }

    printinfix(root->right);

    if (isoperator) cout << ")";
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

    int leftval = evaluate(root->left);
    int rightval = evaluate(root->right);

    if (root->data == "+") {
        cout << leftval << " + " << rightval << " = " << (leftval + rightval) << endl;
        return leftval + rightval;
    }

    if (root->data == "-") {
        cout << leftval << " - " << rightval << " = " << (leftval - rightval) << endl;
        return leftval - rightval;
    }

    if (root->data == "*") {
        cout << leftval << " * " << rightval << " = " << (leftval * rightval) << endl;
        return leftval * rightval;
    }

    return 0;
}

int main() {
    exprnode* root = new exprnode("*");
    exprnode* opplus = new exprnode("+");
    exprnode* opminus = new exprnode("-");

    exprnode* n3 = new exprnode("3");
    exprnode* n5 = new exprnode("5");
    exprnode* n8 = new exprnode("8");
    exprnode* n2 = new exprnode("2");

    root->left = opplus;
    root->right = opminus;

    opplus->left = n3;
    opplus->right = n5;

    opminus->left = n8;
    opminus->right = n2;

    cout << "infix expression: ";
    printinfix(root);
    cout << endl;

    cout << "prefix expression: ";
    printprefix(root);
    cout << endl;

    cout << "postfix expression: ";
    printpostfix(root);
    cout << endl;

    cout << "evaluation:" << endl;

    int finalanswer = evaluate(root);

    cout << "final answer: " << finalanswer << endl;

    return 0;
}