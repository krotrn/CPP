#include <bits/stdc++.h>

using namespace std;

class Solution {
    int helper(int str, int stc, int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (str == m || stc == n)
            return INT_MAX;
        if (str == m - 1 and stc == n - 1)
            return grid[str][stc];
        if (dp[str][stc] != -1)
            return dp[str][stc];
        return dp[str][stc] = grid[str][stc] + min(helper(str + 1, stc, m, n, grid, dp), helper(str, stc + 1, m, n, grid, dp));
    }

public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return helper(0, 0, m, n, grid, dp);
    }
};

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 1; i < m; i++)
            grid[i][0] += grid[i - 1][0];
        for (int i = 1; i < n; i++)
            grid[0][i] += grid[0][i];
        for (int i = 1; i < m; i++){
            for (int j = 1; j < n; j++)
                grid[i][j] = grid[i][j] + min(grid[i - 1][j], grid[i][j - 1]);
        }

        return grid[m - 1][n - 1];
    }
};
