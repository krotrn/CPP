#include<bits/stdc++.h>
using namespace std;
// https://cses.fi/problemset/task/1637

class Solution {
    vector<int> get_digits(int n){
        vector<int> v;
        while (n > 0){
            if (n % 10)
                v.push_back(n % 10);
            n /= 10;
        }
        return v;
    }
public:
    int minStepsToReachZero(int n, vector<int> &dp){
        if(n == 0)
            return 0;
        if(n<=9)
            return 1;
        if(dp[n] != -1)
            return dp[n];
        vector<int> v = get_digits(n);
        int result = INT_MAX;
        int p = v.size();
        for (int i = 0; i < p; i++)
        {
            result = min(result, minStepsToReachZero(n - v[i], dp));
        }
        return dp[n] = result + 1;
    }
    int minStepsToReachZero2(int nums, vector<int> &dp){
        dp[0] = 0;
        for (int i = 1; i < 10; i++)
            dp[i] = 1;
        for (int n = 10; n <= nums; n++){
            vector<int> d = get_digits(n);
            int result = INT_MAX;
            for (int i = 0; i < d.size(); i++)
                result = min(result, dp[n - d[i]]);
            dp[n] = result + 1;
        }
        return dp[nums];
    }
};

int main(){
    Solution s;
    int n;
    cin >> n;
    vector<int> dp(n+1, -1);
    cout << s.minStepsToReachZero2(n, dp);
}