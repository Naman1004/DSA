#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Define a structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Define a structure to represent a graph
struct Graph {
    int V, E; // V is number of vertices, E is number of edges
    vector<Edge> edges;
};

// A structure to represent a subset for union-find
struct Subset {
    int parent;
    int rank;
};

// Function to create a graph with V vertices and E edges
Graph createGraph(int V, int E) {
    Graph graph;
    graph.V = V;
    graph.E = E;
    graph.edges = vector<Edge>(E);
    return graph;
}

// A utility function to find set of an element i (uses path compression)
int find(Subset subsets[], int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

// A function that does union of two sets of x and y (uses union by rank)
void Union(Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot;
    } else if (subsets[xroot].rank > subsets[yroot].rank) {
        subsets[yroot].parent = xroot;
    } else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Compare two edges according to their weights
bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

// The main function to construct MST using Kruskal's algorithm
void KruskalMST(Graph& graph) {
    int V = graph.V;
    vector<Edge> result(V); // This will store the resultant MST
    int e = 0; // An index variable, used for result[]
    int i = 0; // An index variable, used for sorted edges

    // Step 1: Sort all the edges in non-decreasing order of their weight
    sort(graph.edges.begin(), graph.edges.end(), compare);

    // Allocate memory for creating V subsets
    Subset* subsets = new Subset[(V * sizeof(Subset))];

    // Create V subsets with single elements
    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Number of edges to be taken is equal to V-1
    while (e < V - 1 && i < graph.edges.size()) {
        // Step 2: Pick the smallest edge. And increment the index for next iteration
        Edge next_edge = graph.edges[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        // If including this edge does not cause a cycle, include it in result and increment the index of result for next edge
        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }

    // Print the contents of result[] to display the built MST
    cout << "Following are the edges in the constructed MST\n";
    for (i = 0; i < e; ++i) {
        cout << result[i].src << " -- " << result[i].dest << " == " << result[i].weight << endl;
    }

    // Free allocated memory
    delete[] subsets;
}

// Main function to run the Kruskal's algorithm example
int main() {
    int V = 4; // Number of vertices in graph
    int E = 5; // Number of edges in graph
    Graph graph = createGraph(V, E);

    // Add edges
    graph.edges[0] = {0, 1, 10};
    graph.edges[1] = {0, 2, 6};
    graph.edges[2] = {0, 3, 5};
    graph.edges[3] = {1, 3, 15};
    graph.edges[4] = {2, 3, 4};

    // Function call
    KruskalMST(graph);

    return 0;
}
