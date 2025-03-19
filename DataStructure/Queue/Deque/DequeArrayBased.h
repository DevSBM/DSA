#pragma once
#include <iostream>
#include <optional>

class DequeArrayBased {
	private:
		int* arr;
		int front, rear, capacity, size;

	public:
		DequeArrayBased(int capacity):capacity(capacity),size(0) {
			front = -1, rear = -1;
			arr = new int[capacity];
		}

		~DequeArrayBased() {
			delete[] arr;
		}

		void pushFront(int value){
			if (isFull()) {
				std::cout << "Deque overflow!";
				return;
			}
			if (isEmpty()) {
				front = rear = 0;
			}
			else {
				front = (front - 1 + capacity) % capacity;
			}
			arr[front] = value;
			size++;
		}

		void pushBack(int value) {
			if (isFull()) {
				std::cout << "Deque overflow!";
				return;
			}
			if (isEmpty()) {
				front = rear = 0;
			}
			else {
				rear = (rear + 1) % capacity;
			}
			arr[rear] = value;
			size++;
		}

		void popFront() {
			if (isEmpty()) {
				std::cout << "Deque underflow!";
				return;
			}
			front = (front + 1) % capacity;
			size--;
		}

		void popBack() {
			if (isEmpty()) {
				std::cout << "Deque underflow!";
				return;
			}
			rear = (rear - 1 + capacity) % capacity;
			size--;
		}

		std::optional<int> getFront() {
			if (isEmpty()) {
				return std::nullopt;
			}
			return arr[front];
		}

		std::optional<int> getBack() {
			if (isEmpty()) {
				return std::nullopt;
			}
			return arr[rear];
		}

		bool isEmpty() {
			return size == 0;
		}

		bool isFull() {
			return size == capacity;
		}

		void print() {
			if (isEmpty()) {
				std::cout << "Deque is empty!";
				return;
			}

			for (int i = 0; i < size; i++) {
				std::cout << arr[(front + i) % capacity]<<" -> ";
			}
			std::cout << " NULL "<<"\n";
		}
};