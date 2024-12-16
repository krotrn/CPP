#include <bits/stdc++.h>

using namespace std;

class Solution {
    int find(int x, vector<int> &parent){
        if(parent[x] == -1)
            parent[x] = x;
        return (parent[x] != x) ? parent[x] = find(parent[x], parent) : x;
    }

    void Union(int x, int y, vector<int> &parent, vector<int> &size){
        x = find(x, parent);
        y = find(y, parent);
        if(x == y)
            return;
        if(size[x]<size[y]){
            parent[x] = y;
            size[y] += size[x];
        }else{
            parent[y] = x;
            size[x] = size[y];
        }
    }
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> parent(n, -1), size(n, 1);
        for(auto edge: edges){
            Union(edge[0], edge[1], parent, size);
        }

        unordered_map<int, int> connected;
            for (int i = 0; i < n; i++) {
                int root = find(i, parent);
                connected[root]++;
            }

        long long totalPairs = (long long)n * (n - 1) / 2; 
        for (auto [root, compSize] : connected) {
            totalPairs -= (long long)compSize * (compSize - 1) / 2;
        }

        return totalPairs;
    }
};

int main() {
    cout << "" << endl;
    return 0;
}