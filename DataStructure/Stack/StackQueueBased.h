#pragma once
#include <iostream>
#include <queue>

class StackQueueBased {
private:
	std::queue<int> q1, q2;
public:
	StackQueueBased() {}

	void push(int val) {
		q2.push(val);
		while (!q1.empty()) {
			q2.push(q1.front());
			q1.pop();
		}
		std::swap(q1, q2);
	}

	void pop() {
		if (q1.empty()) {
			std::cout << "Stack is empty!";
			return;
		}
		q1.pop();
	}

	int peek() {
		if (q1.empty()) {
			throw std::out_of_range("Stack is Empty!");
		}
		return q1.front();
	}

	bool isEmpty() {
		return q1.empty();
	}

	void print() {
		// Not efficient
		std::queue<int> temp = q1; // Copy constructor
		while (!temp.empty()) {
			std::cout << temp.front() << " ";
			temp.pop();
		}
		std::cout << "\n";
	}
};