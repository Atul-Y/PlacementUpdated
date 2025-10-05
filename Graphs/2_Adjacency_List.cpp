//Adjacency List Representation

//Adjacency List for Directed graph:

#include <bits/stdc++.h>
using namespace std;
#define V 5
void addEdge(vector<vector<int>>& adjList, int u, int v) {
    adjList[u].push_back(v); // For directed graph
}
void printList(const vector<vector<int>>& adjList) {
    for (int i = 0; i < adjList.size(); i++) {
        cout << i << ": ";
        for (const auto& val : adjList[i]) {
            cout << val << " ";
        }
        cout << endl;
    }
}
int main() {
    vector<vector<int>> adjList(V); // Initialize adjacency list with V vertices

    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 4);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 1, 4);
    addEdge(adjList, 2, 3);
    addEdge(adjList, 3, 4);

    printList(adjList);

    return 0;
}
//------------------------------------------------------------------

//Adjacency List for Undirected graph:
#include <bits/stdc++.h>
using namespace std;
#define V 5
void addEdge(vector<vector<int>>& adjList, int u, int v) {
    adjList[u].push_back(v);
    adjList[v].push_back(u); // For undirected graph
}
void printList(const vector<vector<int>>& adjList) {
    for (int i = 0; i < adjList.size(); i++) {
        cout << i << ": ";
        for (const auto& val : adjList[i]) {
            cout << val << " ";
        }
        cout << endl;
    }
}
int main() {
    vector<vector<int>> adjList(V); // Initialize adjacency list with V vertices

    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 4);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 1, 4);
    addEdge(adjList, 2, 3);
    addEdge(adjList, 3, 4);

    printList(adjList);

    return 0;
}

//------------------------------------------------------------------

//Adjacency List for Directed and Weighted graph:
#include <bits/stdc++.h>
using namespace std;
#define V 5
void addEdge(vector<vector<pair<int, int>>>& adjList, int u, int v, int weight) {
    adjList[u].push_back({v, weight}); // For directed graph
}
void printList(const vector<vector<pair<int, int>>>& adjList) {
    for (int i = 0; i < adjList.size(); i++) {
        cout << i << ": ";
        for (const auto& val : adjList[i]) {
            cout << "(" << val.first << ", " << val.second << ") ";
        }
        cout << endl;
    }
}
int main() {
    vector<vector<pair<int, int>>> adjList(V); // Initialize adjacency list with V vertices

    addEdge(adjList, 0, 1, 10);
    addEdge(adjList, 0, 4, 20);
    addEdge(adjList, 1, 2, 30);
    addEdge(adjList, 1, 3, 40);
    addEdge(adjList, 1, 4, 50);
    addEdge(adjList, 2, 3, 60);
    addEdge(adjList, 3, 4, 70);

    printList(adjList);

    return 0;
}

//------------------------------------------------------------------
//Adjacency List for Undirected and Weighted graph:
#include <bits/stdc++.h>
using namespace std;
#define V 5
void addEdge(vector<vector<pair<int, int>>>& adjList, int u, int v, int weight) {
    adjList[u].push_back({v, weight});
    adjList[v].push_back({u, weight}); // For undirected graph
}
void printList(const vector<vector<pair<int, int>>>& adjList) {
    for (int i = 0; i < adjList.size(); i++) {
        cout << i << ": ";
        for (const auto& val : adjList[i]) {
            cout << "(" << val.first << ", " << val.second << ") ";
        }
        cout << endl;
    }
}
int main() {
    vector<vector<pair<int, int>>> adjList(V); // Initialize adjacency list with V vertices

    addEdge(adjList, 0, 1, 10);
    addEdge(adjList, 0, 4, 20);
    addEdge(adjList, 1, 2, 30);
    addEdge(adjList, 1, 3, 40);
    addEdge(adjList, 1, 4, 50);
    addEdge(adjList, 2, 3, 60);
    addEdge(adjList, 3, 4, 70);

    printList(adjList);

    return 0;
}

//------------------------------------------------------------------

//time complexity: O(V + E) where V is number of vertices and E is number of edges
//space complexity: O(V + E) for adjacency list
//whereas for adjacency matrix time complexity is O(V^2) and space complexity is O(V^2)
//Adjacency list is more space efficient for sparse graphs
//Adjacency matrix is more space efficient for dense graphs
//Also adjacency list is more efficient for iterating over all edges
//Adjacency list is used in algorithms like DFS, BFS, Dijkstra's, Prim's, Kruskal's etc.
//Adjacency matrix is used in algorithms like Floyd-Warshall, Bellman-Ford etc  
//Also adjacency list can be easily modified to store additional information like weights, capacities etc.
//In adjacency list we can use vector of vectors, vector of lists, array of vectors, array of lists etc. depending on the requirements
//In adjacency matrix we can use 2D array or vector of vectors
//In adjacency list we can also use unordered_map or map to store the adjacency list for dynamic graphs

