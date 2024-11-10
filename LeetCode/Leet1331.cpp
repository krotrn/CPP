#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if (arr.empty())
            return arr;
        // rank[i] = {arr[i], i}
        vector<pair<int, int>> rank(arr.size(), {0, 0});
        for (int i = 0; i < arr.size(); i++)
            rank[i] = {arr[i], i};
        // sort rank array based on arr[i]
        sort(rank.begin(), rank.end());
        arr[rank[0].second] = 1;
        for (int i = 1; i < arr.size(); i++)
            arr[rank[i].second] = (rank[i].first == rank[i - 1].first) ? arr[rank[i - 1].second] : (arr[rank[i - 1].second] + 1);
        return arr;
    }
};