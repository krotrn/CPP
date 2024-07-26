#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        int n = strs.size();
        for (int i = 0; i < n; i++){
            string lexo = strs[i];
            sort(lexo.begin(), lexo.end());
            if(m.find(lexo) == m.end()){
                m[lexo] = {};
                m[lexo].push_back(strs[i]);
            }
            else{
                m[lexo].push_back(strs[i]);
            }
        }
        vector<vector<string>> ans;
        for(auto e : m) {
            ans.push_back(e.second);
        }
    }
};