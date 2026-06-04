#include <iostream>
#include <string>
using namespace std;

class bstnode {
public:
    int isbn;
    string title;
    bstnode* left;
    bstnode* right;

    bstnode(int i, string t) {
        isbn = i;
        title = t;
        left = nullptr;
        right = nullptr;
    }
};

class listnode {
public:
    int isbn;
    string title;
    listnode* next;

    listnode(int i, string t) {
        isbn = i;
        title = t;
        next = nullptr;
    }
};

bstnode* insertbst(bstnode* root, int isbn, string title) {
    if (root == nullptr)
        return new bstnode(isbn, title);

    if (isbn < root->isbn)
        root->left = insertbst(root->left, isbn, title);
    else if (isbn > root->isbn)
        root->right = insertbst(root->right, isbn, title);

    return root;
}

void bsttolinkedlist(bstnode* root, listnode*& head, listnode*& tail) {
    if (root == nullptr)
        return;

    bsttolinkedlist(root->left, head, tail);

    listnode* newnode = new listnode(root->isbn, root->title);

    if (head == nullptr) {
        head = newnode;
        tail = newnode;
    }
    else {
        tail->next = newnode;
        tail = newnode;
    }

    bsttolinkedlist(root->right, head, tail);
}

void printlinkedlist(listnode* head) {
    while (head != nullptr) {
        cout << "isbn: " << head->isbn
            << ", title: " << head->title << endl;
        head = head->next;
    }
}

int main() {
    bstnode* root = nullptr;
    listnode* head = nullptr;
    listnode* tail = nullptr;

    int n;

    cout << "enter number of books: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int isbn;
        string title;

        cout << "\nenter isbn: ";
        cin >> isbn;

        cin.ignore();

        cout << "enter title: ";
        getline(cin, title);

        root = insertbst(root, isbn, title);
    }

    bsttolinkedlist(root, head, tail);

    cout << "\nsorted book catalog:\n";
    printlinkedlist(head);

    return 0;
}