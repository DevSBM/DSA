#pragma once
#include <iostream>
#include <optional>

struct Node{
	int value;
	Node* next,* prev;
	Node(int val):value(val),next(nullptr),prev(nullptr){}
};

class DequeLinkedListBased {
private:
	Node* front, * rear;
public:
	DequeLinkedListBased():front(nullptr),rear(nullptr) {}

	bool isEmpty() {
		return front == nullptr;
	}

	void pushFront(int value) {
		Node* newNode = new Node(value);
		if (isEmpty()) {
			front = rear = newNode;
		}
		else {
			newNode->next = front;
			front->prev = newNode;
			front = newNode;
		}
	}

	void pushBack(int value) {
		Node* newNode = new Node(value);
		if (isEmpty()) {
			front = rear = newNode;
		}
		else {
			rear->next = newNode;
			newNode->prev = rear;
			rear = newNode;
		}
	}

	void popFront() {
		if (isEmpty()) {
			std::cout << "Deque Underflow!";
			return;
		}
		Node* currentFront = front;

		front = front->next;
		if (!front) {
			front = rear = nullptr;
		}
		else {
			front->prev = nullptr;
		}

		delete currentFront;
	}

	void popBack() {
		if (isEmpty()) {
			std::cout << "Deque Underflow!";
			return;
		}
		Node* currentRear = rear;

		rear = rear->prev;
		if (!rear) {
			front = rear = nullptr;
		}
		else {
			rear->next = nullptr;
		}

		delete currentRear;
	}

	std::optional<int> getFront() {
		if (isEmpty()) {
			return std::nullopt;
		}

		return front->value;
	}

	std::optional<int> getBack() {
		if (isEmpty()) {
			return std::nullopt;
		}
		return rear->value;
	}

	void print() {
		Node* temp = front;

		while (temp) {
			std::cout << temp->value << " -> ";
			temp = temp->next;
		}

		std::cout << " NULL\n";
	}
};