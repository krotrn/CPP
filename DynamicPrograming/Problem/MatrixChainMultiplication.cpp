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
};

int main() {

    vector<int> matrix = {1,2,3,4,3};
    Solution s;
    cout << s.matrixChainMultiplication(matrix) << endl;
}