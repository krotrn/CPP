#include <bits/stdc++.h>

using namespace std;

vector<list<int>> graph;
int v;
void add_edge(int src, int dest, bool bi_dir = true){
    graph[src].push_back(dest);
    if(bi_dir)
        graph[dest].push_back(src);
}

bool bfs(int src){
    queue<int> q;
    unordered_set<int> visited;
    vector<int> par(v, -1);
    q.push(src);
    bool result = false;
    visited.insert(src);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(auto neighbour : graph[curr]){
            if(visited.count(neighbour) && par[curr] != neighbour)
                return true;
            if(!visited.count(neighbour)){
                q.push(neighbour);
                par[neighbour] = curr;
                visited.insert(neighbour);
            }
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
            result = bfs(i);
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
    cout << "" << endl;
    return 0;
}