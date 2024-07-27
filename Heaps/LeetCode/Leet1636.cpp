#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    typedef pair<int, int> pip;
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> m;
        // {element, frequency}
        for (int i = 0; i < nums.size(); i++)
            m[nums[i]]++;
        auto cmp = [](pip left, pip right) {
            if (left.first == right.first)
                return left.second <right.second; // Sort by element in decreasing order if frequencies are the same
            return left.first >right.first; // Sort by frequency in increasing order
        };
        priority_queue<pip, vector<pip>, decltype(cmp)> pq(cmp);
        // {frequency, element}
        for (auto e : m)
            pq.push({e.second, e.first});
        vector<int> ans;
        // {element}
        while (!pq.empty()) {
            for (int i = 0; i < pq.top().first; i++)
                ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};