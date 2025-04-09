#pragma once
#include <vector>
#include <queue>

// If not all nodes are visited, there is a cycle (also known as Kahn's Algorithm)
namespace TopoSortBFS {
	using namespace std;

	vector<int> TopoSort(int V, const vector<vector<int>>& adj) {
		vector<int> indegree(V,0),topoSorted;
		queue<int> q;

		for (int u = 0; u < V; u++) {
			for (int v : adj[u]) {
				indegree[v]++;
			}
		}
		for (int u = 0; u < V; u++) {
			if (indegree[u] == 0) {
				q.push(u);
			}
		}

		while (!q.empty()) {
			int node = q.front();
			q.pop();

			topoSorted.push_back(node);

			for (int neighbour : adj[node]) {
				indegree[neighbour]--;
				if (indegree[neighbour] == 0) {
					q.push(neighbour);
				}
			}
		}


		return topoSorted;
	}
}