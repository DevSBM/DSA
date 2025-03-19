#pragma once
#include <iostream>
#include <queue>

struct Node {
	int data;
	Node* left, * right;
	Node(int data):data(data),left(nullptr),right(nullptr){}
};

class BinaryTree {
public:
	Node* root;
	BinaryTree():root(nullptr){}

	Node* insert(int val,Node* currentNode,std::string location="") {
		if (root == nullptr) {
			root = new Node(val);
			return root;
		}
		else {
			if (location == "" || currentNode==nullptr) {
				return new Node(val);
			}
			else {
				char c = location[0];
				location = location.substr(1);
				if (c == '0') {
					currentNode->left = insert(val, currentNode->left, location);
				}
				else {
					currentNode->right = insert(val, currentNode->right, location);
				}
					return currentNode;
			}
		}
	}

	void inorder(Node* node) {
		if (node == nullptr) {
			return;
		}
		preorder(node->left);
		std::cout << node->data << " ";
		preorder(node->right);
	}

	void preorder(Node* node) {
		if (node == nullptr) {
			return;
		}
		std::cout << node->data << " ";
		preorder(node->left);
		preorder(node->right);
	}

	void postorder(Node* node) {
		if (node == nullptr) {
			return;
		}
		preorder(node->left);
		preorder(node->right);
		std::cout << node->data << " ";
	}

	// only bfs type search
	void levelorder() {
		if (root == nullptr) {
			return;
		}
		std::queue<Node*> q;
		q.push(root);

		while (!q.empty()) {
			Node* currentNode = q.front();
			q.pop();
			std::cout << currentNode->data << " ";
			if (currentNode->left) {
				q.push(currentNode->left);
			}
			if (currentNode->right) {
				q.push(currentNode->right);
			}
		}
	}
};