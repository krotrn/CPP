#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef pair<int, int> pip;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pip>> pq;
        for(auto e: points)
        {
            int x = e[0], y = e[1];
            pq.push({(x*x + y*y), {x, y}});
            if(pq.size() > k)
                pq.pop();
        }
        vector<vector<int>> ans;
        while(!pq.empty())
        {
            ans.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }
        return ans;
    }
};