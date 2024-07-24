#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        int n = nums.size();
        for (int i = 0; i < n; i++){
            if(m.find(target - nums[i]) == m.end()) m[nums[i]] = i;
            else{
                vector<int> v(2);
                v[0] = m[target - nums[i]];
                v[1] = i;
                return v;
            }
        }
        return {};
    }
};