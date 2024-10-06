#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if (n > m) return false;
        // frequency array for s1 and s2
        vector<int> str1(26), str2(26);
        for (int i = 0; i < n; i++) {
            str1[s1[i] - 'a']++;
            str2[s2[i] - 'a']++;
        }
        // check if s1 is a substring of s2
        if (str1 == str2) return true;
        for (int i = n; i < m; i++) {
        }
        return false;
    }
};

auto speedup = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();