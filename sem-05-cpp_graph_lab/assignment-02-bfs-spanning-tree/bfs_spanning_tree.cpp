#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Runs BFS from 'source' and, along the way, builds a spanning tree out
// of the edges that were actually used to first reach each new node.
// Those "first reach" edges are exactly what a BFS spanning tree is.
void bfsSpanningTree(int V, vector<vector<int>>& adj, int source) {
    vector<bool> visited(V, false);
    queue<int> q;

    visited[source] = true;
    q.push(source);

    cout << "\nBFS traversal order (nodes visited): ";
    vector<pair<int, int>> treeEdges;   // edges that make up the spanning tree

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                treeEdges.push_back({u, v});   // the edge used to discover v
                q.push(v);
            }
        }
    }
    cout << endl;

    cout << "\nSpanning tree edges (in the order they were added):\n";
    for (auto& e : treeEdges) {
        cout << e.first << " -- " << e.second << endl;
    }

    // if some node was never reached, the graph wasn't connected from
    // this source, so a single spanning tree covering everything
    // wasn't actually possible
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
    cout << "Enter the starting vertex for BFS: ";
    cin >> source;

    bfsSpanningTree(V, adj, source);

    return 0;
}
