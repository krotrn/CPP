#include <bits/stdc++.h>

using namespace std;
// catalan Number


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


class Solution{
public:
    int numTrees(int n){
        if(n<=1) return 1;
        if(n == 2) return 2;
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++)
            for (int j = 1; j <= i; j++)
                dp[i] += dp[j - 1] * dp[i - j];
        return dp[n];
    }
};