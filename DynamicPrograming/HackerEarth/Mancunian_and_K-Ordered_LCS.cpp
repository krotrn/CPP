// https://www.hackerearth.com/problem/algorithm/mancunian-and-k-ordered-lcs-e6a4b8c6/
#include <bits/stdc++.h>

using namespace std;

class Solution{
    int helper(vector<int> &s1, vector<int> &s2, int x, int y, int k, vector<vector<vector<int>>> &dp){
        if(x == 0 || y == 0){
            return 0;
        }
        if(dp[x][y][k] != -1){
            return dp[x][y][k];
        }
        // if found same element
        if(s1[x-1] == s2[y-1])
            return dp[x][y][k] = 1 + helper(s1, s2, x - 1, y - 1, k, dp);
        // if have any chance of flipping
        if (k)
            dp[x][y][k] = max(dp[x][y][k], 1 + helper(s1, s2, x - 1, y - 1, k - 1, dp));
        // if filliping chace is over
        dp[x][y][k] = max(dp[x][y][k], helper(s1, s2, x - 1, y, k, dp));
        dp[x][y][k] = max(dp[x][y][k], helper(s1, s2, x, y - 1, k, dp));
        return dp[x][y][k];
    }
public:
    int LCSWithK(vector<int> s1, vector<int> s2, int k){
        int x = s1.size();
        int y = s2.size();
        vector<vector<vector<int>>> dp(x+1, vector<vector<int>>(y+1, vector<int>(k+1, -1)));
        return helper(s1, s2, x, y, k, dp);
    }
};


int main() {
    int N, M, k;
    cin >> N >> M >> k;
    vector<int> s1(N), s2(M);
    for (int i = 0; i < N; ++i) cin >> s1[i];
    for (int i = 0; i < M; ++i) cin >> s2[i];
    Solution s;
    cout << s.LCSWithK(s1, s2, k);
    return 0;
}