#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>

using namespace std;

typedef pair<int, int> pii;

class Graph {
    int V; // Number of vertices
    vector<vector<pii>> adj; // Adjacency list

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // If the graph is undirected
    }

    void dijkstra(int src) {
        // Min-heap priority queue
        priority_queue<pii, vector<pii>, greater<pii>> pq;

        // Distance vector initialized to infinity
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        pq.push({0, src});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            // Traverse all adjacent vertices of u
            for (auto &neighbor : adj[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                // If there's a shorter path to v through u
                if (dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        // Print shortest distances
        cout << "Vertex Distance from Source" << endl;
        for (int i = 0; i < V; ++i) {
            cout << i << " \t\t " << dist[i] << endl;
        }
    }
};

int main() {
    int V = 9; // Number of vertices in the graph
    Graph g(V);

    // Add edges to the graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    g.dijkstra(0); // Run Dijkstra's algorithm from vertex 0

    return 0;
}
