#include <bits/stdc++.h>
using namespace std;

class Solution{
    int helper(int s, int e, vector<int> &matrix, vector<vector<int>> &dp){
        if(s == e || s + 1 == e )
            return 0;
        if(dp[s][e] != -1){
            return dp[s][e];
        }
        int mn = INT_MAX;
        for (int i = s + 1; i < e; i++){
            mn = min(mn, helper(s, i, matrix, dp) + helper(i, e, matrix, dp) + matrix[s] * matrix[e] * matrix[i]);
        }
        return dp[s][e] = mn;
    } 
public :
    int matrixChainMultiplication(vector<int> &matrix){
        int n = matrix.size();
        if(n < 3)
            return matrix[0] * matrix[1];
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
        return helper(0, n - 1, matrix, dp);
    }

    int matrixChainMultiplication2(vector<int>& matrix) {
        int n = matrix.size(); // Size of the dimension array
        if (n < 3) return 0;   // At least two matrices are needed
        
        // Create a DP table initialized to 0
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Fill the table using bottom-up dynamic programming
        for (int length = 2; length < n; ++length) { // length is the chain length
            for (int i = 1; i < n - length + 1; ++i) {
                int j = i + length - 1;
                dp[i][j] = INT_MAX;
                for (int k = i; k < j; ++k) {
                    // Calculate the cost of multiplying the matrices from i to j
                    int cost = dp[i][k] + dp[k+1][j] + matrix[i-1] * matrix[k] * matrix[j];
                    // Update the minimum cost in dp table
                    dp[i][j] = min(dp[i][j], cost);
                }
            }
        }
        // Return the minimum cost of multiplying matrices from 1 to n-1 
        return dp[1][n-1];
    }
};

int main() {

    vector<int> matrix = {1,2,3,4,3};
    Solution s;
    cout << s.matrixChainMultiplication(matrix) << endl;
}