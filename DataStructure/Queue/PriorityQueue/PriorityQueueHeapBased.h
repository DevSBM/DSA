#pragma once
#include <iostream>
#include <optional>
#include <vector>

class PriorityQueueHeapBased {
private:
	std::vector<int> maxHeap;

	void heapifyUp(int index) {
		while (index > 0) {
			int parent = (index - 1) / 2;
			if (maxHeap[index] > maxHeap[parent]) {
				std::swap(maxHeap[index], maxHeap[parent]);
				index = parent;
			}
			else {
				break;
			}
		}
	}

	void heapifyDown(int index) {
		int largest = index, left = (index * 2) + 1, right = (index * 2) + 2;

		if (left < maxHeap.size() && maxHeap[largest] < maxHeap[left]) {
			largest = left;
		}
		if (right < maxHeap.size() && maxHeap[largest] < maxHeap[right]) {
			largest = right;
		}

		if (largest != index) {
			std::swap(maxHeap[largest], maxHeap[index]);
			heapifyDown(largest);
		}
		
	}

public:
	PriorityQueueHeapBased() {

	}

	void push(int value) {
		maxHeap.push_back(value);
		heapifyUp(maxHeap.size() - 1);
	}

	void pop() {
		if (isEmpty()) {
			std::cout << "Heap Underflow\n";
			return;
		}
		maxHeap[0] = maxHeap[maxHeap.size() - 1];
		maxHeap.pop_back();
		if (!isEmpty()) {
			heapifyDown(0);
		}
	}

	bool isEmpty() {
		return maxHeap.size() == 0;
	}

	std::optional<int> top() {
		if (isEmpty()) {
			return std::nullopt;
		}
		return maxHeap[0];
	}

	void print() {
		if (isEmpty()) {
			std::cout << "Queue is empty!\n";
			return;
		}
		for (auto num:maxHeap)
		{
			std::cout << num << "\n";
		}
	}
};