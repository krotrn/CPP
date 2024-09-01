#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        if (intervals.empty()) return ans;
    
        sort(intervals.begin(), intervals.end());
        vector<int> temp = intervals[0];
    
        for (int i = 1; i < intervals.size(); i++) {
            if (temp[1] >= intervals[i][0]) {
                temp[1] = max(temp[1], intervals[i][1]);
            } else {
                ans.push_back(temp);
                temp = intervals[i];
            }
        }
        ans.push_back(temp);
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        if (intervals.empty()) return ans;
    
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });

        int n = intervals.size();
        ans.push_back(intervals[0]);

        for(int i = 1; i < n; i++) {
            if (ans.back()[1] >= intervals[i][0]) {
                ans.back()[0] = min(ans.back()[0], intervals[i][0]);
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            } else {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};


// Methord 2
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        if (intervals.empty()) return ans;
    
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });

        int n = intervals.size();
        ans.push_back(intervals[n-1]);

        for(int i = n-2; i >= 0; i--) {
            if (ans.back()[0] <= intervals[i][1]) {
                ans.back()[0] = min(ans.back()[0], intervals[i][0]);
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            } else {
                ans.push_back(intervals[i]);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};