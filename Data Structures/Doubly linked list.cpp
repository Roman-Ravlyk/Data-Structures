#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node* prev;
	Node(int a) : data(a), next(nullptr), prev(nullptr) {};
};

class DoublyLinkedList {
public:
	Node* head;
	DoublyLinkedList() : head(nullptr) {}

	void add_node(int data) {
		Node* new_node = new Node(data);
		new_node->next = head;
		if (head != nullptr) {
			head->prev = new_node;
		}
		head = new_node;
	}

	void print_prev() {
		Node* current = head;

		if (current == nullptr) {
			cout << "List is empty" << endl;
			return;
		}


		while (current->next != nullptr) {
			current = current->next;
		}
	
		cout << "Prev: ";

		while (current != nullptr) {
			cout << current->data << " ";
			current = current->prev;
		}
		cout << endl;
	}

	void print_next(Node* start) {
		Node* current = start;

		cout << "Next: ";
		while (current != nullptr) {
			cout << current->data << " ";
			current = current->next;
		}
		cout << endl;
	}

	Node* find_middle() {
		if (head == nullptr) return nullptr;

		Node* slow = head;
		Node* fast = head;

		while (fast != nullptr && fast->next != nullptr) {
			slow = slow->next;
			fast = fast->next->next;
		}

		return slow;
	}

	void split_and_print() {
		Node* middle = find_middle();
		if (middle == nullptr) return;

		Node* second_half = middle->next;
		if (second_half != nullptr) {
			second_half->prev = nullptr;
		}

		middle->next = nullptr;

		cout << "First half: ";
		print_next(head);

		cout << "Second half: ";
		print_next(second_half);
	}

	void delElBefore(int data) {
		Node* current = head;

		if (current == nullptr) return;

		while (current != nullptr) {

			if (current->data == data) {

				if (current == head || current->prev == nullptr) return;

				Node* temp = current->prev;

				if (temp->prev != nullptr) {
					temp->prev->next = current;
				}
				else {
					head = current;
				}
				current->prev = temp->prev;

				delete temp;
				return;
			}
			current = current->next;
		}
	}

	void print() {
		Node* current = head;

		while (current != nullptr) {
			cout << current->data << " ";
			current = current->next;
		}
	}

};

//int main() {
//	DoublyLinkedList list;
//
//	list.add_node(2);
//	list.add_node(3);
//
//	list.add_node(4);
//	list.add_node(2);
//
//	list.add_node(3);
//	list.add_node(4);
//
//	list.add_node(2);
//	list.add_node(3);
//
//	list.add_node(4);
//	list.add_node(2);
//
//	list.add_node(3);
//	list.add_node(4);
//	
//	list.print_prev(); cout << endl;
//	list.delElBefore(2);
//	list.print_prev();
//}