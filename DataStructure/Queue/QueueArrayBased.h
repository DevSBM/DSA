#pragma once
#include <iostream>
#include <optional>


class QueueArrayBased {
private:
	int* arr;
	// front and rear is flexible and changes position accorading to enqueue and dequeue
	// enequeue-> changes rear
	// dequeue -> changes front
	int size, capacity, front, rear;
public:
	QueueArrayBased(int cap=10):capacity(cap),size(0),front(0),rear(-1) {
		arr = new int[capacity];
	}

	~QueueArrayBased() {
		delete[] arr;
	}

	void enqueue(int val) {
		if (size == capacity) {
			std::cout << "Queue Overflow!";
			return;
		}
		size++;
		rear = (rear + 1) % capacity;
		arr[rear] = val;
	}

	void dequeue() {
		if (size == 0) {
			std::cout << "Queue Underflow!";
			return;
		}
		size--;
		front = (front + 1) % capacity;
	}

	// Needs >=C++17 to compile
	std::optional<int> peek() {
		if (size == 0) {
			return std::nullopt;
		}
		return arr[front];
	}

	bool isEmpty() {
		return size == 0;
	}

	void print() {
		for (size_t i = 0; i < size; i++)
		{
			std::cout << arr[(front + i) % capacity] << " ";
		}
		std::cout << std::endl;
	}
};