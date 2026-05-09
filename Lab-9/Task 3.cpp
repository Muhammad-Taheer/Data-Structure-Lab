#include <iostream>
using namespace std;

class Node {
public:
    int playerID;
    int score;
    Node* next;

    Node(int id, int s) {
        playerID = id;
        score = s;
        next = nullptr;
    }
};

class CircularLinkedList {
private:
    Node* tail;
    Node* current;

public:
    CircularLinkedList() {
        tail = nullptr;
        current = nullptr;
    }

    void addPlayer(int id, int score) {

        Node* newNode = new Node(id, score);

        if (tail == nullptr) {
            tail = newNode;
            tail->next = tail;
            current = tail;
        }

        else {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }

        cout << "Player " << id << " Added Successfully!" << endl;
    }

    void displayPlayers() {

        if (tail == nullptr) {
            cout << "No Players in Game!" << endl;
            return;
        }

        Node* temp = tail->next;

        cout << "\n----- Players List -----" << endl;

        do {
            cout << "Player ID: " << temp->playerID
                 << " | Score: " << temp->score << endl;

            temp = temp->next;

        } while (temp != tail->next);

        cout << "------------------------" << endl;
    }

    void nextTurn() {

        if (current == nullptr) {
            cout << "No Players Available!" << endl;
            return;
        }

        current = current->next;

        cout << "Current Turn -> Player "
             << current->playerID << endl;
    }

    void skipPlayer() {

        if (current == nullptr) {
            cout << "No Players Available!" << endl;
            return;
        }

        cout << "Skipping Player "
             << current->next->playerID << endl;

        current = current->next->next;

        cout << "Now Turn -> Player "
             << current->playerID << endl;
    }

    void removePlayer(int id) {

        if (tail == nullptr) {
            cout << "No Players in Game!" << endl;
            return;
        }

        Node* currentNode = tail->next;
        Node* previous = tail;

        do {

            if (currentNode->playerID == id) {

                if (currentNode == tail &&
                    currentNode->next == tail) {

                    cout << "Player " << id
                         << " Removed!" << endl;

                    delete currentNode;
                    tail = nullptr;
                    current = nullptr;
                    return;
                }

                previous->next = currentNode->next;

                if (currentNode == tail) {
                    tail = previous;
                }

                if (current == currentNode) {
                    current = currentNode->next;
                }

                cout << "Player " << id
                     << " Removed Successfully!" << endl;

                delete currentNode;
                return;
            }

            previous = currentNode;
            currentNode = currentNode->next;

        } while (currentNode != tail->next);

        cout << "Player Not Found!" << endl;
    }

    void checkWinner() {

        if (tail != nullptr &&
            tail->next == tail) {

            cout << "\nGame Over!" << endl;
            cout << "Winner is Player "
                 << tail->playerID << endl;
        }
    }
};

int main() {

    CircularLinkedList game;

    game.addPlayer(1, 100);
    game.addPlayer(2, 150);
    game.addPlayer(3, 200);
    game.addPlayer(4, 250);

    game.displayPlayers();

    cout << "\nNext Turn:" << endl;
    game.nextTurn();

    cout << "\nNext Turn:" << endl;
    game.nextTurn();

    cout << "\nSkipping a Player:" << endl;
    game.skipPlayer();

    cout << "\nRemoving Player 3:" << endl;
    game.removePlayer(3);

    game.displayPlayers();

    cout << "\nRemoving Player 2:" << endl;
    game.removePlayer(2);

    game.displayPlayers();

    cout << "\nRemoving Player 4:" << endl;
    game.removePlayer(4);

    game.displayPlayers();

    game.checkWinner();

    return 0;
}