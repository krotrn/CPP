#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2, 0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for(int i = 1; i<n; i++){
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0]-prices[i]);
        }
        return dp[n-1][0];
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = prices[0];
        int ans = 0;
        for (int i = 1; i < n; i++){
            ans += max(0,prices[i] - buy);
            buy = min(buy, prices[i]);
        }
        return ans;
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;
        for (int i = 1; i < n; i++)
            ans += max(0,prices[i] - prices[i-1]);
        return ans;
    }
};


