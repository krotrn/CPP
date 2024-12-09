#include<bits/stdc++.h>
using namespace std;

class Solution {
    void fill(vector<vector<int>>& image, int sr, int sc, int &color, vector<vector<bool>> visited, int prev){
        if(sr < 0 || sc < 0 || sr == image.size() || sc == image[0].size() || visited[sr][sc] || image[sr][sc] != prev)
            return;
        image[sr][sc] = color;
        visited[sr][sc] = true;
        fill(image, sr + 1, sc, color, visited, prev);
        fill(image, sr, sc + 1, color, visited, prev);
        fill(image, sr - 1, sc, color, visited, prev);
        fill(image, sr, sc - 1, color, visited, prev);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<bool>> visited(image.size(), vector<int>(image[0].size(), false));
        fill(image, sr, sc, color, visited, image[sr][sc]);
    }
};