#pragma once
#include <vector>

namespace CycleUndirectedDFS {
	using namespace std;
	bool dfsCycleUndirected(int node, int parent, vector<bool>& visited, vector<vector<int>>& adj) {
		visited[node] = true;

		for (int neighbour : adj[node]) {
			if (!visited[neighbour]) {
				if (dfsCycleUndirected(neighbour, node, visited, adj)) {
					return true;
				}
			}
			else if (neighbour != parent) {
				return true;
			}
		}

		return false;
	}

	bool isCycle(int V, vector<vector<int>>& adj) {

		vector<bool> visited(V, false);

		for (int i = 0; i < V; ++i) {
			if (!visited[i]) {
				if (dfsCycleUndirected(i, -1, visited, adj))
					return true;
			}
		}

		return false;
	}

}