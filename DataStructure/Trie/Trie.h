#pragma once
#include <iostream>
#include <unordered_map>

struct TrieNode {
	std::unordered_map<char, TrieNode*> children;
	bool isWord;
	TrieNode():isWord(false){}
};

class Trie {
private:
	TrieNode* root;
	bool _removeWord(TrieNode* node, const std::string& word ,int depth) {
		if (!node) {
			return false;
		}

		if (depth == word.length()) {
			if (!node->isWord) {
				return false;
			}
			node->isWord = false;
			return node->children.empty();
		}

		char ch = word[depth];
		if (_removeWord(node->children[ch], word, depth + 1)) {
			delete node->children[ch];
			node->children.erase(ch);

			return node->children.empty() && !node->isWord;
		}

		return false;
	}
public:
	Trie() {
		root = new TrieNode();
	}

	void insert(const std::string& word) {
		TrieNode* current = root;
		for (char ch : word) {
			if (current->children.find(ch) == current->children.end()) {
				current->children[ch] = new TrieNode();
			}
			current = current->children[ch];
		}
		current->isWord = true;
	}

	bool search(const std::string& word) {
		TrieNode* current = root;
		for (char ch : word) {
			if (current->children.find(ch) == current->children.end()) {
				return false;
			}
			current = current->children[ch];
		}
		return current->isWord;
	}

	bool remove(const std::string& word) {
		return this->_removeWord(root,word,0);
	}
};