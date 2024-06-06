#include <iostream>
using namespace std;

class Graph {
private:
    int numVertices;
    int** adjMatrix;

public:
    Graph(int numVertices) {
        this->numVertices = numVertices;

        // Initialize the adjacency matrix
        adjMatrix = new int*[numVertices];
        for (int i = 0; i < numVertices; i++) {
            adjMatrix[i] = new int[numVertices];
            for (int j = 0; j < numVertices; j++) {
                adjMatrix[i][j] = 0;
            }
        }
    }

    void addEdge(int u, int v) {
        // Add an edge between vertex u and vertex v
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // Since it's an undirected graph
    }

    void removeEdge(int u, int v) {
        // Remove the edge between vertex u and vertex v
        adjMatrix[u][v] = 0;
        adjMatrix[v][u] = 0; // Since it's an undirected graph
    }

    void display() {
        // Display the adjacency matrix
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    ~Graph() {
        // Destructor to free up allocated memory
        for (int i = 0; i < numVertices; i++) {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
    }
};

int main() {
    int numVertices = 5;
    Graph g(numVertices);

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    cout << "Adjacency Matrix:" << endl;
    g.display();

    return 0;
}
