#include <bits/stdc++.h>
using namespace std;

// https://atcoder.jp/contests/dp/tasks/dp_c
class Solution {

    int helper(int i, int j, vector<vector<int>> &h, vector<vector<int>> &dp) {
        if (i == 0)
            return h[i][j];
        if (dp[i][j] != -1)
            return dp[i][j];
        if (j == 0)
            return dp[i][j] = h[i][j] + max(helper(i - 1, 1, h, dp), helper(i - 1, 2, h, dp));
        else if (j == 1)
            return dp[i][j] = h[i][j] + max(helper(i - 1, 0, h, dp), helper(i - 1, 2, h, dp));
        return dp[i][j] = h[i][j] + max(helper(i - 1, 0, h, dp), helper(i - 1, 1, h, dp));
    }

public:
    int maxHappyness(vector<vector<int>> &happy) {
        int n = happy.size();
        vector<vector<int>> dp(n, vector<int>(3, -1));
        return max({helper(n - 1, 0, happy, dp), helper(n - 1, 1, happy, dp), helper(n - 1, 2, happy, dp)});
    }
};

int main() {
    Solution s;
    int n;
    cin >> n;
    vector<vector<int>> happy(n, vector<int>(3));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> happy[i][j];
        }
    }
    cout << s.maxHappyness(happy) << endl;
    return 0;
}