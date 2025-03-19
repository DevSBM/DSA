#pragma once

struct Node {
	int data;
	Node* left , *right;
	Node(int val):data(val),left(nullptr),right(nullptr) {}
};

class BinarySearchTree {
private:
public:
	Node* root;

	BinarySearchTree():root(nullptr) {}

};