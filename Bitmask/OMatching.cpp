#include <bits/stdc++.h>
using namespace std;

// https://atcoder.jp/contests/dp/submissions/61086836

class Solution {
    const int MOD = 1e9 + 7;

    vector<vector<int>> dp;

    int helper(int men, int mask, vector<vector<int>> &c) {
        if (men == c.size()) 
            return 1;
        if (dp[men][mask] != -1) 
            return dp[men][mask];

        int ans = 0;
        for (int i = 0; i < c.size(); i++) {
            if (c[men][i] && (mask & (1 << i)))  // Availability and compatability
                ans = (ans + helper(men + 1, mask ^ (1 << i), c)) % MOD;
        }
        return dp[men][mask] = ans;
    }

public:
    int Match(vector<vector<int>> &c) {
        int n = c.size();
        dp.assign(n, vector<int>(1 << n, -1));
        return helper(0, (1 << n) - 1, c);
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<int>> compatibility(n , vector<int>(n , 0));
    for (auto &r : compatibility)
        for (int &ele: r)
            cin >> ele;

    Solution s;
    cout << s.Match(compatibility) << endl;
    return 0;
}