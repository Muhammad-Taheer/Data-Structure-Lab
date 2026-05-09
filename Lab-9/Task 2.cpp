#include <iostream>
using namespace std;

class Node {
public:
    int songID;
    string songName;
    float duration;

    Node* next;
    Node* prev;

    Node(int id, string name, float dur) {
        songID = id;
        songName = name;
        duration = dur;

        next = nullptr;
        prev = nullptr;
    }
};

class PlaylistManager {
private:
    Node* head;
    Node* tail;
    Node* current;

public:
    PlaylistManager() {
        head = nullptr;
        tail = nullptr;
        current = nullptr;
    }

    void addSong(int id, string name, float dur) {

        Node* newNode = new Node(id, name, dur);

        if (head == nullptr) {
            head = tail = current = newNode;
            return;
        }

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void deleteSong(string name) {

        if (head == nullptr) {
            cout << "Playlist is Empty!" << endl;
            return;
        }

        Node* temp = head;

        while (temp != nullptr && temp->songName != name) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Song not found!" << endl;
            return;
        }

        if (temp == head) {
            head = head->next;

            if (head != nullptr)
                head->prev = nullptr;
            else
                tail = nullptr;
        }

        else if (temp == tail) {
            tail = tail->prev;
            tail->next = nullptr;
        }

        else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }

        if (current == temp) {
            current = head;
        }

        delete temp;

        cout << "Song Deleted Successfully!" << endl;
    }

    void playNext() {

        if (current == nullptr) {
            cout << "Playlist is Empty!" << endl;
            return;
        }

        if (current->next == nullptr) {
            cout << "No Next Song Available!" << endl;
            return;
        }

        current = current->next;

        cout << "Now Playing: " << current->songName << endl;
    }

    void playPrevious() {

        if (current == nullptr) {
            cout << "Playlist is Empty!" << endl;
            return;
        }

        if (current->prev == nullptr) {
            cout << "No Previous Song Available!" << endl;
            return;
        }

        current = current->prev;

        cout << "Now Playing: " << current->songName << endl;
    }

    void reversePlaylist() {

        if (head == nullptr) {
            cout << "Playlist is Empty!" << endl;
            return;
        }

        Node* temp = nullptr;
        Node* currentNode = head;

        while (currentNode != nullptr) {

            temp = currentNode->prev;
            currentNode->prev = currentNode->next;
            currentNode->next = temp;

            currentNode = currentNode->prev;
        }

        temp = head;
        head = tail;
        tail = temp;

        cout << "Playlist Reversed Successfully!" << endl;
    }

    void displayPlaylist() {

        if (head == nullptr) {
            cout << "Playlist is Empty!" << endl;
            return;
        }

        Node* temp = head;

        cout << "\n----- Playlist -----" << endl;

        while (temp != nullptr) {

            cout << "Song ID: " << temp->songID << endl;
            cout << "Song Name: " << temp->songName << endl;
            cout << "Duration: " << temp->duration << " mins" << endl;
            cout << "---------------------" << endl;

            temp = temp->next;
        }
    }
};

int main() {

    PlaylistManager playlist;

    playlist.addSong(1, "Shape of You", 4.2);
    playlist.addSong(2, "Blinding Lights", 3.5);
    playlist.addSong(3, "Perfect", 4.8);
    playlist.addSong(4, "Levitating", 3.9);

    cout << "Playlist After Adding Songs:" << endl;
    playlist.displayPlaylist();

    cout << "\nPlaying Next Song:" << endl;
    playlist.playNext();

    cout << "\nPlaying Next Song:" << endl;
    playlist.playNext();

    cout << "\nPlaying Previous Song:" << endl;
    playlist.playPrevious();

    cout << "\nDeleting Song 'Perfect':" << endl;
    playlist.deleteSong("Perfect");

    playlist.displayPlaylist();

    cout << "\nReversing Playlist:" << endl;
    playlist.reversePlaylist();

    playlist.displayPlaylist();

    return 0;
}