#pragma once
#include <vector>
#include <algorithm>
#include "./DisjointSet.h"

namespace Kruskal {
	using namespace std;

	// edge: u,v,edgeWeight
	int getMinWeight(vector<vector<int>>& edges, int total_nodes) {
		sort(edges.begin(), edges.end(),[](vector<int>& edge1, vector<int>& edge2){
			return edge1[2] < edge2[2];
		});

		DisjointSet::DSU dsu(total_nodes);
		int mstWeight = 0;

		for (auto& edge: edges) {
			int u = edge[0], v = edge[1], w = edge[2];

			if (dsu.unionSet(u,v)) {
				mstWeight += w;
			}
		}

		return mstWeight;
	}
}