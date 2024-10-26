#include <bits/stdc++.h>

using namespace std;

class Solution{
    int helper(int n, vector<int> &dp){
        if (n <= 1)
            return 1;
        if(dp[n] != -1)
            return dp[n];
        int ans = 0;
        for (int i = 1; i <= n; i++)
            ans += helper(i - 1, dp) * helper(n - i, dp);
        return dp[n] = ans;
    }
public:
    int numTrees(int n){
        vector<int> dp(n + 1, -1);
        return helper(n, dp);
    }
};