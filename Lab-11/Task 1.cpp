#include <iostream>
using namespace std;

class node {
public:
	int data;
	node* left;
	node* right;

	node(int value) {
		data = value;
		right = left = nullptr;
	}
};
node* insert(node* root, int  value) {
	if (root == nullptr) {
		return new node(value);
	}
	if (value < root->data) {
		root->left = insert(root->left, value);
	}
	else if (value > root->data) {
		root->right = insert(root->right, value);
	}
	return root;
}
void inorder(node* root) {
	if (root != nullptr) {
		inorder(root->left);
		cout << root->data;
		inorder(root->right);
	}
}
void preorder(node* root) {
	if (root != nullptr) {
		cout << root->data;
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(node* root) {
	if (root != nullptr) {
		postorder(root->left);
		postorder(root->right);
		cout << root->data;
	}
}
bool search(node* root, int key) {
	if (root == nullptr) {
		return false;
	}
	if (root->data == key) {
		return true;
	}
	if (key < root->data) {
		return search(root->left, key);
	}
	return search(root->right, key);
}
int main() {
	node* root = nullptr;
	int n, value, key;

	cout << "enter a number ";
	cin >> n;

	cout << "enter integers";
	for (int i = 0; i < n; i++) {
		cin >> value;
		root = insert(root, value);
	}
	cout << "Inorder Traversal: " << endl;
	inorder(root);

	cout << "Preorder Traversal: " << endl;
	preorder(root);

	cout << "Postorder Traversal: " <<endl;
	postorder(root);

	cout << "Enter key to search: " << endl;
	cin >> key;

	if (search(root, key))
		cout << "Key found in BST" << endl;
	else
		cout << "Key not found in BST" << endl;

	return 0;

}