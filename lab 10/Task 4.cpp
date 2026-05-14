#include <iostream>
using namespace std;

class node {
public:
	int data;
	node* next;
};

void print(node*head) {
	if (head == NULL) {
		return;
	}
	cout << head->data<<endl;

	print(head->next);
}

int main() {
	node* head = new node{ 10 , NULL };
	head->next = new node{ 20, NULL };
	head->next->next = new node{ 30, NULL };
	head->next->next->next = new node{ 40, NULL };

	 print(head);
}
