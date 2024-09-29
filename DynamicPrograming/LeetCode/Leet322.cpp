#include <bits/stdc++.h>
using namespace std;

class Solution {
    int minimizeCoins(vector<int>& coins, int x, vector<int>& dp) {
        if(x == 0)
            return 0;
        if(dp[x] != -2)
            return dp[x];
        int result = INT_MAX;
        for (int i = 0; i < coins.size(); i++) {
            if (x - coins[i] >= 0) {
                result = min(result, minimizeCoins(coins, x - coins[i], dp));
            }
        }
        return dp[x] = (result == INT_MAX) ? INT_MAX : result + 1;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -2);
        int ans = minimizeCoins(coins, amount, dp);
        return ans == INT_MAX ? -1 : ans;
    }
};