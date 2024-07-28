#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* prev;
	Node* next;

	Node(int x) {
		data = x;
		prev = next = NULL;
	}
};

class Deque {

	Node* front, * rear;
public:
	Deque() {
		front = rear = NULL;
	}

	void push_front(int x) { 
		Node* temp = new Node(x);
		temp->prev = NULL;
		temp->next = front;
		if (front == NULL) {
			rear = front = temp;
			return;
		}

		
		front->prev = temp;
		front = temp;
	}

	void push_back(int x) {
		Node* temp = new Node(x);
		temp->prev = rear;
		temp->next = NULL;
		if (rear == NULL) {
			rear = front = temp;
			return;
		}

		rear->next = temp;
		rear = temp;
	}

	void enq_front() {
		if (front == NULL) {
			return;
		}

		Node* temp = front;
		front = front->next;
		front->prev = NULL;
		delete (temp);
	}

	void enq_back() {
		if (rear == NULL) {
			return;
		}

		Node* temp = rear;
		rear = rear->prev;
		rear->next = NULL;
		delete(temp);
	}

	int check_front() {
		if (front == NULL) {
			return 0;
		}

		return front->data;
	}

	int check_rear() {
		if (rear == NULL) {
			return 0;
		}

		return rear->data;
	}

	void print_queue() {
		Node* temp = front;
		if (front == NULL) {
			return;
		}

		cout << "Your deque: ";
		do {
			cout << temp->data << " ";
			temp = temp->next;
		} while (temp != NULL);
		cout << endl;
	}
};

//int main() {
//	Deque d;
//
//	d.push_front(10);
//	d.push_back(20);
//	d.push_front(30);
//
//	d.print_queue();
//
//	cout << "Front: " << d.check_front() << endl;
//	cout << "Rear: " << d.check_rear() << endl;
//	
//
//	cout << "Enq back: ";
//	d.enq_back();
//	d.print_queue();
//
//	cout << "Enq front: " << endl;
//	d.enq_front();
//	d.print_queue();
//}