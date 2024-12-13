#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<pair<int,int>> dir = {{1,0}, {0,1}, {-1,0}, {0,-1}}; // Directions for moving up, down, left, and right

    void dfs(vector<vector<int>>& grid, int x, int y, queue<pair<int, int>>& boundary) {
        int rows = grid.size(), cols = grid[0].size();
        if (x < 0 || x >= rows || y < 0 || y >= cols || grid[x][y] != 1) return;

        grid[x][y] = -1; // Mark as visited
        bool isBoundary = false;
        for (auto d : dir) {
            int nx = x + d.first, ny = y + d.second;
            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && grid[nx][ny] == 0) {
                isBoundary = true;
            }
            dfs(grid, nx, ny, boundary);
        }

        if (isBoundary) {
            boundary.push({x, y}); // Store boundary cell for BFS
        }
    }

public:
    int shortestBridge(vector<vector<int>>& grid) {
        int rows = grid.size(); // Get the number of rows in the grid
        int cols = grid[0].size(); // Get the number of columns in the grid

        int r = 0, c = 0; // Variables to store the row and column of the second island
        bool found = false; // Flag to stop after marking the first island
        queue<pair<int, int>> islandBoundary; // Queue to store the boundary cells of the first island

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1 && !found) {
                    dfs(grid, i, j, islandBoundary); // Mark the first island and save its boundary
                    found = true; // Stop searching for the first island
                } else if (grid[i][j] == 1 && found) {
                    r = i;
                    c = j;
                }
            }
        }

        int steps = 0; // Variable to store the number of steps taken to reach the second island
        while(!islandBoundary.empty()) {
            int n = islandBoundary.size();
            for (int i = 0; i < n; ++i) {
                auto p = islandBoundary.front();
                islandBoundary.pop();
                for (auto d : dir) {
                    int nx = p.first + d.first, ny = p.second + d.second;
                    if (nx >= 0 && nx < rows && ny >= 0 && ny < cols) {
                        if (grid[nx][ny] == 1) {
                            return steps; // Return the number of steps taken to reach the second island
                        } else if (grid[nx][ny] == 0) {
                            islandBoundary.push({nx, ny}); // Add the boundary cell to the queue
                            grid[nx][ny] = -1; // Mark the boundary cell as visited
                        }
                    }
                }
            }
            steps++; // Increment the number of steps after each level of BFS
        }

        return -1; // Return -1 if the second island cannot be reached

    }
};