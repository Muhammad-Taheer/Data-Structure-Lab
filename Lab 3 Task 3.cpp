#include <iostream>
#include <string>
using namespace std;

class mycarstack {
private:
    string arr[8];
    int topindex;

public:
    mycarstack() {
        topindex = -1;
    }

    bool isempty() {
        return topindex == -1;
    }

    bool isfull() {
        return topindex == 7;
    }

    void push(string car) {
        if (isfull()) {
            cout << "parking full!" << endl;
            return;
        }
        arr[++topindex] = car;
        cout << "car parked: " << car << endl;
    }

    string pop() {
        if (isempty()) {
            cout << "parking empty!" << endl;
            return "";
        }
        return arr[topindex--];
    }

    string top() {
        if (isempty()) return "";
        return arr[topindex];
    }

    int count() {
        return topindex + 1;
    }

    void display() {
        if (isempty()) {
            cout << "no cars parked!" << endl;
            return;
        }

        cout << "cars in parking (top to bottom): ";
        for (int i = topindex; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // search car
    bool search(string car) {
        for (int i = 0; i <= topindex; i++) {
            if (arr[i] == car)
                return true;
        }
        return false;
    }

    // remove specific car
    void removecar(string car) {
        if (isempty()) {
            cout << "parking empty!" << endl;
            return;
        }

        mycarstack temp;
        bool found = false;

        // remove until we find the car
        while (!isempty()) {
            string current = pop();

            if (current == car) {
                cout << "car removed: " << car << endl;
                found = true;
                break;
            } else {
                temp.push(current);
            }
        }

        if (!found) {
            cout << "car not found!" << endl;
        }

        // put back cars
        while (!temp.isempty()) {
            push(temp.pop());
        }
    }
};

int main() {
    mycarstack parking;
    int choice;
    string car;

    do {
        cout << "\n--- parking menu ---" << endl;
        cout << "1. park new car" << endl;
        cout << "2. remove car" << endl;
        cout << "3. show all cars" << endl;
        cout << "4. total cars" << endl;
        cout << "5. search car" << endl;
        cout << "6. show top car" << endl;
        cout << "7. exit" << endl;
        cout << "enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "enter car number: ";
            cin >> car;
            parking.push(car);
            break;

        case 2:
            cout << "enter car number to remove: ";
            cin >> car;
            parking.removecar(car);
            break;

        case 3:
            parking.display();
            break;

        case 4:
            cout << "total cars: " << parking.count() << endl;
            break;

        case 5:
            cout << "enter car number to search: ";
            cin >> car;
            if (parking.search(car))
                cout << "car found!" << endl;
            else
                cout << "car not found!" << endl;
            break;

        case 6:
            cout << "top car: " << parking.top() << endl;
            break;

        case 7:
            cout << "exiting..." << endl;
            break;

        default:
            cout << "invalid choice!" << endl;
        }

    } while (choice != 7);

    return 0;
}