#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;

void floydWarshall(int V, vector<vector<int>>& dist, vector<vector<int>>& next) {
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    // whenever the route through k improves i -> j, the
                    // first step of the new best route from i to j is
                    // now the same as the first step of the best route
                    // from i to k, that's what makes path reconstruction
                    // possible afterward
                    next[i][j] = next[i][k];
                }
            }
        }
    }
}

// Walks the 'next' matrix from source to destination, one hop at a
// time, to rebuild the actual sequence of vertices on the shortest path.
vector<int> reconstructPath(int u, int v, vector<vector<int>>& next) {
    vector<int> path;
    if (next[u][v] == -1) {
        return path;   // empty: no path exists between u and v
    }

    path.push_back(u);
    while (u != v) {
        u = next[u][v];
        path.push_back(u);
    }
    return path;
}

void printMatrix(int V, vector<vector<int>>& dist) {
    cout << "\nFinal all-pairs shortest distance matrix:\n\n";
    cout << "\t";
    for (int j = 0; j < V; j++) cout << j << "\t";
    cout << endl;

    for (int i = 0; i < V; i++) {
        cout << i << "\t";
        for (int j = 0; j < V; j++) {
            if (dist[i][j] >= INF) {
                cout << "INF\t";
            } else {
                cout << dist[i][j] << "\t";
            }
        }
        cout << endl;
    }
}

int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    vector<vector<int>> dist(V, vector<int>(V));
    vector<vector<int>> next(V, vector<int>(V));

    cout << "Enter the adjacency matrix (" << V << " x " << V
         << "), use -1 for 'no direct edge', 0 only on the diagonal:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            int val;
            cin >> val;
            dist[i][j] = (val == -1) ? INF : val;

            // next[i][j] starts as "the first hop on the direct edge
            // i -> j", or -1 if no such edge exists yet
            if (i == j || val == -1) {
                next[i][j] = (i == j) ? i : -1;
            } else {
                next[i][j] = j;
            }
        }
        dist[i][i] = 0;
        next[i][i] = i;
    }

    floydWarshall(V, dist, next);
    printMatrix(V, dist);

    cout << "\nReconstructed shortest paths:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i == j) continue;

            vector<int> path = reconstructPath(i, j, next);
            cout << i << " -> " << j << " : ";
            if (path.empty()) {
                cout << "no path exists\n";
            } else {
                for (size_t idx = 0; idx < path.size(); idx++) {
                    cout << path[idx];
                    if (idx != path.size() - 1) cout << " -> ";
                }
                cout << "  (distance " << dist[i][j] << ")\n";
            }
        }
    }

    return 0;
}
