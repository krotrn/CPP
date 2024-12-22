#include <bits/stdc++.h>

using namespace std;

class Solution {
    bool canPlaceQueen(int row, int col, vector<string>& grid) {
        // col check
        for (int i = row - 1; i >= 0; i--) {
            if (grid[i][col] == 'Q')
                return false;
        }
        // diagonal left
        for (int i = 1; row - i >= 0 && col - i >= 0; i++) {
            if (grid[row - i][col - i] == 'Q')
                return false;
        }
        // diagonal right
        for (int i = 1; row - i >= 0 && col + i < grid.size(); i++) {
            if (grid[row - i][col + i] == 'Q')
                return false;
        }
        return true;
    }
    void helper(int row, vector<string>& grid,
                vector<vector<string>>& ans) {
        if (row == grid.size()) {
            ans.push_back(grid);
            return;
        }

        for (int j = 0; j < grid.size(); j++) {
            if (canPlaceQueen(row, j, grid)) {
                grid[row][j] = 'Q';
                helper(row + 1, grid, ans);
                grid[row][j] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        string s(n, '.');
        vector<string> grid(n, s);
        vector<vector<string>> ans;
        helper(0, grid, ans);
        return ans;
    }
};


class Solution2 {

    void helper(int row, vector<string>& grid, vector<vector<string>>& ans, vector<bool> &col, vector<bool> & rightDiag, vector<bool> &leftDiag) {
        if(row == grid.size()) {
            ans.push_back(grid);
            return;
        }

        for (int j = 0; j < grid.size(); j++){
            if(col[j] || leftDiag[row - j + grid.size() - 1] || rightDiag[row + j]) continue;
            grid[row][j] = 'Q';
            col[j] = leftDiag[row - j + grid.size() - 1] = rightDiag[row + j] = true;
            helper(row + 1, grid, ans, col, rightDiag, leftDiag);
            grid[row][j] = '.';
            col[j] = leftDiag[row - j + grid.size() - 1] = rightDiag[row + j] = false;
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<bool> col(n, false);
        vector<bool> leftDiag(2*n - 1, false);
        vector<bool> rightDiag(2*n - 1, false);
        vector<string> grid(n, string(n, '.'));
        vector<vector<string>> ans;
        helper(0, grid, ans, col, rightDiag, leftDiag);
        return ans;
    }
};


int main() {
    Solution2 s;
    auto v = s.solveNQueens(7);
    for(auto r : v){
        for(auto ele : r)
            cout << ele << endl;
        cout << "-----------" << endl;
    }
    return 0;
}