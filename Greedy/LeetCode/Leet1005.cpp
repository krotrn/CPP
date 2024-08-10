#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) { // T.C = O(nlogn + k)
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end()); // T.C = O(n)
        int sum = 0;
        for (int ele:nums) // T.C = O(n)
            sum += ele;
        while (k--) // T.C = O(klogn)
        {
            if(pq.top() == 0)
                break;
            int x = pq.top();
            pq.pop();
            pq.push(-x);
            sum = sum - 2*x;
        }
        return sum;
    }
};