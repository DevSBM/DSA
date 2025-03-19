#pragma once
#include<vector>

class DisjointSet {
public:
	std::vector<int> parent, rank;
private:
	DisjointSet(int n) {
		parent.resize(n);
		rank.resize(n,0);
		for (size_t i = 0; i < n; i++)
		{
			parent[i] = i;
		}
	}
	int find(int x) {
		if (parent[x] != x) {
			parent[x] = find(parent[x]);
		}
		return parent[x];
	}

	void unionSets(int x,int y) {
		int rootX = find(x);
		int rootY = find(y);

		if (rootX != rootY) {

		}

	}
};