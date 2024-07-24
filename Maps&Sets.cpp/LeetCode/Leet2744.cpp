#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int n=words.size();
        unordered_set<string> s(words.begin(),words.end());
        string rev;
        int count = 0;
        for (int i = 0; i < n; i++){
            rev = words[i];
            reverse(rev.begin(), rev.end());
            if(rev == words[i]) continue;
            if(s.find(rev) != s.end()){
                s.erase(rev);
                s.erase(words[i]);
                count++;
            }
        }
        return count;
    }
};
class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int n=words.size();
        unordered_set<string> s;
        int count = 0;
        string rev;
        for (int i = 0; i < n; i++){
            if(s.find(words[i]) != s.end()){
                s.erase(words[i]);
                count++;
                continue;
            }
            else{
                reverse(words[i].begin(), words[i].end());
                s.insert(words[i]);
            }
        }
        return count;
    }
};