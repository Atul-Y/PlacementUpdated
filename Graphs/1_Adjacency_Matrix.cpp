// C++ program to demonstrate Adjacency Matrix
// representation of undirected and unweighted graph
#include <bits/stdc++.h>
using namespace std;
#define V 5
void addEdge(int adjMatrix[V][V], int u, int v) {
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1; // For undirected graph
}
void printMatrix(int adjMatrix[V][V]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}
int main() {
    int adjMatrix[V][V] = {0}; // Initialize all entries to 0

    addEdge(adjMatrix, 0, 1);
    addEdge(adjMatrix, 0, 4);
    addEdge(adjMatrix, 1, 2);
    addEdge(adjMatrix, 1, 3);
    addEdge(adjMatrix, 1, 4);
    addEdge(adjMatrix, 2, 3);
    addEdge(adjMatrix, 3, 4);

    printMatrix(adjMatrix);

    return 0;
}
//using vector of vectors
#include <bits/stdc++.h>
using namespace std;
#define V 5
void addEdge(vector<vector<int>>& adjMatrix, int u, int v) {
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1; // For undirected graph
}
void printMatrix(const vector<vector<int>>& adjMatrix) {
    for (const auto& row : adjMatrix) {
        for (const auto& val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}
int main() {
    vector<vector<int>> adjMatrix(V, vector<int>(V, 0)); // Initialize VxV matrix with 0

    addEdge(adjMatrix, 0, 1);
    addEdge(adjMatrix, 0, 4);
    addEdge(adjMatrix, 1, 2);
    addEdge(adjMatrix, 1, 3);
    addEdge(adjMatrix, 1, 4);
    addEdge(adjMatrix, 2, 3);
    addEdge(adjMatrix, 3, 4);

    printMatrix(adjMatrix);

    return 0;
}

// Output:
// 0 1 0 0 1
// 1 0 1 1 1
// 0 1 0 1 0
// 0 1 1 0 1
// 1 1 0 1 0
// Time Complexity: O(1) for addEdge and O(V^2) for printMatrix
// Space Complexity: O(V^2) for adjacency matrix
// Where V is the number of vertices in the graph 
// Note: Adjacency matrix is not space efficient for sparse graphs
// It is more suitable for dense graphs where number of edges is close to V^2
// For weighted graph, we can store the weight instead of 1 in the matrix
// If there is no edge between two vertices, we can store 0 or infinity based on the context
// For directed graph, we only need to update adjMatrix[u][v] = 1
// and not adjMatrix[v][u] = 1
// In case of self-loops, we can set adjMatrix[u][u] = 1
// Adjacency matrix can be used to check if there is an edge between two vertices in O(1) time
// It can also be used to find all neighbors of a vertex in O(V) time
// However, it is not efficient for finding all edges in the graph as it takes O(V^2) time
// For very large graphs, adjacency list representation is preferred over adjacency matrix
// as it is more space efficient and can perform most operations in O(E) time where E is the number of edges
// Adjacency matrix is also used in algorithms like Floyd-Warshall for finding shortest paths
// and in network flow algorithms like Edmonds-Karp
// It is also used in graph algorithms that require fast access to edge weights
// like Prim's and Dijkstra's algorithms
// However, for very large graphs with millions of vertices, even adjacency list may not be feasible
// In such cases, we can use more advanced data structures like compressed sparse row (CSR)
// or compressed sparse column (CSC) to store the graph efficiently
// These data structures store only the non-zero entries of the adjacency matrix
// and allow for efficient traversal and access to edges
// They are commonly used in scientific computing and machine learning applications
// In summary, adjacency matrix is a simple and effective way to represent graphs
// but it has its limitations and is not suitable for all types of graphs
// especially sparse graphs or very large graphs.
// Choose the right representation based on the specific requirements of the problem at hand.
// Always consider the trade-offs between time complexity, space complexity, and ease of implementation
// when selecting a graph representation.
// Happy Coding!
