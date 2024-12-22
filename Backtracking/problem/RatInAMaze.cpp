#include <bits/stdc++.h>

using namespace std;

class Solution{
    int helper(int row, int col, vector<vector<int>> &maze){
        if(row<0 || row >= maze.size() || col < 0 || col >= maze[0].size() || maze[row][col] == 1)
            return 0;
        if(row == maze.size() - 1 && col == maze[0].size() - 1)
            return 1;
        maze[row][col] = 1;
        vector<pair<int,int>> direction = {}
        { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
        int ans = 0;
        for(auto d : direction)
            ans += helper(row + d.first, col + d.second, maze);
        
        maze[row][col] = 0;
        return ans;
    }
public:
    int ratInMaze(vector<vector<int>> &maze){
        if (maze.size() == 0 || maze[0][0] == 1 || maze[maze.size() - 1][maze.size() - 1] == 1)
            return 0; 
        return helper(0, 0, maze);
    }
}

int main() {
    cout << "" << endl;
    return 0;
}