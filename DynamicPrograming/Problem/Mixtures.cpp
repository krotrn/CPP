#include <bits/stdc++.h>
using namespace std;
// https://www.spoj.com/problems/MIXTURES/

class Solution {
    int sum(int s, int e, vector<int> &mixture){
        int res = 0;
        for (int i = s; i <= e; i++){
            res += mixture[i];
            res %= 100;
        }
        return res;
    }
    int helper(int s, int e, vector<int> &mixture, vector<vector<int>> &dp){
        if (s == e)
            return 0;
        if (dp[s][e] != -1)
            return dp[s][e];
        int smoke = INT_MAX;
        for (int i = s; i < e; i++)
            smoke = min(smoke, helper(s, i, mixture, dp) + helper(i + 1, e, mixture, dp) + sum(s, i, mixture) * sum(i + 1, e, mixture));

        return dp[s][e] = smoke;
    }

public:
    // Recursive
    int minSmokes(vector<int> &mixture){
        int n = mixture.size();
        vector<vector<int>> dp(101, vector<int>(101, -1));
        return helper(0, n - 1, mixture, dp);
    }


    // Iterative
    int minSmokesBotUp(vector<int> &mixture){
        int n = mixture.size();
        vector<vector<int>> dp(101, vector<int>(101, 0));
        for (int len = 2; len <= n; len++){
            for (int s = 0; s <= n - len; s++){
                int e = s + len - 1;
                int smoke = INT_MAX;
                for (int k = s; k < e; k++)
                    smoke = min(smoke, dp[s][k] + dp[k + 1][e] + sum(s, k, mixture) * sum(k + 1, e, mixture));

                dp[s][e] = smoke;
            }
        }
        return dp[0][n - 1];
    }
};

int main() {
    int n;
    Solution s;
    while (cin >> n){
        vector<int> mixture(n);
        for (int i = 0; i < n; i++)
            cin >> mixture[i];
        cout << s.minSmokesBotUp(mixture) << endl;
        mixture.clear();
    }
    return 0;
}