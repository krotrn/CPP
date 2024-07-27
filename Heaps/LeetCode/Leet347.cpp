#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    typedef pair<int, int> pip;
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> m;
        // {element, frequency}
        for (int i = 0; i < nums.size(); i++)
            m[nums[i]]++;
        priority_queue<pip, vector<pip>, greater<pip>> pq;
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