#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {// T.C. O(nlogk) aux space O(k)
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < nums.size(); i++) // T.C. O(n)
        {
            pq.push(nums[i]); // T.C. O(logk)
            // pop the minimum element
            if (pq.size() > k)
                pq.pop(); // T.C. O(logk)
        }
        return pq.top();
    }
};