#include <iostream>
#define MAX 1000

using namespace std;

class Stack {
	int top;
public:
	int a[MAX];

	Stack() { top = -1; };

	bool push(int x) {
		if (top >= (MAX - 1)) {
			cout << "StackOverflow" << endl;
			return false;
		}
		else {
			a[++top] = x;
			cout << "Element successfully pushed into stack" << endl;
			return true;
		}
	};


	int peek() {
		if (top < 0) {
			cout << "Stack underflow" << endl;
			return 0;
		}
		int x = a[top];
		return x;
	};

	int pop() {
		if (top < 0) {
			cout << "Stack is underflow!" << endl;
			return 0;
		}
		else {
			int x = a[top--];
			cout << "Element successfully popped from stack" << endl;
			return x;
		}
	};
	bool isEmpty() {
		return (top < 0);
	};

	void print() {
		cout << "Your stack: ";
		for (int i = 0; i <= top; i++) {
			cout << a[i] << " ";
		}
		cout << endl;
	}

};

//int main() {
//	Stack stack;
//
//	for (int i = 0; i < 10; i++) {
//		stack.push(i);
//	}
//
//	stack.print();
//
//	stack.pop();
//	stack.print();
//
//	cout << "Top element is " << stack.peek() << endl;
//
//	stack.pop();
//	stack.print();
//
//	return 0;
//}