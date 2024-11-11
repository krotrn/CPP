#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> dp(n + 1, INT_MAX - 1);
        for (int i = 0; i <= n; i++){
            int start = max(0, i - ranges[i]);
            int end = min(n, i + ranges[i]);
            for (int j = start; j <= end; j++)
                dp[end] = min(dp[end], dp[j] + 1);
        }
        return dp[n] == INT_MAX - 1 ? -1 : dp[n];
    }
};