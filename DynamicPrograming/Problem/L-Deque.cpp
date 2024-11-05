// https://atcoder.jp/contests/dp/tasks/dp_l
#include <bits/stdc++.h>

using namespace std;

class Solution {
    // Helper function to calculate the maximum score difference
    long long helper(int st, int en, vector<vector<long long>> &dp, vector<int> &sequence) {
        // Base case: if the start and end indices are the same, return the value at that index
        if (st == en)
            return sequence[st];
        
        // If the value is already computed, return it
        if (dp[st][en] != -1) 
            return dp[st][en];
        
        // Recursively calculate the maximum score difference
        return dp[st][en] = max(sequence[st] - helper(st + 1, en, dp, sequence), sequence[en] - helper(st, en - 1, dp, sequence));
    }
public:
    // Function to calculate the resulting value
    long long resultingValue(vector<int> &sequence) {
        int n = sequence.size();
        // Initialize the dp table with -1
        vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, -1));
        // Call the helper function with the full range of the sequence
        return helper(0, n - 1, dp, sequence);
    }
};


class Solution1{
public:
    long long resultingValue(vector<int> &sequence){
        int n = sequence.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(n + 1));
        for (int i = 0; i < n; i++)
            dp[i][i] = sequence[i];
        for (int len = 2; len <= n; len++){
            for (int i = 0; i <= n - len; i++){
                int j = i + len - 1;
                dp[i][j] = max(sequence[i] - dp[i + 1][j], sequence[j] - dp[i][j - 1]);
            }
        }
        return dp[0][n - 1];
    }
};


int main() {
    Solution1 s;
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout << s.resultingValue(v) << endl;
    return 0;
}