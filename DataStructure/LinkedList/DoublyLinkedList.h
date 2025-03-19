#pragma once
#include <iostream>

typedef struct DNode {
	int data;
	DNode* next;
	DNode* prev;
	DNode(int val):data(val),next(nullptr),prev(nullptr){}
}DNode;

class DoublyLinkedList {
private:
	DNode* head;
public:
	DoublyLinkedList():head(nullptr){};
	~DoublyLinkedList() {
		while (head) {
			DNode* toDelete = head;
			head = head->next;
			delete toDelete;
			std::cout << " .";
		}
	}
	void insert(int val) {
		DNode* newNode = new DNode(val);

		if (!head) {
			head = newNode;
			return;
		}

		DNode* current = head;
		while (current->next) {
			current = current->next;
		}

		current->next = newNode;
		newNode->prev = current;

	}

	void remove(int val) {
		if (!head) {
			return;
		}
		// If we need to delete head node
		// then we also need to change 
		// the head pointer
		if (head->data == val) {
			DNode* currentHead = head;
			head = head->next;
			if (head) {
				head->prev = nullptr;
			}
			delete currentHead;
			return;
		}
		DNode* current = head;

		while (current && current->data != val) {
			current = current->next;
		}

		if (current) {
			DNode* toDelete = current;

			if (toDelete->next) {
				toDelete->next->prev = toDelete->prev;
			}

			if (toDelete->prev) {
				toDelete->prev->next = toDelete->next;
			}

			delete toDelete;
		}
	}

	void printForward() {
		DNode* current = head;

		while (current) {
			std::cout << current->data << " <-> ";
			current = current->next;
		}
		std::cout << "Null" << std::endl;
	}
};