#include <bits/stdc++.h>

using namespace std;

// Graph represented as an adjacency list
vector<list<int>> graph;
// Set to keep track of visited nodes
unordered_set<int> visited;
// Number of vertices in the graph
int v;

// Function to add an edge to the graph
void add_edge(int src, int dest, bool bi_dir = true){
    graph[src].push_back(dest);
    if(bi_dir)
        graph[dest].push_back(src);
}

// Function to display the graph
void display(){
    for (int i = 0; i < graph.size(); i++){
        cout << i << " -> ";
        for(auto ele:graph[i]){
            cout << ele << ", ";
        }
        cout << endl;
    }
}

void bfs(int src, vector<int> &dist){
    queue<int> q;
    visited.clear();
    dist[src] = 0;
    visited.insert(src);
    q.push(src);
    while(!q.empty()){
        int curr = q.front();
        cout << curr << " ";
        q.pop();
        for(auto neighbour : graph[curr]){
            if(!visited.count(neighbour)) {
                dist[neighbour] = dist[curr] + 1;
                q.push(neighbour);
                visited.insert(neighbour);
            }
        }
    }
    cout << "\n";
}

int main() {
    cout << "Enter the number of vertices : " << endl;
    cin >> v;
    graph.resize(v, list<int>());
    cout << "Enter the number of Edges : " << endl;
    int e;
    cin >> e;
    visited.clear();
    while(e--){
        int s, d;
        cin >> s >> d;
        add_edge(s, d);
    }
    display();
    vector<int> dist(v, INT_MAX);
    cout << "Enter the Source : " << endl;
    int src;
    cin >> src;
    bfs(src, dist);
    for (int i = 0; i < dist.size(); i++)
    {
        cout << dist[i] << " ";
    }
    return 0;
}