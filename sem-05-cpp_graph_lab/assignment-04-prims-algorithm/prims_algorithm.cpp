#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Classic O(V^2) Prim's algorithm using an adjacency matrix.
// 0 in the matrix means "no direct edge" between two distinct vertices.
void primMST(int V, vector<vector<int>>& graph) {
    vector<int> parent(V, -1);         // parent[i] = the MST-side vertex that connects to i
    vector<int> key(V, INT_MAX);       // key[i] = cheapest edge weight found so far to reach i
    vector<bool> inMST(V, false);      // whether vertex i is already part of the tree

    key[0] = 0;   // start building the tree from vertex 0

    for (int count = 0; count < V - 1; count++) {
        // pick the vertex not yet in the MST with the smallest key value
        int u = -1;
        int minKey = INT_MAX;
        for (int v = 0; v < V; v++) {
            if (!inMST[v] && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }

        if (u == -1) {
            // remaining vertices are unreachable, the graph isn't connected
            break;
        }

        inMST[u] = true;

        // relax the keys of u's neighbors now that u has joined the tree
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    int totalWeight = 0;
    cout << "\nEdges included in the Minimum Spanning Tree:\n";
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++) {
        if (parent[i] != -1) {
            cout << parent[i] << " -- " << i << "\t" << key[i] << endl;
            totalWeight += key[i];
        } else {
            cout << "Vertex " << i << " is unreachable, no edge added.\n";
        }
    }
    cout << "\nTotal weight of MST: " << totalWeight << endl;
}

int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V, 0));

    cout << "Enter the adjacency matrix (" << V << " x " << V
         << "), use 0 for 'no edge':\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    primMST(V, graph);

    return 0;
}
