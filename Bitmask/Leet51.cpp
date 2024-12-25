#include <bits/stdc++.h>
using namespace std;

class Solution {
    void helper(int row, vector<string>& grid, vector<vector<string>>& ans,
                int& col, int& rightDiag, int& leftDiag) {
        if (row == grid.size()) {
            ans.push_back(grid);
            return;
        }

        for (int j = 0; j < grid.size(); j++) {
            if ((col & (1 << j)) ||
                (leftDiag & (1 << (row - j + grid.size() - 1))) ||
                (rightDiag & (1 << (row + j))))
                continue;
            grid[row][j] = 'Q';
            col |= (1 << j);
            leftDiag |= (1 << (row - j + grid.size() - 1));
            rightDiag |= (1<<(row + j));
            helper(row + 1, grid, ans, col, rightDiag, leftDiag);
            grid[row][j] = '.';
            col ^= (1 << j);
            leftDiag ^= (1 << (row - j + grid.size() - 1));
            rightDiag ^= (1<<(row + j));
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        int col = 0;
        int leftDiag = 0;
        int rightDiag = 0;
        vector<string> grid(n, string(n, '.'));
        vector<vector<string>> ans;
        helper(0, grid, ans, col, rightDiag, leftDiag);
        return ans;
    }
};