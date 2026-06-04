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
node* min(node* root) {
	while (root->left != nullptr) {
		root = root->left;
	}
	return root;
}
node* deletenode(node* root, int key) {
	if (root == nullptr)
		return root;

	if (key < root->data) {
		root->left = deletenode(root->left, key);
	}
	else if (key > root->data) {
		root->right = deletenode(root->right, key);
	}
	else {

		if (root->left == nullptr && root->right == nullptr) {
			delete root;
			return nullptr;
		}

		else if (root->left == nullptr) {
			node* temp = root->right;
			delete root;
			return temp;
		}
		else if (root->right == nullptr) {
			node* temp = root->left;
			delete root;
			return temp;
		}

		node* temp = min(root->right);
		root->data = temp->data;
		root->right = deletenode(root->right, temp->data);
	}

	return root;
}
int main() {
	node* root = nullptr;
	int n, value, key, deletekey;

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

	cout << "Postorder Traversal: " << endl;
	postorder(root);

	cout << "Enter key to search: " << endl;
	cin >> key;

	if (search(root, key))
		cout << "Key found in BST" << endl;
	else
		cout << "Key not found in BST" << endl;

	cout << "\nEnter key to delete: ";
	cin >> deletekey;

	root = deletenode(root, deletekey);

	cout << "\nBST after deletion:\n";

	cout << "Inorder Traversal: ";
	inorder(root);

	cout << "\nPreorder Traversal: ";
	preorder(root);

	cout << "\nPostorder Traversal: ";
	postorder(root);

	cout << endl;

	return 0;

}