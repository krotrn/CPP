#include <bits/stdc++.h>

using namespace std;

vector<list<int>> graph;
unordered_set<int> visited;
int v;
void add_edge(int src, int dest, bool bi_dir = true){
    graph[src].push_back(dest);
    if(bi_dir)
        graph[dest].push_back(src);
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

bool dfs(int current, int end){
    if(current == end)
        return true;
    visited.insert(current);
    for(auto neighbour : graph[current]){
        if(not visited.count(neighbour)){
            bool result = dfs(neighbour, end);
            if(result)
                return true;
        }
    }
    return false;
}

bool anyPath(int src, int dest){
    return dfs(src, dest);
}

int main() {
    cout << "Enter the nomber of vertices : " << endl;
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
    if(anyPath(src, dest))
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;
    cout << "" << endl;
    return 0;
}