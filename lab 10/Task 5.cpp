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
class doubly {
public:
	node* head;
	node* tail;

	void insertstart(int value) {
		node* newnode = new node(value);

		if (head == NULL) {
			head = tail = newnode;
			return;
		}
		head->prev = newnode;
		newnode->next = head;
		head = newnode;
	}
	void insertend(int value) {
		node* newnode = new node(value);
		if (head == NULL) {
			head = tail = newnode;
			return;
		}
		tail->next = newnode;
		newnode->prev = tail;
		tail = newnode;
	}
	void insertposition(int pos, int value) {
		node* newnode = new node(value);

		node* temp = head;

		for (int i = 1; i < pos - 1 || temp != NULL; i++){
			temp = temp->next;
		}
		newnode->next = temp->next;
		newnode->prev = temp;

		temp->next->prev = newnode;
		temp->next = newnode;
	}

	void deleteposition(int pos) {
		node* temp = head;

		for (int i = 1; i < pos - 1 || temp != NULL; i++) {
			temp = temp->next;
		}
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;

		delete temp;
	}
	void displayforward() {
		node* temp = head;

		cout << "Forward ";
		while (temp != NULL) {
			cout << temp->data;
			temp = temp->next;
		}
	}
	void displaybackward() {
		node* temp = head;

		cout << "Forward ";
		while (temp != NULL) {
			cout << temp->data;
			temp = temp->prev;
		}
	}
};

int main() {

	doubly d;

	d.insertstart(10);
	d.insertstart(5);

	d.insertend(20);
	d.insertend(30);

	d.displayforward();
	d.displaybackward();

	d.insertposition(3, 15);

	cout << "After inserting " << endl;

	d.displayforward();
	d.deleteposition(2);

	cout << "After deleting " << endl;

	d.displayforward();
	d.displaybackward();


}