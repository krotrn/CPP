#include <bits/stdc++.h>

using namespace std;

vector<list<pair<int,int>>> graph;
int v;
void add_edge(int src, int dest,int wei, bool bi_dir = true){
    graph[src].push_back({dest, wei});
    if(bi_dir)
        graph[dest].push_back({src, wei});
}

void display(){
    for (int i = 0; i < graph.size(); i++){
        cout << i << " -> ";
        for(auto ele:graph[i]){
            cout <<"{"<< ele.first<<", "<<ele.second<<"}" << ", ";
        }
        cout << endl;
    }
}

int main() {
    cin >> v;
    graph.resize(v, list<pair<int,int>>());
    int e;
    cin >> e;
    while(e--){
        int s, d, w;
        cin >> s >> d >> w;
        add_edge(s, d, w);
    }
    display();
    cout << "" << endl;
    return 0;
}