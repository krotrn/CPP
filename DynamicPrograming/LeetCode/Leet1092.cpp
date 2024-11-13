#include <bits/stdc++.h>

using namespace std;

class Solution {
        vector<vector<int>> longestCommonSubsequence(string s1, string s2) {
        vector<vector<int>> dp(s1.size() + 1, vector<int> (s2.size() + 1, 0));
        for(int i = 1; i<=s1.size(); i++){
            for(int j = 1; j<=s2.size(); j++){
                if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
        return dp;
    }
public:
    string shortestCommonSupersequence(string str1, string str2) {
        vector<vector<int>> dp = longestCommonSubsequence(str1, str2);
        int i = str1.size(), j = str2.size();
        string ans = "";
        while(i && j){
            if(str1[i - 1] == str2[j - 1]){
                ans += str1[i - 1];
                i--;
                j--;
            }else if(dp[i-1][j] > dp[i][j-1]) ans += str1[i-- - 1];
            else ans += str2[j-- - 1];
        }
        while(i) ans += str1[i-- - 1];
        while(j) ans += str2[j-- - 1];
        reverse(ans.begin(), ans.end());
        return ans; 
    }
};

int main() {
    cout << "" << endl;
    return 0;
}