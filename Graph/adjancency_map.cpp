#include <bits/stdc++.h>

using namespace std;

vector<unordered_map<int,int>> graph;
int v;
void add_edge(int src, int dest, int weight, bool bi_dir = true){
    graph[src][dest] = weight;
    if(bi_dir) {
        graph[dest][src] = weight;
    }
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
    graph.resize(v, unordered_map<int,int>());
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