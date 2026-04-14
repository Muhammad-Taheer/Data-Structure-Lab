#include <iostream>
#include <stack>
using namespace std;

class myqueue {
private:
    stack<int> s1, s2;

public:
    void enqueue(int value) {
        s1.push(value);
    }

    int dequeue() {
        if (isempty()) {
            cout << "queue is empty\n";
            return -1;
        }

        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        int value = s2.top();
        s2.pop();
        return value;
    }

    int front() {
        if (isempty()) {
            cout << "queue is empty\n";
            return -1;
        }

        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        return s2.top();
    }

    bool isempty() {
        return s1.empty() && s2.empty();
    }

    void display() {
        if (isempty()) {
            cout << "queue is empty\n";
            return;
        }

        stack<int> temp1 = s1;
        stack<int> temp2 = s2;

        while (!temp2.empty()) {
            cout << temp2.top() << " ";
            temp2.pop();
        }

        stack<int> reverse;
        while (!temp1.empty()) {
            reverse.push(temp1.top());
            temp1.pop();
        }

        while (!reverse.empty()) {
            cout << reverse.top() << " ";
            reverse.pop();
        }

        cout << endl;
    }
};

int main() {
    myqueue q;
    int choice = -1, value;

    while (choice != 0) {
        cout << "1 enqueue" << endl;
        cout << "2 dequeue" << endl;
        cout << "3 front" <<endl;
        cout << "4 display" << endl;
        cout << "0 exit" << endl;;
        cin >> choice;

        switch (choice) {
        case 1:
            cin >> value;
            q.enqueue(value);
            break;
        case 2:
            cout << q.dequeue() << endl;
            break;
        case 3:
            cout << q.front() << endl;
            break;
        case 4:
            q.display();
            break;
        }
    }

    return 0;
}