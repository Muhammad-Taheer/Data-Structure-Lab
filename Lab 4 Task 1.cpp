#include <iostream>
using namespace std;

template <typename t>
class abstractqueue {
public:
    virtual void enqueue(t value) = 0;
    virtual t dequeue() = 0;
    virtual t front() const = 0;
    virtual bool isempty() const = 0;
    virtual bool isfull() const = 0;
    virtual ~abstractqueue() {}
};

template <typename t>
class myqueue : public abstractqueue<t> {
private:
    t* arr;
    int frontindex, rearindex, capacity;

public:
    myqueue(int cap) {
        capacity = cap;
        arr = new t[capacity];
        frontindex = -1;
        rearindex = -1;
    }

    ~myqueue() {
        delete[] arr;
    }

    void enqueue(t value) {
        if (isfull()) {
            cout << "queue is full\n";
            return;
        }

        if (isempty()) {
            frontindex = 0;
        }

        rearindex++;
        arr[rearindex] = value;
    }

    t dequeue() {
        if (isempty()) {
            cout << "queue is empty\n";
            return -1;
        }

        t value = arr[frontindex];
        frontindex++;

        if (frontindex > rearindex) {
            frontindex = rearindex = -1;
        }

        return value;
    }

    t front() const {
        if (isempty()) {
            cout << "queue is empty\n";
            return -1;
        }
        return arr[frontindex];
    }

    bool isempty() const {
        return frontindex == -1;
    }

    bool isfull() const {
        return rearindex == capacity - 1;
    }

    void display() const {
        if (isempty()) {
            cout << "queue is empty\n";
            return;
        }

        for (int i = frontindex; i <= rearindex; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int cap;
    cin >> cap;

    myqueue<int> q(cap);

    int choice = -1, value;

    while (choice != 0) {
        cout << "1. EnQueue" << endl;
        cout << "2. DeQueue" << endl;
        cout << "3. Front" << endl;
        cout << "4. Check Empty" << endl;
        cout << "5. Check Full" << endl;
        cout << "6. Display" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
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
            cout << q.isempty() << endl;
            break;
        case 5:
            cout << q.isfull() << endl;
            break;
        case 6:
            q.display();
            break;
        }
    }

    return 0;
}