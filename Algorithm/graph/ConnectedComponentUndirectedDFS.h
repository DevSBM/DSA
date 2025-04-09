#pragma once
#include <vector>

namespace ConnectedComponentUndirectedDFS {
    using namespace std;

    void dfs(int node, vector<bool>& visited, vector<vector<int>>& adj, vector<int>& component) {
        visited[node] = true;
        component.push_back(node);
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, visited, adj, component);
            }
        }
    }

    vector<vector<int>> getConnectedComponentsDFS(int V, vector<vector<int>>& adj) {
        vector<bool> visited(V, false);
        vector<vector<int>> components;

        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                vector<int> component;
                dfs(i, visited, adj, component);
                components.push_back(component);
            }
        }

        return components;
    }

}