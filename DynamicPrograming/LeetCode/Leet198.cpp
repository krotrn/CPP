#include<bits/stdc++.h>
using namespace std;


// stateof DP = a set of all parameter using which we can identify a sub-problem uniquely.

// class Solution {
//     /**
//      * Timelimit Exceeded
//      */
// public:
//     int helper(vector<int>& nums, int start){
//         return nums[start] + max(((nums.size() > start + 2) ? helper(nums, start + 2) : 0), ((nums.size() > start + 3) ? helper(nums, start + 3) : 0));
//     }
//     int rob(vector<int>& nums) {
//         if(nums.empty())
//             return 0;
//         if(nums.size() == 1)
//             return nums[0];
//         return max(helper(nums, 0), ((nums.size() > 0) ? helper(nums, 1) : 0));
//     }
// };

// class Solution {
//     /**
//      * Memorylimit Exceeded
//      */
// public:
//     int helper(vector<int>& nums, int start, vector<int> dp){
//         if(dp[start] != -1)
//             return dp[start];
//         return dp[start] = nums[start] + max(((nums.size() > start + 2) ? helper(nums, start + 2,dp) : 0), ((nums.size() > start + 3) ? helper(nums, start + 3,dp) : 0));
//     }
//     int rob(vector<int>& nums) {
//         if(nums.empty())
//             return 0;
//         if(nums.size() == 1)
//             return nums[0];
//         vector<int> dp(nums.size(),-1);
//         return dp[0] = max(helper(nums, 0, dp), ((nums.size() > 0) ? helper(nums, 1, dp) : 0));
//     }
// };

class Solution {
public:
    int helper(vector<int>& nums, int start, vector<int>& dp){
        if(dp[start] != -1)
            return dp[start];
        if(nums.size() == start + 1)
            return dp[start] = nums[start];
        if(nums.size() == start + 2)
            return dp[start] = max(nums[start], nums[start + 1]);
        return dp[start] = max(helper(nums, start + 1, dp), nums[start] + helper(nums, start + 2, dp));
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return helper(nums, 0,dp);
    }
};

int main (){
    Solution s;
    vector<int> v = {0};
    cout << s.rob(v);
}