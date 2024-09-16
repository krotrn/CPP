#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if (obstacleGrid[0][0] == 1) return 0;

        obstacleGrid[0][0] = 1;

        for (int i = 1; i < m; i++) {
            obstacleGrid[i][0] = (obstacleGrid[i][0] == 1 || obstacleGrid[i-1][0] == 0) ? 0 : 1;
        }

        for (int j = 1; j < n; j++) {
            obstacleGrid[0][j] = (obstacleGrid[0][j] == 1 || obstacleGrid[0][j-1] == 0) ? 0 : 1;
        }

        for (int i = 1; i < m; i++){
            for (int j = 1; j < n; j++){
                if(obstacleGrid[i][j] == 1)
                    obstacleGrid[i][j] = 0;
                else {
                    obstacleGrid[i][j] = obstacleGrid[i - 1][j]  + obstacleGrid[i][j - 1];
                }
            }
        }
        return obstacleGrid[m - 1][n - 1];
    }
};