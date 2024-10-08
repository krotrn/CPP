#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        for(int i = 0; i < st.size(); i++){
            if(st.empty())
                st.push(s[i]);
            else{
                if((st.top() == 'A' && s[i] == 'B') || (st.top() == 'C' && s[i] == 'D'))
                    st.pop();
                else
                    st.push(s[i]);
            }
        }
        return st.size();
    }
};
auto speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();