#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.size();
        int ocnt = 0;
        int zcnt = 0;
        long long ans = 0;
        for (int i = 0; i < n; i++){
            if(s[i] == '0')
                ans += ocnt;
            else
                ocnt++;
        }
        return ans;
    }
};
ststic const auto speedup = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};