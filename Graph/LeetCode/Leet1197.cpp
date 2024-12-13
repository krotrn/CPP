#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minKnightMoves(int x, int y) {
        queue<pair<int, int>> q; // Queue to perform BFS
        set<pair<int, int>> visited; // Set to keep track of visited cells
        
        // Normalize the target cell to the first quadrant
        x = abs(x);
        y = abs(y);

        // Directions for moving the knight
        vector<pair<int, int>> dir = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

        // Add the starting cell to the queue
        q.push({0, 0});
        visited.insert({0, 0});

        int moves = 0; // Number of moves taken to reach the target cell

        // Perform BFS to reach the target cell
        while(!q.empty()){
            int n = q.size();
            for (int i = 0; i < n; i++){
                auto p = q.front(); // Get the front element of the queue
                q.pop(); // Remove the front element from the queue

                // Check if the target cell is reached
                if (p.first == x && p.second == y)
                    return moves;

                // Move the knight to the adjacent cells
                for(auto d: dir){
                    int nx = p.first + d.first;
                    int ny = p.second + d.second;

                    // Check if the adjacent cell is within bounds and not visited
                    if (!visited.count({nx, ny}) && nx >= -1 && ny >= -1){
                        q.push({nx, ny}); // Add the adjacent cell to the queue
                        visited.insert({nx, ny}); // Mark the adjacent cell as  visited
                    }
                }
            }
            moves++; // Increment the number of moves after each level of BFS
        }

        return -1; // Return -1 if the target cell cannot be reached
    }
};