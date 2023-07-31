#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

const int INF = 1e9;

// Function to find the shortest path using Dijkstra's algorithm
void dijkstra(int startNode, unordered_map<int, vector<pair<int, int>>>& adjList, vector<int>& distances) {
    int n = adjList.size();
    distances.assign(n, INF);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, startNode});
    distances[startNode] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        int dist_u = pq.top().first;
        pq.pop();

        if (dist_u > distances[u]) continue;

        for (const auto& neighbor : adjList[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                pq.push({distances[v], v});
            }
        }
    }
}

// Function to add an edge to the graph
void addEdge(unordered_map<int, vector<pair<int, int>>>& adjList, int u, int v, int weight) {
    adjList[u].push_back({v, weight});
    // For an undirected graph, add the reverse edge as well
    adjList[v].push_back({u, weight});
}

// Function to build the graph from user input
void buildGraph(unordered_map<int, vector<pair<int, int>>>& adjList) {
    int n, m; // n: number of nodes, m: number of edges
    cout << "Enter the number of nodes in the graph: ";
    cin >> n;
    cout << "Enter the number of edges in the graph: ";
    cin >> m;

    cout << "Enter " << m << " edges (u v weight format, 0-based indexing):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        addEdge(adjList, u, v, weight);
    }
}

int main() {
    unordered_map<int, vector<pair<int, int>>> adjList;
    buildGraph(adjList);

    int startNode;
    cout << "Enter the starting node for Dijkstra's algorithm: ";
    cin >> startNode;

    int totalNodes = adjList.size();
    vector<int> distances(totalNodes, INF);

    dijkstra(startNode, adjList, distances);

    cout << "Shortest distances from node " << startNode << " to all other nodes:" << endl;
    for (int i = 0; i < totalNodes; i++) {
        if (distances[i] == INF)
            cout << "Node " << i << ": Not reachable" << endl;
        else
            cout << "Node " << i << ": " << distances[i] << endl;
    }

    return 0;
}
