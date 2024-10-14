#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());

        long long ans = 0;
        
        for (int i = 0; i < k; ++i) {
            int curr = pq.top();
            pq.pop();

            ans += curr;

            pq.push((curr + 2) / 3);
        }

        return ans;
    }
};
