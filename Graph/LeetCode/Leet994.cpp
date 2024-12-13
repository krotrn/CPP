#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size(); // Get the number of rows in the grid
        int cols = grid[0].size(); // Get the number of columns in the grid
        vector<pair<int,int>> dir = {{1,0}, {0,1}, {-1,0}, {0,-1}}; // Directions for moving up, down, left, and right
        queue<pair<int, int>> rotten; // Queue to perform BFS
        int fresh = 0; // Count of fresh oranges

        // Iterate through the grid to count fresh oranges and add rotten oranges to the queue
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
            if(grid[i][j] == 2)
                rotten.push({i, j}); // Add rotten orange to the queue
            else if (grid[i][j] == 1){
                fresh++; // Count fresh orange
            }
            }
        }

        // If there are no fresh oranges, return 0
        if (!fresh)
            return 0;

        int time = 0; // Time taken to rot all oranges

        // Perform BFS to rot adjacent fresh oranges
        while(!rotten.empty()){
            int n = rotten.size();
            for (int i = 0; i < n; i++){
            auto p = rotten.front(); // Get the front element of the queue
            rotten.pop(); // Remove the front element from the queue
            for(auto d: dir){
                int x = p.first + d.first;
                int y = p.second + d.second;
                // Check if the adjacent cell is within bounds and has a fresh orange
                if (x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] == 1){
                grid[x][y] = 2; // Rot the fresh orange
                rotten.push({x, y}); // Add the newly rotten orange to the queue
                fresh--; // Decrease the count of fresh oranges
                }
            }
            }
            time++; // Increment time after each level of BFS
        }

        // If there are no fresh oranges left, return the time taken, otherwise return -1
        return fresh == 0 ? time - 1 : -1;
    }
};