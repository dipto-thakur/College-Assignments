#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int INF = 1e9;   // stands in for "no path yet", using a large finite
                        // number instead of INT_MAX avoids overflow when
                        // two INF values get added together

void floydAllPairs(int V, vector<vector<int>>& dist) {
    // try every vertex k as a possible "stepping stone" between every
    // pair (i, j). If going i -> k -> j is shorter than the best i -> j
    // route found so far, update it. By the time k has looped through
    // every vertex, dist[i][j] holds the true shortest path using any
    // combination of intermediate vertices.
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

void printMatrix(int V, vector<vector<int>>& dist) {
    cout << "\nAll-pairs shortest distance matrix:\n\n";
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

    cout << "Enter the adjacency matrix (" << V << " x " << V
         << "), use -1 for 'no direct edge', 0 only on the diagonal:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            int val;
            cin >> val;
            dist[i][j] = (val == -1) ? INF : val;
        }
        dist[i][i] = 0;   // distance from a vertex to itself is always 0
    }

    floydAllPairs(V, dist);
    printMatrix(V, dist);

    return 0;
}
