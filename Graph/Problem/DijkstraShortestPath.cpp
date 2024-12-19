#include <bits/stdc++.h>

using namespace std;

// Adjacency list representation of the graph
vector<vector<pair<int, int>>> graph;
int v; // Number of vertices
vector<int> dist; // Stores shortest distances from source

// Function to add an edge to the graph
void add_edge(int src, int dest, int weight, bool bi_dir = true) {
    graph[src].emplace_back(dest, weight); // Add edge from src to dest
    if (bi_dir)
        graph[dest].emplace_back(src, weight); // Add edge from dest to src if bidirectional
}

// Function to display the graph's adjacency list
void display() {
    for (int i = 0; i < graph.size(); i++) {
        cout << i << " -> ";
        for (const auto& ele : graph[i]) {
            cout << ele.first << "(" << ele.second << "), ";
        }
        cout << endl;
    }
}

// Implementation of Dijkstra's algorithm
void dijkstra(int src, vector<int>& parent) { // O((V + E)logV) time complexity
    dist.assign(v, INT_MAX); // Initialize all distances to infinity
    vector<bool> visited(v, false); // Track visited vertices
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min-heap {dist, vertex}

    pq.push({0, src}); // Start with the source vertex
    dist[src] = 0; // Distance to source is zero
    parent[src] = -1; // Source has no parent
    int total_visited = 0; // To keep track of visited vertices

    while (!pq.empty()) { // O((V + E)logV) loop
        auto ele = pq.top();
        pq.pop();

        if (visited[ele.second]) // Skip already visited nodes
            continue;
        visited[ele.second] = true;
        total_visited++;
        if(total_visited == v) // If all vertices are visited, break
            break;

        for ( auto neighbour : graph[ele.second]) { // Relaxation step: O(E) loop
            // Relaxation step: Update dist if a shorter path is found
            if (!visited[neighbour.first] && dist[neighbour.first] > ele.first + neighbour.second) {
                dist[neighbour.first] = ele.first + neighbour.second;
                pq.push({dist[neighbour.first], neighbour.first});
                parent[neighbour.first] = ele.second; // Update parent to reconstruct path
            }
        }
    }
}

// Function to print the shortest path from source to destination
void print_path(int src, int dest, const vector<int>& parent) {
    if (dist[dest] == INT_MAX) { // Check if destination is reachable
        cout << "No path exists from " << src << " to " << dest << "." << endl;
        return;
    }

    vector<int> path; // To store the path
    for (int v = dest; v != -1; v = parent[v]) { // Backtrack from destination to source // O(V) loop
        path.push_back(v);
    }
    reverse(path.begin(), path.end()); // Reverse to get the correct order // O(V) loop

    cout << "Shortest path from " << src << " to " << dest << ":" << endl;
    for (int v : path) // Print the path // O(V) loop
        cout << v << " ";
    cout << endl << "Total weight: " << dist[dest] << endl;
}

int main() {
    cin >> v; // Input number of vertices
    graph.resize(v); // Resize graph to hold adjacency lists

    int e; // Number of edges
    cin >> e;
    for (int i = 0; i < e; i++) {
        int s, d, w;
        cin >> s >> d >> w; // Input source, destination, and weight of the edge
        add_edge(s, d, w);
    }

    display(); // Display the graph

    int src, dest;
    cin >> src; // Input source and destination vertices
    cin >> dest; // Input source and destination vertices

    vector<int> parent(v, -1); // To store the shortest path tree
    dijkstra(src, parent); // Compute shortest paths

    // Print the shortest distances from the source vertex
    cout << "Shortest distances from source " << src << ":" << endl;
    for (int i = 0; i < v; i++) { // O(V) loop
        cout << "Vertex " << i << ": " << (dist[i] == INT_MAX ? -1 : dist[i]) << endl;
    }

    print_path(src, dest, parent); // Print the shortest path to destination
    return 0;
}


// inputs: 
// 7 9
// 0 1 1
// 0 2 5
// 1 2 4 
// 1 3 1
// 3 4 1
// 2 4 1
// 3 6 2
// 6 5 1
// 4 5 5 
