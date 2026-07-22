#include <iostream>
#include <vector>
using namespace std;

// Runs DFS from 'source' recursively, and records every edge that leads
// to a first (unvisited) discovery of a node. Those discovery edges
// together make up the DFS spanning tree.
void dfsVisit(int u, vector<vector<int>>& adj, vector<bool>& visited,
              vector<pair<int, int>>& treeEdges) {
    visited[u] = true;
    cout << u << " ";

    for (int v : adj[u]) {
        if (!visited[v]) {
            treeEdges.push_back({u, v});
            dfsVisit(v, adj, visited, treeEdges);
        }
    }
}

void dfsSpanningTree(int V, vector<vector<int>>& adj, int source) {
    vector<bool> visited(V, false);
    vector<pair<int, int>> treeEdges;

    cout << "\nDFS traversal order (nodes visited): ";
    dfsVisit(source, adj, visited, treeEdges);
    cout << endl;

    cout << "\nSpanning tree edges (in the order they were added):\n";
    for (auto& e : treeEdges) {
        cout << e.first << " -- " << e.second << endl;
    }

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            cout << "\nNote: node " << i << " was never reached, "
                 << "the graph is not fully connected from node " << source << "." << endl;
        }
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> adj(V);

    cout << "Enter each edge as: u v  (0-indexed vertices)\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);   // undirected graph
    }

    int source;
    cout << "Enter the starting vertex for DFS: ";
    cin >> source;

    dfsSpanningTree(V, adj, source);

    return 0;
}
