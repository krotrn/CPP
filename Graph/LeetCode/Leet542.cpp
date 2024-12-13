#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size(); // Get the number of rows in the matrix
        int cols = mat[0].size(); // Get the number of columns in the matrix
        queue<pair<int, int>> q; // Queue to perform BFS
        vector<pair<int,int>> dir = {{1,0}, {0,1}, {-1,0}, {0,-1}}; // Directions for moving up, down, left, and right

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(mat[i][j] == 0)
                    q.push({i, j}); // Add the cell with 0 to the queue
                else
                    mat[i][j] = INT_MAX; // Set the cell with 1 to INT_MAX
            }
        }
        int distance = 0; // Distance from the cell with 0 to the cell with 1
        while(!q.empty()){
            int n = q.size();
            for (int i = 0; i < n; i++){
                auto p = q.front(); // Get the front element of the queue
                q.pop(); // Remove the front element from the queue
                for(auto d: dir){
                    int x = p.first + d.first;
                    int y = p.second + d.second;
                    // Check if the adjacent cell is within bounds and has a distance greater than the current cell
                    if (x >= 0 && x < rows && y >= 0 && y < cols && mat[x][y] > distance){
                        mat[x][y] = distance; // Update the distance of the adjacent cell
                        q.push({x, y}); // Add the adjacent cell to the queue
                    }
                }
            }
            distance++; // Increment the distance after each level of BFS
        }

        return mat; // Return the updated matrix
    }
};