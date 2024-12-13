#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int rows = rooms.size();
        if(rows == 0)
            return;
        int col  = rooms[0].size();
        queue<pair<int, int>> q;
        vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        for (int i = 0; i < rows; i++){
            for (int j = 0; j < col; j++){
                if (rooms[i][j] == 0)
                    q.push({i, j});
            }
        }


        while(!q.empty()){
            auto p = q.front();
            q.pop();
            for(auto d: dir){
                int x = p.first + d.first;
                int y = p.second + d.second;
                if (x >= 0 && x < rows && y >= 0 && y < col && rooms[x][y] == INT_MAX){
                    rooms[x][y] = rooms[p.first][p.second] + 1;
                    q.push({x, y});
                }
            }
        }
    }
};