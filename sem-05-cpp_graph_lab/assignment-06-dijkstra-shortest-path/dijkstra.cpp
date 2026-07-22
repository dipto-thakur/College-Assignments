#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int, int> pii;   // (distance, vertex)

void dijkstra(int V, vector<vector<pii>>& adj, int source) {
    vector<int> dist(V, INT_MAX);
    dist[source] = 0;

    // min-heap ordered by distance, so we always expand the closest
    // unfinalized vertex next, that's the greedy idea behind Dijkstra's
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // this entry is stale, we've already found a shorter way to u
        if (d > dist[u]) continue;

        for (auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "\nShortest distances from source vertex " << source << ":\n";
    cout << "Vertex \tDistance\n";
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX) {
            cout << i << "\tunreachable\n";
        } else {
            cout << i << "\t" << dist[i] << endl;
        }
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<pii>> adj(V);

    cout << "Enter each edge as: u v weight  (0-indexed vertices, directed)\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        // uncomment the line below if your graph should be treated as
        // undirected instead of directed:
        // adj[v].push_back({u, w});
    }

    int source;
    cout << "Enter the source vertex: ";
    cin >> source;

    dijkstra(V, adj, source);

    return 0;
}
