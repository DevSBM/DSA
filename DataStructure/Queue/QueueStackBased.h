#pragma once
#include <iostream>
#include <optional>
#include <stack>

class QueueStackBased {
private:
	std::stack<int> s1, s2;
public:
	void enqueue(int data) {
		while (!s1.empty()) {
			s2.push(s1.top());
			s1.pop();
		}
		s2.push(data);
		while (!s2.empty()) {
			s1.push(s2.top());
			s2.pop();
		}
	}

	void dequeue() {
		if (s1.empty()) {
			std::cout << "Stack Underflow!\n";
			return;
		}
		s1.pop();
	}

	std::optional<int> peek() {
		if (s1.size() == 0) {
			return std::nullopt;
		}
		return s1.top();
	}

	bool isEmpty(){
		return s1.empty();
	}

	void print() {
		std::stack<int> temp_s1 = s1;
		std::stack<int> rev_s1;

		while (!temp_s1.empty()) {
			rev_s1.push(temp_s1.top());
			temp_s1.pop();
		}

		while (!rev_s1.empty()) {
			std::cout << rev_s1.top()<<" ";
			rev_s1.pop();
		}

		std::cout << std::endl;

	}
};