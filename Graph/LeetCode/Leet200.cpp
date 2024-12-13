#include <bits/stdc++.h>

using namespace std;


class Solution {
    void dfs(vector<vector<char>>& grid, int row, int col, vector<vector<bool>>& visited){
        if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] == '0' || visited[row][col])
            return;
        visited[row][col]=true;
        dfs(grid, row + 1, col, visited);
        dfs(grid, row - 1, col, visited);
        dfs(grid, row, col + 1, visited);
        dfs(grid, row, col - 1, visited);
        return;
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<bool>> visited(r, vector<bool> (c, false));

        int island = 0;

        for (int i = 0; i < r; i++){
            for (int j = 0; j < c; j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    island++;
                    dfs(grid, i, j, visited);
                }
            }
        }
        return island;
    }
};