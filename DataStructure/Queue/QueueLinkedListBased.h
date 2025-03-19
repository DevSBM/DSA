#pragma once
#include <iostream>
#include <optional>

struct Node {
	int data;
	Node* next;
	Node(int val):data(val),next(nullptr){}
};

class QueueLinkedListBased {
private:
	Node* front, * rear;
public:
	QueueLinkedListBased():front(nullptr),rear(nullptr) {}

	void enqueue(int data) {
		Node* newNode = new Node(data);
		if (!front) {
			front = rear = newNode;
		}
		else {
			rear->next = newNode;
			rear = newNode;
		}
	}

	void dequeue() {
		if (!front) {
			std::cout << "Queue Underflow";
			return;
		}
		else {
			Node* currentFront = front;
			front = front->next;
			if (!front) {
				rear = nullptr;
			}
			delete currentFront;
		}
	}

	std::optional<int> peek() {
		if (front == nullptr) {
			return std::nullopt;
		}
		return front->data;
	}

	bool isEmpty() {
		return front == nullptr;
	}

	void print() {
		Node* temp = front;
		while (temp) {
			std::cout << temp->data << " ";
			temp = temp->next;
		}
		std::cout << std::endl;
	}


};