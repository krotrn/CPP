#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int> su(n);
        su[n - 1] = nums[n-1];
        for (int i = n - 1; i > -1; i++)
            su[i] = max(nums[i], su[i + 1]);

        int ans = 0;
        int i = 0, j = 0;
        while(j<n){
            if(nums[i]<= su[j]){
                ans = max(ans, j - i);
                j++;
            }
            else
                i++;
        }
        return ans;
    }
};