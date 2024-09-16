#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int helper(int n, vector<int>& dp){
        if(n == 1)
            return 0;
        if(dp[n] != -1)
            return dp[n];
        int div3 = INT_MAX;
        int div2 = INT_MAX;
        int dec = n - 1;
        if(n%3 == 0)
            div3 = n / 3;
        if(n%2 == 0)
            div2 = n / 2;

        return dp[n] = 1 + min({helper(div3, dp), helper(div2, dp), helper(dec,dp)});
    }

    int minStep(int n){
        vector<int> dp(n+1,-1);
        return helper(n, dp);
    }
};

int main(){
    Solution s;
    cout << s.minStep(9999) << endl;
}