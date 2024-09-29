#include <bits/stdc++.h>
using namespace std;


class Solution {
    #define mod 1000000007
    int helper(int n, int k,int target, vector<vector<int>>& dp){
        if(n == 0 && target == 0)
            return 1;
        if(n == 0)
            return 0;
        if (dp[n][target] != -1)
            return dp[n][target];
        int sum = 0;
        for (int j = 1; j <= k; j++){
            if(target-j < 0)
                break;
            sum = (sum + (helper(n - 1, k, target - j, dp) % mod)) % mod;
        }
        return dp[n][target] = sum;
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        return helper(n, k, target, dp);
    }
};
class Solution {
    #define mod 1000000007
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= target; j++) {
                for (int face = 1; face <= k; face++) {
                    if (j - face >= 0) {
                        dp[i][j] = (dp[i][j] + dp[i - 1][j - face]) % mod;
                    }
                }
            }
        }

        return dp[n][target];
    }
};

int main(){
    Solution s;
    cout << s.numRollsToTarget(30, 30, 500);
}