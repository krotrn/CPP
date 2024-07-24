#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> m;
        int n = arr.size();
        for (int i = 0; i < n; i++){
            m[arr[i]]++;
        }
        unordered_set<int> s;
        for(auto e: m){
            if(s.find(e.second) == s.end()) {
                s.insert(e.second);
            }
            else
                return false;
        }
        return true;
    }
};