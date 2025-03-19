#pragma once
#include <iostream>

typedef struct Node {
	int data;
	Node* next;
	Node(int val):data(val),next(nullptr) {};
}Node;

class CircularLinkedList {
private:
	Node* tail;
public:
	CircularLinkedList():tail(nullptr){}

	void insert(int val) {
		Node* newNode = new Node(val);
		// If its the first node to be inserted
		if (!tail) {
			newNode->next=newNode;
			tail=newNode;
		}
		else {
			newNode->next = tail->next;
			tail->next = newNode;
			// Inserted node becomes the new tail
			tail = newNode;
		}
	}

	void remove(int val) {
		if (!tail) {
			return;
		}
		Node* current = tail->next, *prev = tail;

		do {
			if (current->data == val) {
				// Single Node Available
				if (current == tail && current->next == tail) {
					delete current;
					tail = nullptr;
					return;
				}
				prev->next = current->next;
				// If deleted node is tail
				if (current == tail) {
					tail = prev;
				}
				delete current;
				return;
			}
			prev = current;
			current = current->next;
		} while (current!=tail->next); // Same Logic as printing Node values
	}

	void print() {
		if (!tail) {
			std::cout << "No Items Found in List";
			return;
		}
		Node* current = tail->next;

		do {
			std::cout << current->data << " -> ";
			current = current->next;
		} while (current != tail->next);
		std::cout << "Head" << std::endl;
	}
};