#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to perform Depth-First Traversal
void DFS(int node, unordered_map<int, vector<int>>& adjList, vector<bool>& visited) {
    cout << node << " ";
    visited[node] = true;

    for (int neighbor : adjList[node]) {
        if (!visited[neighbor])
            DFS(neighbor, adjList, visited);
    }
}

// Function to add an edge to the graph
void addEdge(unordered_map<int, vector<int>>& adjList, int u, int v) {
    adjList[u].push_back(v);
    adjList[v].push_back(u); // For an undirected graph
}

// Function to build the graph from user input
void buildGraph(unordered_map<int, vector<int>>& adjList) {
    int n, m; // n: number of nodes, m: number of edges
    cout << "Enter the number of nodes in the graph: ";
    cin >> n;
    cout << "Enter the number of edges in the graph: ";
    cin >> m;

    cout << "Enter " << m << " edges (u v format, 0-based indexing):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(adjList, u, v);
    }
}

int main() {
    unordered_map<int, vector<int>> adjList;
    buildGraph(adjList);

    int startNode;
    cout << "Enter the starting node for Depth-First Traversal: ";
    cin >> startNode;

    int totalNodes = adjList.size();
    vector<bool> visited(totalNodes, false);

    cout << "Depth-First Traversal starting from node " << startNode << ": ";
    DFS(startNode, adjList, visited);
    cout << endl;

    return 0;
}
