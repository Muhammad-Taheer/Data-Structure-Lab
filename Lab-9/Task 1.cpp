#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = tail = newNode;
            return;
        }

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void insertAtStart(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = tail = newNode;
            return;
        }

        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void insertAtPosition(int position, int value) {

        if (position == 1) {
            insertAtStart(value);
            return;
        }

        Node* temp = head;

        for (int i = 1; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Invalid Position!" << endl;
            return;
        }

        if (temp->next == nullptr) {
            insertAtEnd(value);
            return;
        }

        Node* newNode = new Node(value);

        newNode->next = temp->next;
        newNode->prev = temp;

        temp->next->prev = newNode;
        temp->next = newNode;
    }

    void deleteByValue(int value) {

        if (head == nullptr) {
            cout << "List is Empty!" << endl;
            return;
        }

        Node* temp = head;

        while (temp != nullptr && temp->data != value) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Value not found!" << endl;
            return;
        }

        if (temp == head) {
            head = head->next;

            if (head != nullptr)
                head->prev = nullptr;
            else
                tail = nullptr;

            delete temp;
            return;
        }

        if (temp == tail) {
            tail = tail->prev;
            tail->next = nullptr;

            delete temp;
            return;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        delete temp;
    }

    void displayForward() {

        if (head == nullptr) {
            cout << "List is Empty!" << endl;
            return;
        }

        Node* temp = head;

        cout << "Forward Traversal: ";

        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    void displayReverse() {

        if (tail == nullptr) {
            cout << "List is Empty!" << endl;
            return;
        }

        Node* temp = tail;

        cout << "Reverse Traversal: ";

        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->prev;
        }

        cout << endl;
    }
};

int main() {

    DoublyLinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);

    cout << "After Insert At End:" << endl;
    list.displayForward();

    list.insertAtStart(5);

    cout << "\nAfter Insert At Start:" << endl;
    list.displayForward();

    list.insertAtPosition(3, 15);

    cout << "\nAfter Insert At Position:" << endl;
    list.displayForward();

    cout << endl;
    list.displayReverse();

    list.deleteByValue(20);

    cout << "\nAfter Deletion of 20:" << endl;
    list.displayForward();

    list.deleteByValue(5);

    cout << "\nAfter Deletion of First Node:" << endl;
    list.displayForward();

    list.deleteByValue(30);

    cout << "\nAfter Deletion of Last Node:" << endl;
    list.displayForward();

    cout << endl;
    list.displayReverse();

    return 0;
}