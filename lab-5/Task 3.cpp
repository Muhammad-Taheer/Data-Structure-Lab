#include <iostream>
using namespace std;

const int MAX = 100;

class Queue {
private:
    string arr[MAX];
    int front;
    int rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    bool isFull() {
        return rear == MAX - 1;
    }

    void enqueue(string x) {
        if (isFull()) return;

        if (front == -1) front = 0;

        arr[++rear] = x;
    }

    string dequeue() {
        if (isEmpty()) return "";

        string val = arr[front++];
        return val;
    }

    void display() {
        if (isEmpty()) {
            cout << "Empty\n";
            return;
        }

        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

class AirportSystem {
private:
    Queue emergency;
    Queue passenger;
    Queue cargo;

public:
    void enqueue(string type, string id) {
        if (type == "E") {
            emergency.enqueue(id);
        }
        else if (type == "P") {
            passenger.enqueue(id);
        }
        else {
            cargo.enqueue(id);
        }
    }

    void dequeue() {
        if (!emergency.isEmpty()) {
            cout << "Landing: " << emergency.dequeue() << endl;
        }
        else if (!passenger.isEmpty()) {
            cout << "Landing: " << passenger.dequeue() << endl;
        }
        else if (!cargo.isEmpty()) {
            cout << "Landing: " << cargo.dequeue() << endl;
        }
        else {
            cout << "No flights waiting\n";
        }
    }

    void display() {
        cout << "\nEmergency Queue: ";
        emergency.display();

        cout << "Passenger Queue: ";
        passenger.display();

        cout << "Cargo Queue: ";
        cargo.display();
    }
};

int main() {
    AirportSystem airport;
    int choice;
    string type, id;

    while (choice != 0) {
        cout << "1 Enqueue Flight" << endl;
        cout << "2 Land Flight" << endl;
        cout << "3 Display Queues" << endl;
        cout << "4 Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter type (E/P/C) and ID: ";
            cin >> type >> id;
            airport.enqueue(type, id);
        }
        else if (choice == 2) {
            airport.dequeue();
        }
        else if (choice == 3) {
            airport.display();
        }

    } while (choice != 4);

    return 0;
}