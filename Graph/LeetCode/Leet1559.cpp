#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<pair<int, int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    bool dfs(int pos, vector<vector<char>> &grid, vector<vector<bool>> &visited, int par) {
        int rows = grid.size();
        int cols = grid[0].size();
        int x = pos / cols;
        int y = pos % cols;
        visited[x][y] = true;
        
        for (auto dir : direction) {
            int i = x + dir.first;
            int j = y + dir.second;

            // Check bounds and matching character
            if (i >= 0 && i < rows && j >= 0 && j < cols && grid[i][j] == grid[x][y]) {
                int newPos = i * cols + j;

                if (newPos != par) {
                    if (visited[i][j] || dfs(newPos, grid, visited, pos))
                        return true;
                }
            }
        }
        return false;
    }

public:
    bool containsCycle(vector<vector<char>> &grid) {
        int r = grid.size();
        int c = grid[0].size();
        if (grid.empty() || grid[0].empty())
            return false;

        vector<vector<bool>> visited(r, vector<bool>(c, false));
        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (!visited[i][j] && dfs(i * c + j, grid, visited, -1))
                    return true;
            }
        }
        return false;
    }
};


int main() {
    cout << "" << endl;
    return 0;
}