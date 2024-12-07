#include <bits/stdc++.h>

using namespace std;

// Graph represented as an adjacency list
vector<list<int>> graph;
// Set to keep track of visited nodes
unordered_set<int> visited;
// Vector to store all paths from source to destination
vector<vector<int>> results;
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

// Depth First Search (DFS) to find all paths from current node to end node
void dfs(int current, int end, vector<int> &path){
    path.push_back(current);
    if(current == end){
        results.push_back(path);
        path.pop_back();
        return;
    }
    visited.insert(current);
    for(auto neighbour : graph[current]){
        if(not visited.count(neighbour)){
            dfs(neighbour, end, path);
        }
    }
    path.pop_back();
    visited.erase(current);
    return;
}

// Function to find all paths from src to dest
void allPath(int src, int dest){
    vector<int> v;
    dfs(src, dest, v);
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
    int src, dest;
    cout << "Enter the start and destination : " << endl;
    cin >> src >> dest;
    allPath(src, dest);
    for(auto paths: results){
        for(auto ele: paths){
            cout << ele;
            if(ele!=dest)
                cout << "->";
        }
        cout << "\n";
    }
    return 0;
}