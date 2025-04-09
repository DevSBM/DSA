#pragma once
#include <vector>
using namespace std;

namespace CycleDirectedDFS {
	bool dfsCycleDirected(int node, vector<bool>& visited, vector<bool>& recStack, vector<vector<int>>& adj) {
		visited[node] = true;
		recStack[node] = true;

		for (int neighbour : adj[node]) {
			if (!visited[neighbour]) {
				if (dfsCycleDirected(neighbour, visited, recStack, adj)) {
					return true;
				}
			}
			else if (recStack[neighbour]) {
				return true;
			}
		}

		recStack[node] = false;

		return false;
	}

	bool isCycle(int V, vector<vector<int>>& adj) {

		vector<bool> visited(V, false);
		vector<bool> recStack(V, false);


		for (int i = 0; i < V; ++i) {
			if (!visited[i]) {
				if (dfsCycleDirected(i,visited,recStack, adj))
					return true;
			}
		}

		return false;
	}
}