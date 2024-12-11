#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<pair<int, int>> internal;
    void dfs(vector<vector<int>>& grid, int r, int c, int color, int &ogC){
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] != ogC)
            return;
        grid[r][c] = -color;
        dfs(grid, r + 1, c, color, ogC);
        dfs(grid, r - 1, c, color, ogC);
        dfs(grid, r, c + 1, color, ogC);
        dfs(grid, r, c - 1, color, ogC);

        if (!(r == 0 || c == 0 || r == grid.size() - 1 || c == grid[0].size() - 1 || grid[r + 1][c] != -color || grid[r - 1][c] != -color || grid[r][c - 1] != -color || grid[r][c + 1] != -color)){
            internal.push_back({r, c});
        }
    }

public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int ogC = grid[row][col];
        dfs(grid, row, col, color, ogC);
        for(auto ele : internal)
            grid[ele.first][ele.second] = ogC;
        for(auto &r : grid){
            for(auto &c : r){
                if(c<0) c *= -1;
            }
        }
        return grid;
    }
};