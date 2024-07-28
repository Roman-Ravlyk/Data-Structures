#include <iostream>
using namespace std;

class TreeNode {
public:
	int data;
	TreeNode* firstchild;
	TreeNode* nextsibling;
	
	TreeNode(int d) : data(d), firstchild(nullptr), nextsibling(nullptr) {};
};

class Tree {
	TreeNode* root;

	void preTraversal(TreeNode* node) {
		if (node == nullptr) { return; };
		cout << node->data << " ";
		TreeNode* child = node->firstchild;
		
		while (child != nullptr) {
			preTraversal(child);
			child = node->nextsibling;
		}
	}

public:
	Tree() : root(nullptr) {};

	void setroot(TreeNode* node) {
		root = node;
	}

	void preOrderTraversal() {
		preTraversal(root);
		cout << endl;
	}
};

TreeNode* addChild(TreeNode* parent, int data) {
	if (parent == nullptr) return nullptr;

	TreeNode* child = new TreeNode(data);

	if (parent->firstchild == nullptr) {	
		parent->firstchild = child;
	}
	else {
		TreeNode* sibling = parent->firstchild;
		while (sibling->nextsibling != nullptr) {
			sibling = sibling->nextsibling;
		}
		sibling->nextsibling = child;
	}

	return child;
}

//int main() {
//	TreeNode* root = new TreeNode(1);
//
//	TreeNode* child1 = addChild(root, 2);
//	TreeNode* child2 = addChild(root, 3);
//	TreeNode* child3 = addChild(root, 4);
//
//	addChild(child1, 5);
//	addChild(child1, 6);
//
//	addChild(child2, 7);
//
//	Tree tree;
//	tree.setroot(root);
//
//	cout << "Pre-order Traversal: ";
//	tree.preOrderTraversal();
//
//	return 0;
//}