#include <bits/stdc++.h>

using namespace std;

class Solution {
        bool isSafe(vector<vector<char>> &grid, int row, int col, char val){
        // Row
        for (int i = 0; i < 9; i++){
            if(grid[i][col] == val || grid[row][i] == val)
                return false;
        }
        // Box
        int sr = row - row % 3, sc = col - col % 3;
        for (int i = sr; i < sr + 3; i++){
            for (int j = sc; j < sc + 3; j++){
                if(grid[i][j] == val)
                    return false;
            }
        }
        return true;
    }
    bool helper(vector<vector<char>> &grid, int row, int col){
        if(row == 9)
            return true;
        
        if(col == 9)
            return helper(grid, row + 1, 0);
        

        if(grid[row][col] != '.')
            return helper(grid, row, col + 1);
        
        for (char i = '1'; i <= '9'; i++){
            if(isSafe(grid, row, col, i)){
                grid[row][col] = i;
                if(helper(grid, row, col + 1))
                    return true;
                
                grid[row][col] = '.';
            }
        }
        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        helper(board, 0, 0);
    }
};

static const auto speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};

int main() {
    cout << "" << endl;
    return 0;
}