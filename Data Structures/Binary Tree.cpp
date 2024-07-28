#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;

	Node(int d): data(d), left(nullptr), right(nullptr) {}
};

class BinaryTree {
	Node* root;

	void PreOrderTraversal(Node* node) {
		if (node == nullptr) return;
		cout << node->data << " ";
		PreOrderTraversal(node->left);
		PreOrderTraversal(node->right);
	}

	void InOrderTraversal(Node* node) {
		if (node == nullptr) return;
		InOrderTraversal(node->left);
		cout << node->data << " ";
		InOrderTraversal(node->right);
	}

	void PostOrderTraversal(Node* node) {
		if (node == nullptr) return;
		PostOrderTraversal(node->left);
		PostOrderTraversal(node->right);
		cout << node->data << " ";
	}

public:

	BinaryTree() {
		root = nullptr;
	}
	void setRoot(Node* node) {
		root = node;
	}

	void PreOrder() {
		PreOrderTraversal(root);
		cout << endl;
	}

	void InOrder() {
		InOrderTraversal(root);
		cout << endl;
	}

	void PostOrder() {
		PostOrderTraversal(root);
		cout << endl;
	}
 };

Node* addChild(Node* parent, int value, bool isLeft) {
	if (parent == nullptr) {
		return nullptr;
	}

	Node* child = new Node(value);

	if (isLeft) {
		parent->left = child;
	}
	else {
		parent->right = child;
	}

	return child;
}


int main() {
	BinaryTree tree;

	Node* root = new Node(10);

	Node* leftchild = addChild(root, 5, true);
	Node* rightchild = addChild(root, 15, false);

	tree.setRoot(root);

	addChild(leftchild, 1, true);
	addChild(leftchild, 3, false);
	addChild(rightchild, 20, true);
	addChild(rightchild, 25, false);

	cout << "Pre-order traversal: ";
	tree.PreOrder();

	cout << "In-order traversal: ";
	tree.InOrder();

	cout << "Post-order traversal: ";
	tree.PostOrder();

	return 0;
}