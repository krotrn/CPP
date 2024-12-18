#include <bits/stdc++.h>

using namespace std;

vector<list<pair<int,int>>> graph;
int v;

void addEdge(int src, int dest, int wt, int bidir = true){
    graph[src].push_back({dest, wt});
    if(bidir) graph[dest].push_back({src, wt});
}

// visited set, heap<pair>, unordered_map
// insert the pair <-1, src> in heap
// 1 by 1 remove the root element of heap
// if root is vesited continue
// mark visited
// add ans 
// update map
// go to every neighbour ony those which are not visited and better weight than previous.

long long prism(int src = 0){
    long long ans = 0;
    vector<bool> visited(v + 1, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;  // {weight, vertex}
    vector<int> parent(v + 1, -1); // parent of each vertex
    vector<int> weight(v + 1, INT_MAX); // weight of each vertex
    pq.push({0, src}); // {weight, vertex}
    weight[src] = 0; // weight of source is 0
    int totalVertex = 0;
    while(!pq.empty()){
        auto ele = pq.top();
        pq.pop(); 
        // if the vertex is already visited
        if(visited[ele.second])
            continue;
        visited[ele.second] = true; // mark the vertex as visited 
        ans += ele.first;
        totalVertex++;
        if(totalVertex == v)
            break;
        // go to every neighbour of the vertex
        for(auto neighbour : graph[ele.second]){
            // if the neighbour is not visited and the weight of the neighbour is less than the previous weight
            if(!visited[neighbour.first] && neighbour.second < weight[neighbour.first]){
                weight[neighbour.first] = neighbour.second; // update the weight of the neighbour
                pq.push({neighbour.second, neighbour.first});  // push the neighbour in the heap
                parent[neighbour.first] = ele.second; // update the parent of the neighbour
            }
        }
    }
    return ans;
}

int main() {
    int e;
    cin >> v >> e;
    graph.resize(v + 1);
    while(e--){
        int src, dest, wt;
        cin >> src >> dest >> wt;
        addEdge(src, dest, wt);
    }
    int src;
    cin >> src;
    cout<<prism(src)<<endl;
    return 0;
}