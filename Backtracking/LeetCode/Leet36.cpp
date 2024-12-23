#include <bits/stdc++.h>

using namespace std;

class Solution {
    bool isSafe(vector<vector<char>>& grid, int row, int col, char val) {
        // Row
        for (int i = 0; i < 9; i++) {
            if (grid[i][col] == val && i != row)
                return false;
        }
        // column
        for (int i = 0; i < 9; i++) {
            if (i != col && grid[row][i] == val)
                return false;
        }
        // Box
        int sr = row - row % 3, sc = col - col % 3;
        for (int i = sr; i < sr + 3; i++) {
            for (int j = sc; j < sc + 3; j++) {
                if (grid[i][j] == val && !(i == row && col == j))
                    return false;
            }
        }
        return true;
    }

public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;
                if (!isSafe(board, i, j, board[i][j]))
                    return false;
            }
        }
        return true;
    }
};

int main() {
    cout << "" << endl;
    return 0;
}