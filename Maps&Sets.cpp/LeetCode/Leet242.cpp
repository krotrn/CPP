#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
            return false;
        unordered_map<char, int> m1;
        unordered_map<char, int> m2;
        int n=s.size();
        for (int i = 0; i < n; i++){
            if(m1.find(s[i])==m1.end())
                m1[s[i]] = 1;
            else
                m1[s[i]]++;
            if(m2.find(t[i])==m2.end())
                m2[t[i]] = 1;
            else
                m2[t[i]]++;
        }
        for (int i = 0; i < n; i++){
            if(m1[s[i]] != m2[t[i]])
                return false;
        }
        return true;
    }
};
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return true;
        unordered_map<char, int> m;
        int n = s.size();
        for (int i = 0; i < n; i++){
            m[s[i]]++;
            m[t[i]]--;
            if(m[s[i]] == 0)
                m.erase(s[i]);
            if(m[t[i]] == 0)
                m.erase(t[i]);
        }
        return m.empty();
    }
};