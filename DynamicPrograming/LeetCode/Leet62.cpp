#include<bits/stdc++.h>
using namespace std;

// class Solution {
// /**
//  * RuntimeError for (16,16);
//  */
// public:
//     long long fac(int n,int end,vector<long long> &dp) {
//     // base case
//         if(n==end)
//             return 1;
//         if(dp[n] != -1){
//             return dp[n];
//         }
//         return dp[n] = (long long)(n * fac(n - 1,end, dp));
//     }

//     int uniquePaths(int m, int n) {
//         vector<long long> dp(m + n - 1,-1);
//         dp[0] = 1;
//         return (int)(fac(m + n - 2,max(m-1,n-1), dp) / (fac(min(m - 1,n-1),0, dp)));
//     }
// };

// class Solution {
// public:
// /**
//  * Time Limit Exceeded
//  */
//     int uniquePaths(int m, int n){
//         if(m==1 && n==1)
//             return n;
//         if(m == 0 || n == 0)
//             return 0;
//         return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
//     }
// };


// /**
//  * Approach 1: Recursion
//  */
// class Solution { // Accepted
// public:
//     int helper(int m,int n,int str,int stc, vector<vector<int>> &dp){
//         if(str == m && stc == n)
//             return 1;
//         if(m<str || n<stc)
//             return 0;
//         if(dp[m-str][n-stc] != -1)
//             return dp[m - str][n - stc];
//         return dp[m - str][n - stc] = helper(m, n, str + 1, stc, dp) + helper(m, n, str, stc + 1, dp);
//     }
//     int uniquePaths(int m, int n){
//         vector<vector<int>> dp(m, vector<int> (n,-1));
//         return helper(m-1, n-1,0,0, dp);
//     }
// };



/**
 * Approach 2: Tabulation
 */

class Solution { // Accepted
public:
    int uniquePaths(int m, int n){
        vector<vector<int>> dp(m, vector<int> (n,-1));
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if(i == 0 || j == 0) {
                    dp[i][j] = 1;
                    continue;
                }
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main(){
    Solution s;
    cout << s.uniquePaths(3, 7); 
}

