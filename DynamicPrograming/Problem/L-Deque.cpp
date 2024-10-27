// https://atcoder.jp/contests/dp/tasks/dp_l
#include <bits/stdc++.h>

using namespace std;

class Solution{
    long long helper(int st, int en, vector<vector<long long>> &dp, vector<int> &sequence){
        if(st == en)
            return sequence[st];
        if(dp[st][en] != -1){
            return dp[st][en];
        }
        return dp[st][en] = max(sequence[st] - helper(st + 1, en, dp, sequence), sequence[en] - helper(st, en - 1, dp, sequence));
    }
public:
    long long resultingValue(vector<int> &sequence){
        int n = sequence.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, -1));
        return helper(0, n - 1, dp, sequence);
    }
};


int main() {
    Solution s;
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout << s.resultingValue(v) << endl;
    return 0;
}