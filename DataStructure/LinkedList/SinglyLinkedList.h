#pragma once
#include <iostream>

typedef struct Node {
	Node* next;
	int data;
	Node(int val):next(nullptr),data(val){}
}Node;

class SinglyLinkedList {
private:
	Node* head;
public:
	SinglyLinkedList() :head(nullptr) {
	}

	void insert(int val) {
		Node* newNode = new Node(val);
		if (!head) {
			head = newNode;
			return;
		}
		Node* temp = head;
		while (temp->next) {
			temp = temp->next;
		}
		temp->next = newNode;
	}

	void remove(int val) {
		if (!head) {
			return;
		}
		if (head->data == val) {
			Node* temp = head;
			head = head->next;
			delete temp;
			return;
		}
		Node* temp = head;
		// We have to do this with temp->next 
		// otherwise we will lose the current node
		while (temp->next && temp->next->data != val) {
			temp = temp->next;
		}
		if (temp->next) {
			Node* toDelete = temp->next;
			temp->next = temp->next->next;
			delete toDelete;
		}
	}

	void reverse() {
		Node* prev = nullptr;
		Node* current = head;

		while (current) {
			Node* next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		head = prev;
	}

	bool hasCycle(){
		Node* slow = head, * fast = head;

		if (fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast) {
				return true;
			}
		}
		return false;
	}

	void print() {
		Node* current = head;

		while (current) {
			std::cout << current->data << " -> ";
			current = current->next;
		}

		std::cout << "Null" << std::endl;
	}

};