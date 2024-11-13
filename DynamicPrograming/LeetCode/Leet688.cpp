#include <bits/stdc++.h>

using namespace std;

class Solution{
    double helper(int n, int k, int r, int c, vector<vector<vector<double>>> &dp){
        if(r < 0 || c < 0 || r >= n || c >= n)
            return 0;
        if(k == 0)
            return 1;
        if(dp[r][c][k] > -0.9)
            return dp[r][c][k];

        // // possible moves by Knight
        // vector<pair<int, int>> direction = {{2, 1}, {2, -1}, {1, 2}, {1, -2}, {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}};
        // dp[r][c][k] = 0.0;
        // for(auto [sr, sc] : direction)
        //     dp[r][c][k] += helper(n, k - 1, r + sr, c + sc, dp) / 8.0;
        // return dp[r][c][k];

        double ans = 0.0;
        ans += helper(n, k - 1, r + 2, c + 1, dp);
        ans += helper(n, k - 1, r + 2, c - 1, dp);
        ans += helper(n, k - 1, r + 1, c + 2, dp);
        ans += helper(n, k - 1, r + 1, c - 2, dp);
        ans += helper(n, k - 1, r - 2, c + 1, dp);
        ans += helper(n, k - 1, r - 2, c - 1, dp);
        ans += helper(n, k - 1, r - 1, c + 2, dp); 
        ans += helper(n, k - 1, r - 1, c - 2, dp);
        return dp[r][c][k] = (ans/8.0);
    }
public:
    double knightProbability(int n, int k, int row, int column){
        vector<vector<vector<double>>> dp(n + 1, vector<vector<double>>(n + 1, vector<double>( k + 1, -1.0)));
        return helper(n, k, row, column, dp);
    }
};