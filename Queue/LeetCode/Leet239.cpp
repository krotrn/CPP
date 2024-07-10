#include <iostream>
#include <queue>
#include <stack>
#include <deque>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        deque<int> dq;
        int n = nums.size();
        if (n == 1)
            return nums;
        vector<int> ans(n - k + 1);
        for (int i = 0; i < n; i++)
        {
            while (dq.size() && nums[dq.back()] < nums[i])
                dq.pop_back();
            dq.push_back(i);
            if (i >= k - 1)
            {
                while(dq.size() && dq.front() < i-k+1)
                    dq.pop_front();
                ans[i - k + 1] = nums[dq.front()];
            }
        }
        return ans;
    }
};