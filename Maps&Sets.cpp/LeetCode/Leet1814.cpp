#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int rev(int n){
        int ans = 0;
        while(n){
            ans = ans * 10 + n % 10;
            n /= 10;
        }
        return ans;
    }
    int countNicePairs(vector<int>& nums) {
        unordered_map<int, int> m;
        int count = 0;
        for(int i = 0; i < nums.size(); i++){ 
            nums[i] = nums[i] - rev(nums[i]);
            // if number is already in map, then we can add the number of times it has already occured 
            if(m.find(nums[i]) != m.end()){
                count += m[nums[i]];
            }
            m[nums[i]]++;
        }
        return count;
    }
};