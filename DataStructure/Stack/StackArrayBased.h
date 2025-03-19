#pragma once
#include <iostream>

class StackArrayBased {
private:
	int* arr;
	int top;
	int capacity;

public:
	StackArrayBased(int cap=10) {
		top = -1;
		this->capacity = cap;
		arr = new int[cap];
	}
	~StackArrayBased() {
		delete[] arr;
	}

	void push(int val) {
		if (top == capacity - 1) {
			std::cout << "Stack Overflow\n";
			return;
		}
		arr[++top] = val;
	}

	void pop(){
		if (top == -1) {
			std::cout << "Stack Underflow\n";
			return;
		}
		top--;
	}

	int peek() {
		if (top != -1) {
			return arr[top];
		}
		std::cout << "Stack is Empty!";
	}

	bool isEmpty() {
		return top == -1;
	}

	void print() {
		if (top == -1) {
			std::cout << "Stack is Empty!";
			return;
		}
		for (int i = top; i >=0 ; i--)
		{
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
	}
};