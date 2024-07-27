#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef pair<int, int> pip;
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pip> pq;
        for(auto e: arr)
        {
            pq.push({abs(e-x), e});
            if(pq.size() > k)
                pq.pop();
        }
        vector<int> ans;
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};