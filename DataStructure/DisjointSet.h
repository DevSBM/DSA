#pragma once
#include <vector>

namespace DisjointSet {
	using namespace std;
	class DSU {
	public:
		vector<int> parent, rank;

		DSU(int n) {
			parent.resize(n);
			rank.resize(n, 0);

			for (int i = 0; i < n; i++) {
				parent[i] = i;
			}
		}

		int find(int u) {
			if (parent[u] != u) {
				parent[u] = find(parent[u]);
			}

			return parent[u];
		}

		bool unionSet(int u, int v) {
			int parentU = find(u);
			int parentV = find(v);

			if (parentU != parentV) {
				if (rank[parentU] < rank[parentV]) {
					parent[parentU] = parentV;
				}
				else if (rank[parentU] > rank[parentV]) {
					parent[parentV] = parentU;
				}
				else {
					parent[parentV] = parentU;
					rank[parentU]++;
				}
			}
			else {
				return false;
			}

			return true;
		}

		bool isConnected(int u, int v) {
			return find(u) == find(v);
		}

	};

}
