#include <bits/stdc++.h>
using namespace std;

// Approach 1: Tabulation

class Solution {
public:
    
    int minCostClimbingStairs(vector<int> &cost)
    {
        if(cost.size() < 2) {
            return min(cost[0], cost[1]);
        }
        vector<int> dp(cost.size(),-1);
        int n = cost.size();
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i = 2; i < n; i++) {
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }
        return min(dp[n - 1], dp[n - 2]);
    }
};




//  Approach 2: Recursion

// Start to End Approach
// class Solution {
// public:
//     int helper(vector<int>& cost, int end, vector<int>& dp) {
//         if(end >= cost.size()) {
//             return 0;
//         }
//         if(dp[end] != -1) {
//             return dp[end];
//         }
//         return dp[end] = cost[end] + min(helper(cost, end + 1, dp), helper(cost, end + 2, dp));
//     } 
//     int
//     minCostClimbingStairs(vector<int> &cost)
//     {
//         vector<int> dp(cost.size(),-1);
//         return min(helper(cost,0,dp), helper(cost,1,dp));
//     }
// };


// End to Start Approach
// class Solution {
// public:
//     int helper(vector<int>& cost, int end, vector<int>& dp) {
//         if(end < 2) {
//             return cost[end];
//         }
//         if(dp[end] != -1) {
//             return dp[end];
//         }
//         return dp[end] = cost[end] + min(helper(cost, end - 1, dp), helper(cost, end - 2, dp));
//     } 
//     int
//     minCostClimbingStairs(vector<int> &cost)
//     {
//         vector<int> dp(cost.size(),-1);
//         int n = cost.size();
//         return min(helper(cost,n-1,dp), helper(cost,n-2,dp));
//     }
// };