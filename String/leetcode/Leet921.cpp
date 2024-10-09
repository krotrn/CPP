#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int ocnt = 0;
        int adcnt = 0;
        int n = s.length();

        for (int i = 0; i < n; i++){
            if(s[i] == '(')
                ocnt++;
            else{
                ocnt--;
                if(ocnt < 0){
                    adcnt++;
                    ocnt = 0;
                }
            }
        }
        return adcnt + ocnt;
    }
};

auto speedp = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
};