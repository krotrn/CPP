#include <bits/stdc++.h>

using namespace std;

vector<list<int>> graph;
int v;
void add_edge(int src, int dest, bool bi_dir = true){
    graph[src].push_back(dest);
    if(bi_dir)
        graph[dest].push_back(src);
}

bool dfs(int src, int parent, unordered_set<int> &visited){
    visited.insert(src);
    bool result = false;
    for(auto neighbour : graph[src]){
        // if neighbour is visited and not parent then cycle is detected
        if (visited.count(neighbour) && neighbour != parent)
            return true;
        // if neighbour is not visited then visit it
        if (!visited.count(neighbour)){
            result = dfs(neighbour, src, visited);
            // if cycle found return true
            if(result)
                return true;
        }

    }
    return false;
}

// for disconnected graph
bool hasCycle(){
    unordered_set<int> visited;
    bool result = false;
    for (int i = 0; i < v; i++){
        if(!visited.count(i)){
            result = dfs(i, -1, visited);
            // if cycle found return true
            if(result)
                return true;
        }
    }
    return false;
}

void display(){
    for (int i = 0; i < graph.size(); i++){
        cout << i << " -> ";
        for(auto ele:graph[i]){
            cout << ele << ", ";
        }
        cout << endl;
    }
}

int main() {
    cin >> v;
    graph.resize(v, list<int>());
    int e;
    cin >> e;
    while(e--){
        int s, d;
        cin >> s >> d;
        add_edge(s, d);
    }
    display();
    auto x = (hasCycle()) ? "Has Cycle" : "Not Cycle";
    cout << x << endl;
    return 0;
}