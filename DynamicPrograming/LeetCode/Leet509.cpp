#include<bits/stdc++.h>
using namespace std;

// Function to find the n Fibonacci number using Dynamic Programming

/**
 * T.C : O(n)
 * S.C : O(n)
 */

class Solution {
public:
    int fibo(int n, vector<int> &dp) {
        if (n <= 1) {
            return n;
        }
        if(dp[n] != -1) 
            return dp[n];
        dp[n] = fibo(n - 1,dp) + fibo(n - 2,dp);
        return dp[n];
    }
    int fib(int n) {
        vector<int> dp(n + 1, -1);
        return fibo(n, dp);

    }
};

// iterative approach or tabulation approach or bottom up approach of fibonacci series 
/**
 * best approach of all three algorithm
 */

// class Solution {
// public:
//     int fib(int n) {
//         if (n <= 1)
//             return n;
//         vector<int> dp(n + 1);
//         dp[0] = 0;
//         dp[1] = 1;
//         for (int i = 2; i <= n; i++) {
//             dp[i] = dp[i - 1] + dp[i - 2];
//         }
//         return dp[n];
//     }


int main() {
    Solution obj;
    int n = 10;
    cout << obj.fib(n) << endl;
    return 0;
}