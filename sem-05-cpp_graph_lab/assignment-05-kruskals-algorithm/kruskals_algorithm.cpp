#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
};

// Disjoint Set Union (a.k.a. Union-Find), this is what Kruskal's uses
// to detect cycles without actually walking the tree being built.
class DSU {
    vector<int> parent, rank_;

public:
    DSU(int n) {
        parent.resize(n);
        rank_.assign(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;   // everyone starts as their own set
    }

    // path compression: while finding the root, point every node
    // along the way directly at it, so future lookups are faster
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    // union by rank: attach the smaller tree under the bigger one,
    // keeps the DSU structure shallow
    bool unite(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);

        if (rootA == rootB) {
            return false;   // already in the same set, joining them would form a cycle
        }

        if (rank_[rootA] < rank_[rootB]) {
            parent[rootA] = rootB;
        } else if (rank_[rootA] > rank_[rootB]) {
            parent[rootB] = rootA;
        } else {
            parent[rootB] = rootA;
            rank_[rootA]++;
        }
        return true;
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    vector<Edge> edges(E);
    cout << "Enter each edge as: u v weight  (0-indexed vertices)\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    // Kruskal's core idea: always try the cheapest remaining edge first
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    });

    DSU dsu(V);
    vector<Edge> mst;
    int totalWeight = 0;

    cout << "\nProcessing edges in increasing order of weight:\n";
    for (const Edge& e : edges) {
        // find() tells us if u and v are already connected through some
        // other path already in the MST, if they are, adding this edge
        // would close a cycle, so it gets skipped instead
        if (dsu.find(e.u) == dsu.find(e.v)) {
            cout << e.u << " -- " << e.v << " (weight " << e.weight
                 << ")  -> skipped, would form a cycle\n";
            continue;
        }

        dsu.unite(e.u, e.v);
        mst.push_back(e);
        totalWeight += e.weight;
        cout << e.u << " -- " << e.v << " (weight " << e.weight
             << ")  -> added to MST\n";
    }

    cout << "\nFinal MST edge set:\n";
    cout << "Edge \tWeight\n";
    for (const Edge& e : mst) {
        cout << e.u << " -- " << e.v << "\t" << e.weight << endl;
    }
    cout << "\nTotal weight of MST: " << totalWeight << endl;

    if ((int)mst.size() < V - 1) {
        cout << "\nNote: only " << mst.size() << " edges were added, "
             << "the graph is not fully connected, so this is a minimum "
             << "spanning forest rather than a single spanning tree.\n";
    }

    return 0;
}
