#include <bits/stdc++.h>
using namespace std;

// https://cses.fi/problemset/task/1634

class Solution {
public:
    int minimizeCoins(vector<int>& coins, int x, vector<int> &dp ){
        dp[0] = 0;
        for (int i = 1; i <= x; i++){
            int result = INT_MAX;
            for (int j = 0; j < coins.size(); j++ ){
                if(i-coins[j] && dp[i-coins[j]] != -2)
                result = min(result, dp[i - coins[j]]);
            }
            dp[i] = result == INT_MAX? result : result + 1;
        }
        return dp[x];
    }
    int minimizeCoins2(vector<int>& coins, int x, vector<int>& dp) {
        if(x == 0)
            return 0;
        if(dp[x] != -2)
            return dp[x];
        int n = coins.size();
        int result = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (x - coins[i] >= 0) {
                result = min(result, minimizeCoins(coins, x - coins[i], dp));
            }
        }
        return dp[x] = (result == INT_MAX) ? INT_MAX : result + 1;
    }
};

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    vector<int> dp(x + 1, -2);
    Solution s;
    int ans = s.minimizeCoins2(coins, x, dp);
    cout<<( ans == INT_MAX ? -1 : ans )<< endl;
    return 0;
}