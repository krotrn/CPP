#include<bits/stdc++.h>
using namespace std;

class Solution { // Iterative
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        // If the starting cell has an obstacle, then simply return as there would be no paths to the destination.
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1]) return 0;
        // Number of ways of reaching the starting cell = 1.
        obstacleGrid[0][0] = 1;

        // if the first cell is not blocked, then the number of ways of reaching the first cell is 1, else 0. and if previous cell is blocked then the current cell will also be blocked.
        for (int i = 1; i < m; i++) 
            obstacleGrid[i][0] = (obstacleGrid[i][0] == 1 || obstacleGrid[i-1][0] == 0) ? 0 : 1;
        
        for (int j = 1; j < n; j++)  
            obstacleGrid[0][j] = (obstacleGrid[0][j] == 1 || obstacleGrid[0][j-1] == 0) ? 0 : 1;
        
        // for rows and columns greater than 1, if the cell is blocked then the number of ways of reaching that cell is 0, else it is the sum of the number of ways of reaching the cell above it and the number of ways of reaching the cell to the left of it.
        for (int i = 1; i < m; i++){
            for (int j = 1; j < n; j++){
                // if the cell is blocked, then the number of ways of reaching that cell is 0.
                if(obstacleGrid[i][j] == 1)
                    obstacleGrid[i][j] = 0;
                // else it is the sum of the number of ways of reaching the cell above it and the number of ways of reaching the cell to the left of it.
                else {
                    obstacleGrid[i][j] = obstacleGrid[i - 1][j]  + obstacleGrid[i][j - 1];
                }
            }
        }
        // return the number of ways of reaching the last cell.
        return obstacleGrid[m - 1][n - 1];
    }
};
class Solution { // Recursive
    int helper(int str, int stc, int m, int n, vector<vector<int>> &obstacleGrid, vector<vector<int>> &dp){
        // If current cell has obsticle and starting row or column is out of bound then return 0
        if ( str == m || stc == n || obstacleGrid[str][stc] == 1)
            return 0;
        // If Path is successfully defined then return 1
        if(str == m-1 and stc == n-1)
            return 1;
        if(dp[str][stc] == -1)
            return dp[str][stc];
        // add path comes from left and down side of cell
        return dp[str][stc] = helper(str + 1, stc, m, n, obstacleGrid, dp) + helper(str, stc, m, n, obstacleGrid, dp);
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        return helper(0, 0, m, n, obstacleGrid, dp);
    }
};


int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> obstacleGrid(m, vector<int>(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> obstacleGrid[i][j];
    Solution s;
    cout << s.uniquePathsWithObstacles(obstacleGrid) << endl;
    return 0;
}