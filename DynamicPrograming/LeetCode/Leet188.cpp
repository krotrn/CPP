#include <bits/stdc++.h>

using namespace std;

class Solution {
    // Approach: 1 Recursive
    int helper(int k, vector<int>& prices, int idx, bool ongoing, vector<vector<vector<int>>>& dp) {
        if (idx == prices.size() || k == 0)
            return 0;
        if (dp[idx][k][ongoing] != -1)
            return dp[idx][k][ongoing];
        // avoid
        dp[idx][k][ongoing] = helper(k, prices, idx + 1, ongoing, dp);
        if (ongoing)
            dp[idx][k][ongoing] = max(dp[idx][k][ongoing], prices[idx] + helper(k - 1, prices, idx + 1, false, dp));
        else
            dp[idx][k][ongoing] = max(dp[idx][k][ongoing], helper(k, prices, idx + 1, true, dp) - prices[idx]);
        return dp[idx][k][ongoing];
    }

    // Approach: 2 Iterative
    int helper2(int k, vector<int>& prices, vector<vector<vector<int>>>& dp) {
        int n = prices.size();
        for (int i = 0; i <= k; i++) {
            dp[0][i][0] = 0;          // no stocks
            dp[0][i][1] = -prices[0]; // stocks
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= k; j++) {
                // for not holding stock
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
                // for holding stock
                dp[i][j][1] =
                    max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
            }
        }
        return dp[n - 1][k][0];
    }

public:
    int maxProfit(int k, vector<int>& prices) {
        // vector<vector<vector<int>>> dp(prices.size() + 1, vector<vector<int>>(k + 1, vector<int>(2, -1)));
        // return helper(k, prices, 0, false, dp);
        vector<vector<vector<int>>> dp(prices.size() + 1, vector<vector<int>>(k + 1, vector<int>(2, 0)));
        if (prices.size() == 0 || k == 0)
            return 0;

        if (k >= prices.size() / 2) {
            int maxProfit = 0;
            for (int i = 1; i < prices.size(); ++i) 
                maxProfit += max(0, prices[i] - prices[i - 1]);
            return maxProfit;
        }

        return helper2(k, prices, dp);
    }
};


int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> prices(n);
    for (int idx = 0; idx < n; ++idx)
        cin >> prices[idx];
    Solution s;
    cout << s.maxProfit(k, prices);
    return 0;
}
