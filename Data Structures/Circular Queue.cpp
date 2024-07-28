#include <iostream>
using  namespace std;

class Node {
public:
	int data;
	Node* next;

	Node(int x) {
		data = x;
		next = NULL;
	}
};

class CircularQueue {
	Node* front, *rear;

public:
	CircularQueue() {
		front = rear = NULL;
	}

	void enqueue(int data) {
		Node* temp = new Node(data);
		if (front == NULL) {
			front = rear = temp;
			rear->next = front;
			return;
		}
		rear->next = temp;
		rear = temp;
		rear->next = front;
	}

	int dequeue() {
		if (front == NULL) {
			return 0;
		}

		int value;
		if (front == rear) {
			value = front->data;
			delete front;
			front = rear = NULL;
		}
		else {
			Node* temp = front;
			value = temp->data;
			front = front->next;
			rear->next = front;
			delete temp;
		}

		return value;
	}

	void print_queue() {
		if (front == NULL) {
			return;
		}

		Node* temp = front;
		do {
			cout << temp->data << " ";
			temp = temp->next;
		} while (temp != front);
		cout << endl;
	}
};

//int main() {
//	CircularQueue c;
//	c.enqueue(10);
//	c.enqueue(20);
//	c.enqueue(30);
//	c.enqueue(40);
//	c.enqueue(50);
//
//	c.print_queue();
//
//	cout << "Dequeued: " << c.dequeue() << endl;
//	c.print_queue();
//
//	cout << "Dequeued: " << c.dequeue() << endl;
//	c.print_queue();
//
//	return 0;
//}