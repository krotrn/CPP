// https://www.spoj.com/problems/GNYR09F/
#include <bits/stdc++.h>
using namespace std;


class Solution{
    int helper(int n, int k, int last, vector<vector<vector<int>>> &dp){
        if(k<0)
            return 0;
        // Base case: if length is 0, no valid string can be formed
        if(n == 0)
            return 0;
        // Base case: if length is 1, only valid string is "0" or "1" if k is 0
        if(n == 1){
            if(k == 0)
                return 1;
            else
                return 0;
        }
        // Check if the result is already computed and stored in dp
        if(dp[n][k][last] != -1)
            return dp[n][k][last];
        // If the last bit is 1, we can either add "0" or "1" with one less adjacent 1
        if(last)
            return dp[n][k][last] = helper(n - 1, k, 0, dp) + helper(n - 1, k - 1, 1, dp);
        // If the last bit is 0, we can add either "0" or "1" without changing the count of adjacent 1s
        else
            return dp[n][k][last] = helper(n - 1, k, 0, dp) + helper(n - 1, k, 1, dp);
    }
public:
    int noOfAdjBC(int n, int k){
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(2, -1)));
        // Calculate the result by considering both starting with "0" and "1"
        return helper(n, k, 0, dp) + helper(n, k, 1, dp);
    }
};


int main(){
    int P;
    cin >> P;
    Solution s;
    while(P--) {
        int dataset_number, n, k;
        cin >> dataset_number >> n >> k;
        int result = s.noOfAdjBC(n, k);
        cout << dataset_number << " " << result << endl;
    }
}