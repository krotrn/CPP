#include <bits/stdc++.h>

using namespace std;

class Solution{
    int helper(int k, vector<int> &prices, int idx, bool ongoing, vector<vector<vector<int>>> &dp){
        if(idx == prices.size())
            return 0;
        // avoid
        if(dp[idx][k][ongoing] != -1)
            return dp[idx][k][ongoing];
        dp[idx][k][ongoing] = helper(k, prices, idx + 1, ongoing, dp);
        if(ongoing)
            return dp[idx][k][ongoing] = max(dp[idx][k][ongoing], prices[idx] + helper(k - 1, prices, idx + 1, false, dp));
        else {
            if(k)
                return dp[idx][k][ongoing] = max(dp[idx][k][ongoing], helper(k - 1, prices, idx + 1, true, dp) - prices[idx]);
        }
        return dp[idx][k][ongoing]; 
    }
public:
    int maxProfit(int k, vector<int> &prices){
        vector<vector<vector<int>>> dp(prices.size() + 1, vector<vector<int>>(k + 1, vector<int>(2, -1)));
        int idx = 0;
        return helper(k, prices, idx, false, dp);
    }
};


int main(int argc, char const *argv[])
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
