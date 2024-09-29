#include <bits/stdc++.h>
using namespace std;

// https://cses.fi/problemset/task/1633

#define mod (1000000007)

class Solution {
public:
    int dieCombination(int n, vector<int> &dp){
        if(n < 0)
            return 0;
        if(n < 2)
            return 1;
        if(dp[n] != -1)
            return dp[n];
        int ans = 0;
        for (int i = 1; i < 7; i++){
            if (n-i<0)
                break;
            ans = (ans + dieCombination(n - i, dp) % mod) % mod;
        }
        return dp[n] = ans;
    }
    int dieCombination2(int n, vector<int> &dp){
        dp[0] = 1;
        for (int i = 1; i <= n; i++){
            dp[i] = 0;
            for (int j = 1; j < 7; j++){
                if(i-j < 0)
                    break;
                dp[i] = (dp[i] + dp[i - j] % mod) % mod;
            }
        }
        return dp[n];
    }
};

int main() {
    Solution s;
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    cout << s.dieCombination2(n, dp);
    return 0;
}