#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        queue<int> q;
        vector<bool> visited(n, false);
        q.push(0);
        visited[0] = true;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(auto key: rooms[curr]){
                if(!visited[key]){
                    q.push(key);
                    visited[key] = true;
                }
            }
        }
        for(auto ele : visited){
            if(!ele)
                return ele;
        }
        return true;
    }
};