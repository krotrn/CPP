#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size(); // Get the number of rows in the board
        int cols = board[0].size(); // Get the number of columns in the board
        vector<pair<int,int>> dir = {{1,0}, {0,1}, {-1,0}, {0,-1}}; // Directions for moving up, down, left, and right
        queue<pair<int,int>> q; // Vector to store the border cells

        for (int i = 0; i < rows; i++){
            if(board[i][0] == 'O'){
                q.push({i, 0}); // Add the left border cell
                board[i][0] = 'B'; // Mark the left border cell as visited
            }
            if(board[i][cols - 1] == 'O'){
                q.push({i, cols - 1}); // Add the right border
                board[i][cols - 1] = 'B'; // Mark the right border cell as visited
            }
        }

        for (int i = 0; i < cols; i++){
            if(board[0][i] == 'O'){
                q.push({0, i}); // Add the top border cell
                board[0][i] = 'B'; // Mark the top border cell as visited
            }
            if(board[rows - 1][i] == 'O'){
                q.push({rows - 1, i}); // Add the bottom border cell
                board[rows - 1][i] = 'B'; // Mark the bottom border cell as visited
            }
        }


        while(!q.empty()){
            auto p = q.front(); // Get the front element of the queue
            q.pop(); // Remove the front element from the queue

            for(auto d: dir){
                int x = p.first + d.first;
                int y = p.second + d.second;

                // Check if the adjacent cell is within bounds and has an 'O'
                if (x >= 0 && x < rows && y >= 0 && y < cols && board[x][y] == 'O'){
                    q.push({x, y}); // Add the adjacent cell to the queue
                    board[x][y] = 'B'; // Mark the adjacent cell as visited
                }
            }
        }

        for(auto &r : board){
            for(auto &c : r){
                if(c == 'O')
                    c = 'X'; // Replace the unvisited 'O' with 'X'
                else if(c == 'B')
                    c = 'O'; // Replace the visited 'B' with 'O'
            }
        }
    }
}; 