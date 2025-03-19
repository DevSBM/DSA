#pragma once
#include <iostream>

class DynamicArray {
private:
	int* data;
	int size, capacity;
	// Resizing our Array
	void resize(int newCap) {
		int* temp = new int[newCap];

		for (size_t i = 0; i < size; i++)
		{
			temp[i] = data[i];
		}
		delete[] data;
		data = temp;
		capacity = newCap;
	}
public:
	DynamicArray(int cap=10) :size(0), capacity(cap){
		data = new int[cap];
	}
	~DynamicArray() {
		delete[] data;
	}

	void push_back(int val) {
		if (size == capacity) {
			this->resize(capacity * 2);
		}
		data[size++] = val;
	}

	void pop_back() {
		if (size > 0) {
			size--;
			if (size < (capacity / 4)) {
				this->resize(capacity / 2);
			}
		}
	}

	int getSize() {
		return this->size;
	}

	int getCapacity() {
		return this->capacity;
	}

	void print() {
		for (size_t i = 0; i < this->size; i++)
		{
			std::cout << data[i] << "\n";
		}
		std::cout << std::flush;
	}

	int& operator[](int idx){
		if (idx<0 || idx>=this->size) {
			throw std::out_of_range("Index out of bounds!");
		}
		return data[idx];
	}

};