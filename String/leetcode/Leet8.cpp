#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        while (i < s.size() && s[i] == ' ') {
            i++;
        }
        int op = 1;
        if (i < s.size() && (s[i] == '-' || s[i] == '+')) {
            op = (s[i] == '-') ? -1 : 1;
            i++;
        }
        int ans = 0;
        while(s[i] - '0' <= 9 && s[i] - '0' >= 0 ){
            ans = ans * 10 + (s[i] - '0');
            if (ans * op >= INT_MAX) return INT_MAX;
            if (ans * op <= INT_MIN) return INT_MIN;
            
            i++;
        }
        return op * ans;
    }
};