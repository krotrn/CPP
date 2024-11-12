#include <bits/stdc++.h>

using namespace std;
// https://atcoder.jp/contests/dp/tasks/dp_i

class Solution{
    // probability of getting atleast x heads in [0,n] coins
    double helper(int n, int x, vector<double> &P, vector<vector<double>> &dp){
        if(x == 0)
            return 1;
        if (n == -1)
            return 0;
        if (round(dp[n][x]) > -0.9)
            return dp[n][x];
        return dp[n][x] = helper(n - 1, x, P, dp) * (1 - P[n]) + helper(n - 1, x - 1, P, dp) * (P[n]);
    }
public:
    double moreHeads(int n, vector<double> &P){
        vector<vector<double>> dp(n+1, vector<double>(n+1, -1.0));
        return helper(n - 1, (n + 1) / 2, P, dp);
    }
};

int main(){
    int n;
    cin >> n;
    vector<double> P(n);
    for (int i = 0; i < n; i++){
        cin >> P[i];
    }
    Solution obj;
    cout << fixed << setprecision(9) << obj.moreHeads(n, P) << endl;
    return 0;
}