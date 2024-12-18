#include <bits/stdc++.h>

using namespace std;

int find(int x, vector<int> &parent){
    return parent[x] = (parent[x] == x || parent[x] == -1) ? x : find(parent[x], parent);
}

void Union(int a, int b, vector<int> &parent, vector<int> &rank){
    a = find(a, parent);
    b = find(b, parent);
    if(a == b)
        return;
    if(rank[a] < rank[b])
        parent[a] = b;
    else if(rank[a] > rank[b])
        parent[b] = a;
    else{
        parent[a] = b;
        rank[b]++;
    }
}

struct Edge{
    int src, dest, wt;
};

bool cmp(Edge e1, Edge e2){
    return e1.wt < e2.wt;
}

long long kruskal(vector<Edge> &input, int v){
    sort(input.begin(), input.end(), cmp);
    long long ans = 0;
    vector<int> parent(v,-1);
    vector<int> rank(v, 0);
    int edgeCount = 0;
    for(auto &ele : input){
        int srcPar = find(ele.src, parent);
        int destPar = find(ele.dest, parent);
        if (srcPar == destPar) continue;
        Union(srcPar, destPar, parent, rank);
        ans += ele.wt;
        edgeCount++;
        if(edgeCount == v - 1)
            break;
    }
    return ans;
}


int main() {
    int v, e;
    cin >> v >> e;
    vector<Edge> input(e);
    for(auto &ele : input)
        cin >> ele.src >> ele.dest >> ele.wt;

    cout << kruskal(input, v) << endl;

    return 0;
}