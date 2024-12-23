#include <bits/stdc++.h>

using namespace std;

class Solution {
    void helper(vector<int>& c, int target, int idx, vector<int>& v,
                vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(v);
            return;
        }
        if(idx >= c.size() || target < 0)
            return;
        v.push_back(c[idx]);
        helper(c, target - c[idx], idx + 1, v, ans);
        v.pop_back();

        while(idx + 1 < c.size() && c[idx + 1] == c[idx])
            idx++;
        helper(c, target, idx + 1, v, ans);
        return;
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> v;
        helper(candidates, target, 0, v, ans);
        return ans;
    }
};

class Solution {
    void helper(vector<int>& c, int target, int idx, vector<int>& v,
                vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(v);
            return;
        }
        for (int i = idx; i < c.size(); i++) {
            if (target - c[i] < 0)
                break;
            if (i > idx && c[i] == c[i - 1])
                continue;
            v.push_back(c[i]);
            helper(c, target - c[i], i + 1, v, ans);
            v.pop_back();
        }
        return;
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
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