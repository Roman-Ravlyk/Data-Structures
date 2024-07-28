#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node(int a) : data(a), next(nullptr) {};
};

class CircularLinkedList {
public:
	Node* head;
	CircularLinkedList(): head(nullptr) {}

	void add_node(int data) {
		Node* new_node = new Node(data);
		if (head == nullptr) {
			head = new_node;
			new_node->next = head;
			return;
		}
		Node* current = head;
		while (current->next != head) {
			current = current->next;
		}
		current->next = new_node;
		new_node->next = head;
	}

	void print() {
		Node* current = head;
		if (current == nullptr) return;

		do {
			cout << current->data << " ";
			current = current->next;
		}while (current != head);
	}

	bool have_tup() {
		
		Node* current = head;
		Node* prev = nullptr;
		Node* next = nullptr;

		if (current == nullptr) return false;

		do {
			prev = current;
			next = current->next;

			if (next != head && prev->data == next->data) {
				return true;
			}
			
			current = current->next;

		} while (current != head);

		return false;
	}

	void deleteNode(int key) {
		if (head == nullptr) return;

		Node* temp = head;
		Node* prev = nullptr;

		// Find the node with the key to delete
		while (temp->data != key) {
			if (temp->next == head) {
				cout << "Element not found in the list" << endl;
				return;
			}
			prev = temp;
			temp = temp->next;
		}

		// If the node to delete is the head
		if (temp == head) {
			prev = head;
			while (prev->next != head) {
				prev = prev->next;
			}
			head = temp->next;
			prev->next = head;
			delete temp;
		}
		else {
			prev->next = temp->next;
			delete temp;
		}
	}
};

//int main() {
//	CircularLinkedList list;
//
//	for (int i = 0; i < 5; i++) {
//		list.add_node(i);
//	}
//	list.add_node(1);
//	list.add_node(1);
//	list.print(); cout << endl;
//
//	bool x = list.have_tup();
//	if (x) {
//		cout << "List has tuple pairs";
//	}
//	else {
//		cout << "List hasn`t pairs";
//	}
//	cout << endl;
//	list.deleteNode(2);
//	list.print();
//	return 0;
//}