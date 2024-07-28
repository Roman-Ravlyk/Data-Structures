#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next = nullptr;

	Node(int data) {
		this->data = data;
		this->next = nullptr;
	}
};

class SinglyLinkedList {
public: 
	Node* head;

	SinglyLinkedList() {
		this->head = nullptr;
	}

	void add_node(int data) {
		Node* new_node = new Node(data);
		new_node->next = this->head;
		this->head = new_node;
	}

	void print() {
		Node* current = head;
		while (current != nullptr){
			cout << current->data << " ";
			current = current->next;
		}
	}

	void del_elem(int data) {
		Node* current = head;
		Node* prev = nullptr;

		if (current != nullptr && current->data == data) {
			head = current->next;
			delete current;
			return;
		}

		while (current != nullptr && current->data != data) {
			prev = current;
			current = current->next;
		}

		if (current == nullptr) return;

		prev->next = current->next;
		delete current;
	}

	int sum_indexes(int in, int un) {
		Node* frs = nullptr;
		Node* sec = nullptr;
		Node* current = head;
		int sum = 0;
		int count = 0;

		while (current != nullptr) {
			if (count == in) {
				frs = current;
			}
			else if (count == un) {
				sec = current;
			}
			current = current->next;
			count++;
		}

		if (frs == nullptr || sec == nullptr) {
			cout << "No element on this indexes";
			return 0;
		}

		sum = frs->data += sec->data;
		return sum;
	}

	int sum_tuples() {
		Node* current = head;
		int sum = 0;

		while (current != nullptr) {
			if (current->data % 2 != 0) {
				sum += current->data;
			}
			current = current->next;
		}

		return sum;
	}

	Node* swap() {
		Node* current = head;
		Node* prev = nullptr;
		Node* next = nullptr;

		// Find the middle of the list
		int count = 0;
		while (current != nullptr) {
			current = current->next;
			count++;
		}

		int middle = count / 2;
		count = 0;
		current = head;

		// Traverse to the middle of the list
		while (current != nullptr && count < middle) {
			prev = current;
			current = current->next;
			count++;
		}

		// Reverse the second half of the list
		Node* secondHalf = current;
		Node* temp = nullptr;
		while (secondHalf != nullptr) {
			next = secondHalf->next;
			secondHalf->next = temp;
			temp = secondHalf;
			secondHalf = next;
		}

		// Connect the reversed second half to the first half
		if (prev != nullptr) {
			prev->next = temp;
		}
		else {
			head = temp;
		}

		return head; // Return the head of the reversed list
	}
};

//int main() {
//	SinglyLinkedList list = SinglyLinkedList();
//
//	for (int i = 0; i < 10; i++) {
//		list.add_node(i);
//	}
//
//	//list.print();
//	///*list.del_elem(9);*/
//	//cout << endl;
//	list.print(); cout << endl;
//	/*cout << list.sum_indexes(8, 9);*/
//	//cout << list.sum_tuples();
//	Node* newhead = list.swap();
//	list.print();
//}