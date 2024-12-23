#include <bits/stdc++.h>

using namespace std;

class Solution {
    void helper(vector<int>& c, int target, int idx, vector<int>& v, vector<vector<int>>& ans){
        if(target < 0 || idx >= c.size())
            return;
        if(!target){
            ans.push_back(v);
            return;
        }
        v.push_back(c[idx]);
        helper(c, target - c[idx], idx, v, ans);
        v.pop_back();
        while(idx + 1 < c.size() && c[idx + 1] == c[idx])
            idx++;
        helper(c, target, idx + 1, v, ans);
        return;
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> v;
        helper(candidates, target, 0, v, ans);
        return ans;
    }
};

int main() {
    cout << "" << endl;
    return 0;
}