#include <bits/stdc++.h>

using namespace std;

// https://www.hackerrank.com/challenges/kruskalmstrsub/problem

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
    int minimumCost(int n, vector<vector<int>>& connection) {
        if (n == 0 || connection.empty()) return -1;
        sort(connection.begin(), connection.end(), [](vector<int> &a, vector<int> &b) {
            return a[2] < b[2];
        });
        vector<int> parent(n + 1, -1), rank(n + 1, 0);
        int ans = 0;
        int edgeCount = 0;
        for(const auto &ele : connection){
            int srcPar = find(ele[0], parent);
            int desPar = find(ele[1], parent);
            if(srcPar == desPar) continue;
            ans += ele[2];
            edgeCount++;
            if(edgeCount == n - 1)
                break;
        }

        return (edgeCount == n - 1) ? ans : -1;
    }
};