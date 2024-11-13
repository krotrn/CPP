// https://www.spoj.com/problems/MPILOT/
#include <bits/stdc++.h>

using namespace std;

class Solution{
    int helper(vector<vector<int>> &salary, int st, int amc, vector<vector<int>> &dp){
        if(st == salary.size())
            return 0;
        if(dp[st][amc] != -1)
            return dp[st][amc];

        if(amc == 0)
            return dp[st][amc] = salary[st][1] + helper(salary, st + 1, amc + 1, dp);
        if(amc == salary.size() - st)
            return dp[st][amc] = salary[st][0] + helper(salary, st + 1, amc - 1, dp);
        return dp[st][amc] = min(salary[st][0] + helper(salary, st + 1, amc - 1, dp), salary[st][1] + helper(salary, st + 1, amc + 1, dp));
    }
public:
    int minSalaries(vector<vector<int>> &salary){
        vector<vector<int>> dp(salary.size(), vector<int>(salary.size(), -1));
        return salary[0][1] + helper(salary, 1, 1, dp);
    }
};

int main(){
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(2));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 2; j++)
            cin >> v[i][j];
    
    Solution s;
    cout << s.minSalaries(v);
    return 0;
}
