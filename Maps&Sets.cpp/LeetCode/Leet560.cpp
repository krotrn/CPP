#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        unordered_map<int, int> m;
        int count = 0;
        int sum = 0;
        m[0] = 1; // if sum-k=0 then it means that there is a subarray with sum k
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];                 // sum of elements till i
            if (m.find(sum - k) != m.end()) // if sum-k is already present in map then it means that there is a subarray with sum k
                count += m[sum - k];
            m[sum]++;
        }
        return count;
    }
};

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        unordered_map<int, int> m;
        int count = 0;
        vector<int> pre(n, 0);
        pre[0] = nums[0];
        for (int i = 1; i < n; i++) {
            pre[i] = nums[i] + pre[i - 1];
        }
        for (int i = 0; i < n; i++) {
            if (pre[i] == k)
                count++;
            int rem = pre[i] - k;
            if (m.find(rem) != m.end())
                count += m[rem];
            m[pre[i]]++;
        }
        return count;
    }
};