#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node* prev;

    node(int value) {
        data = value;
        next = NULL;
        prev = NULL;
    }
};

class doublylinkedlist {
private:
    node* head;
    node* tail;

    node* insertendrecursive(node* temp, int value) {
        if (temp == NULL) {
            node* newnode = new node(value);
            tail = newnode;
            return newnode;
        }

        if (temp->next == NULL) {
            node* newnode = new node(value);
            temp->next = newnode;
            newnode->prev = temp;
            tail = newnode;
            return temp;
        }

        temp->next = insertendrecursive(temp->next, value);
        return temp;
    }

    node* insertpositionrecursive(node* temp, int pos, int value) {
        if (pos == 1) {
            node* newnode = new node(value);
            newnode->next = temp;

            if (temp != NULL)
                temp->prev = newnode;

            if (temp == head)
                head = newnode;

            return newnode;
        }

        if (temp == NULL) {
            return NULL;
        }

        temp->next = insertpositionrecursive(temp->next, pos - 1, value);

        if (temp->next != NULL)
            temp->next->prev = temp;

        return temp;
    }

    node* deletevaluerrecursive(node* temp, int value) {
        if (temp == NULL)
            return NULL;

        if (temp->data == value) {
            node* nextnode = temp->next;

            if (nextnode != NULL)
                nextnode->prev = temp->prev;

            if (temp == tail)
                tail = temp->prev;

            delete temp;
            return nextnode;
        }

        temp->next = deletevaluerrecursive(temp->next, value);

        if (temp->next != NULL)
            temp->next->prev = temp;

        return temp;
    }

    node* deletepositionrecursive(node* temp, int pos) {
        if (temp == NULL)
            return NULL;

        if (pos == 1) {
            node* nextnode = temp->next;

            if (nextnode != NULL)
                nextnode->prev = NULL;

            if (temp == tail)
                tail = nextnode;

            delete temp;
            return nextnode;
        }

        temp->next = deletepositionrecursive(temp->next, pos - 1);

        if (temp->next != NULL)
            temp->next->prev = temp;

        return temp;
    }

    int searchrecursive(node* temp, int value, int pos) {
        if (temp == NULL)
            return -1;

        if (temp->data == value)
            return pos;

        return searchrecursive(temp->next, value, pos + 1);
    }

    void printforwardrecursive(node* temp) {
        if (temp == NULL)
            return;

        cout << temp->data << " ";
        printforwardrecursive(temp->next);
    }

    void printreverserecursive(node* temp) {
        if (temp == NULL)
            return;

        cout << temp->data << " ";
        printreverserecursive(temp->prev);
    }

    bool palindromerecursive(node* left, node* right) {
        if (left == right)
            return true;

        if (left->prev == right)
            return true;

        if (left->data != right->data)
            return false;

        return palindromerecursive(left->next, right->prev);
    }

public:
    doublylinkedlist() {
        head = NULL;
        tail = NULL;
    }

    void insertbeginning(int value) {
        node* newnode = new node(value);

        if (head == NULL) {
            head = tail = newnode;
        }
        else {
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }

        printforward();
    }

    void insertend(int value) {
        head = insertendrecursive(head, value);
        printforward();
    }

    void insertposition(int pos, int value) {
        if (pos <= 0) return;

        head = insertpositionrecursive(head, pos, value);

        if (tail == NULL)
            tail = head;

        printforward();
    }

    void deletevalue(int value) {
        if (search(value) == -1)
            return;

        head = deletevaluerrecursive(head, value);
        printforward();
    }

    void deleteposition(int pos) {
        if (pos <= 0)
            return;

        head = deletepositionrecursive(head, pos);
        printforward();
    }

    int search(int value) {
        return searchrecursive(head, value, 1);
    }

    void printforward() {
        if (head == NULL)
            return;

        printforwardrecursive(head);
        cout << endl;
    }

    void printreverse() {
        if (tail == NULL)
            return;

        printreverserecursive(tail);
        cout << endl;
    }

    bool ispalindrome() {
        if (head == NULL || head->next == NULL)
            return true;

        return palindromerecursive(head, tail);
    }
};

int main() {
    doublylinkedlist dll;

    dll.insertbeginning(1);
    dll.insertend(2);
    dll.insertend(3);
    dll.insertend(2);
    dll.insertend(1);

    dll.printforward();
    dll.printreverse();

    cout << dll.search(3) << endl;
    cout << dll.ispalindrome() << endl;

    dll.deletevalue(3);
    dll.deleteposition(2);

    return 0;
}