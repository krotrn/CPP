// https://codeforces.com/problemset/problem/540/D
#include <bits/stdc++.h>

using namespace std;

class Solution{
    double rServival(int r, int s, int p, vector<vector<vector<double>>> &dp){
        if (r == 0 || s == 0)
            return 0;
        if(p == 0)
            return 1;
        if(dp[r][s][p] > - 0.9)
            return dp[r][s][p];
        dp[r][s][p] = 0;
        double totalFight = r * s + s * p + p * r;
        // fight between r and p
        dp[r][s][p] += rServival(r - 1, s, p, dp) * (r * p / totalFight);
        // fight between r and s  
        dp[r][s][p] += rServival(r, s - 1, p, dp) * (r * s / totalFight);
        // fight between s and p
        dp[r][s][p] += rServival(r, s, p - 1, dp) * (s * p / totalFight);
        return  dp[r][s][p];
    }
public: 
    vector<double> servivingProbability(int r, int s, int p){
        int n = max({r, s, p});
        vector<vector<vector<double>>> dp(n + 1, vector<vector<double>>(n + 1, vector<double>(n + 1, -1.0)));
        return {rServival(r, s, p, dp), rServival(s, p, r, dp), rServival(p, r, s, dp)};
    }
};

int main(){
    int r, s, p;
    cin >> r >> s >> p;
    Solution sol;
    vector<double> ans = sol.servivingProbability(r, s, p);
    cout << fixed << setprecision(9) << ans[0] << " " << ans[1] << " " << ans[2] << endl;
}