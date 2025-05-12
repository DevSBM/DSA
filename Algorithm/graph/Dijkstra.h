#pragma once
#include <iostream>
#include <vector>
#include <queue>

namespace Dijkstra {
	using namespace std;

	void findShortest(int V, vector<vector<pair<int, int>>>& adj, int src) {

		// adj: list of adjacent elements 
		// pair<int,int>: {node,weight}

		vector<int> dist(V, INT_MAX);
		vector<int> nodeParent(V,-1);

		// We can also not set parent of source
		// as we can stop loop when a nodeParent==-1
		//nodeParent[src] = src;

		
		// weight,node
		priority_queue<pair<int, int>, vector<pair<int, int>,greater<>>> pq;
		pq.push({0,src});

		while (!pq.empty()) {
			auto [nodeDist, node] = pq.top();
			pq.pop();

			// If we have already found shorter distance for the node
			if (nodeDist > dist[node]) {
				continue;
			}

			// neighbourDist: currentNode->neighbourNode distance
			for (auto [neighbour, neighbourDist] : adj[node]) {
				int curDist = neighbourDist + nodeDist;
				if (curDist < dist[neighbour]) {
					dist[neighbour] = curDist;
					nodeParent[neighbour] = node;
					pq.push({curDist,neighbour});
				}
			}
		}
	}
}
