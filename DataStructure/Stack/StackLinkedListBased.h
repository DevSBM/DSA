#pragma once
#include <iostream>

struct Node {
	int data;
	Node* next;
	Node(int val):data(val),next(nullptr){}
};

class StackLinkedListBased {
private:
	Node* top;
public:
	StackLinkedListBased():top(nullptr) {}

	void push(int val) {
		Node* newNode = new Node(val);
		newNode->next = top;
		top = newNode;
	}

	void pop() {
		if (!top) {
			std::cout << "Stack Underflow!";
			return;
		}
		Node* currentTop = top;
		top = top->next;
		delete currentTop;
	}

	int peek() {
		if (!top) {
			throw std::out_of_range("Stack is Empty!");
		}
		return top->data;
	}

	bool isEmpty(){
		return top == nullptr;
	}

	void print() {
		if (!top) {
			std::cout << "Stack is Empty\n";
			return;
		}
		Node* currentTop = top;
		while (currentTop) {
			std::cout << currentTop->data<<" ";
			currentTop = currentTop->next;
		}
	}
};