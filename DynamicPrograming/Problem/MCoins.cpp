#include <bits/stdc++.h>
using namespace std;

// https://www.spoj.com/problems/MCOINS/

// class Solution { // wrong

//     string helper(int k, int l, vector<int> &coins, vector<int> &dp){
//         string res = "";
//         for (int i = 0; i < coins.size(); i++){
//             if(win(k,l,coins[i],dp))
//                 res += "A";
//             else
//                 res += "B";
//         }
//         return res;
//     }
//     int win(int k, int l, int n, vector<int> &dp){
//         if(n<=0)
//             return 0;
//         if( n == 1 || n == k || n == l)
//             return 1;
//         if(dp[n] != -1)
//             return dp[n];
//         return dp[n] = !(win(k, l, n - 1, dp) and win(k, l, n - k, dp) and win(k, l, n - l, dp));
//     }

// public:
//     string mCoins(int k, int l, vector<int> &coins){
//         vector<int> dp(*max_element(coins.begin(), coins.end()) + 1, -1);
//         return helper(k, l, coins, dp);
//     }
// };


class Solution {
public:
    string mCoins(int k, int l, vector<int> &coins){
        vector<int> dp(*max_element(coins.begin(), coins.end()) + 1, 0);
        dp[0] = 0;
        for (int i = 1; i <= dp.size(); i++) {
            if (dp[i - 1] == 0) {
                dp[i] = 1;
            } else if (i - k >= 0 && dp[i - k] == 0) {
                dp[i] = 1;
            } else if (i - l >= 0 && dp[i - l] == 0) {
                dp[i] = 1;
            }
        }
        string res = "";
        for (int i = 0; i < coins.size(); i++) {
            if (dp[coins[i]] == 1) {
                res += "A";
            } else {
                res += "B";
            }
        }
        return res;
    }
};

int main() {
    int k, l, n;
    cin >> k >> l >> n;
    vector<int> v(n);
    cout << "Enter the Ele :" << endl;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    Solution S;
    string ans = S.mCoins(k, l, v);
    cout << ans << endl;
    return 0;
}