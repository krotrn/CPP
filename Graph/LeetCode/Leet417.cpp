#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<vector<int>> dir = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    int rows, cols;
    vector<vector<int>> h;

    vector<vector<bool>> bfs(queue<pair<int, int>>& q){
        vector<vector<bool>> visited(rows, vector<bool> (cols, false));
        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();
            visited[r][c] = true;
            for(auto d : dir){
                int new_r = r + d[0];
                int new_c = c + d[1];
                if(new_r >= 0 && new_r < rows && new_c >= 0 && new_c < cols && h[new_r][new_c] >= h[r][c] && !visited[new_r][new_c]){
                    q.push({new_r, new_c});
                }
            }
        }
        return visited;
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows = heights.size();
        cols = heights[0].size();
        h = heights;
        queue<pair<int, int>> pecific, atlantic;
        for(int i = 0; i < rows; i++){
            pecific.push({i, 0});
            atlantic.push({i, cols - 1});
        }
        for(int i = 0; i < cols; i++){
            pecific.push({0, i});
            atlantic.push({rows - 1, i});
        }

        vector<vector<bool>> pacific_visited = bfs(pecific);
        vector<vector<bool>> atlantic_visited = bfs(atlantic);

        vector<vector<int>> ans;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(pacific_visited[i][j] && atlantic_visited[i][j]){
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};