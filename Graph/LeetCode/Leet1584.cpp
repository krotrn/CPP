#include <bits/stdc++.h>

using namespace std;

class Solution {
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

public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>> Edges;
        for (int i = 0; i < points.size(); i++){
            for (int j = i + 1; j<points.size(); j++){
                int weight = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                Edges.push_back({i, j, weight});
            }
        }

        vector<int> parent(points.size(), -1), rank(points.size(), 0);

        sort(edges.begin(), edges.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[2] < b[2]; });

        int ans = 0;
        int EdgeCount = 0;

        for(const auto& edge: Edges){
            int srcPar = find(edge[0], parent);
            int destPar = find(edge[1], parent);
            if(srcPar == destPar) continue;
            Union(srcPar, destPar, parent, rank);
            ans += edge[2];
            EdgeCount++;
            if(EdgeCount == points.size() - 1)
                break;
        }
        return ans;
    }
};

int main() {
    cout << "" << endl;
    return 0;
}