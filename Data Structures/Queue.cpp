#include <iostream>
using namespace std;
//#define MAX 1000
//
//class Queue {
//	int front, rear, size;
//	int* arr;
//public:
//	Queue(int maxSize = MAX) {
//		front = size = 0;
//		rear = maxSize - 1;
//		arr = new int[maxSize];
//	}
//
//	~Queue() {
//		delete[] arr;
//	}
//
//	bool isFull() {
//		return (size == MAX);
//	}
//	bool isEmpty() {
//		return (size == 0);
//	}
//
//	void enqueue(int item) {
//		if (isFull()) {
//			cout << "Queue is Overflow!" << endl;
//			return;
//		}
//		rear = (rear + 1) % MAX;
//		arr[rear] = item;
//		size++;
//		cout << "Item Enqueued: " << item << endl;
//	}
//
//	int dequeue() {
//		if (isEmpty()) {
//			cout << "Queue is Underflow" << endl;
//			return INT_MIN;
//		}
//		int item = arr[front];
//		front = (front + 1) % MAX;
//		size--;
//		return front;
//	}
//
//	int frontElement() {
//		if (isEmpty()) {
//			return INT_MIN;
//		}
//		return arr[front];
//	}
//
//	int rearElement() {
//		if (isFull()) {
//			return INT_MIN;
//		}
//		return arr[rear];
//	} 
//	
//	void printQueue() {
//		if (isEmpty()) {
//			cout << "Queue is Empty! " << endl;
//			return;
//		}
//		cout << "Queue elemnts: ";
//		for (int i = 0; i < size; i++) {
//			cout << arr[(front + i) % MAX] << " ";
//		}
//		cout << endl;
//	}
//};

class QNode {
public:
	int data;
	QNode* next;

	QNode(int d) {
		data = d;
		next = NULL;
	}
};

class Queue {
	QNode *front, *rear;
public:
	Queue() { front = rear = NULL; }

	void enQueue(int x) {
		QNode* temp = new QNode(x);

		if (rear == NULL) {
			front = rear = temp;
			return;
		}

		rear->next = temp;
		rear = temp;
	}

	void deQueue() {
		if (front == NULL) {
			return;
		}
		QNode* temp = front;
		front = front->next;

		if (front == NULL) {
			rear == NULL;
		}
		delete (temp);
	}

	void printQueue() {
		if (front == NULL) {
			return;
		}

		QNode* temp = front;

		cout << "Your Queue: ";
		do{
			cout << temp->data << " ";
			temp = temp->next;
		} while (temp != NULL);
		cout << endl;
	}

	int frontElement() {
		if (front == NULL) {
			return 0;
		}

		return front->data;
	}

	int rearElement() {
		if (rear == NULL) {
			return 0;
		}

		return rear->data;
	}
};

//int main() {
//	Queue q;
//	q.enQueue(10);
//	q.enQueue(20);
//	q.enQueue(30);
//	q.enQueue(40);
//	q.enQueue(50);
//
//	q.printQueue();
//
//	q.deQueue();
//	q.printQueue();
//
//	cout << "Front " << q.frontElement() << endl;
//	cout << "Rear " << q.rearElement() << endl;
//}