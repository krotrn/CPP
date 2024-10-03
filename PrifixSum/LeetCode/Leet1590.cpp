#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int sum = 0;
        
        // calculating the sum of the array modulo p
        for (int ele : nums) 
            sum = (sum + ele) % p;
        
        // if the sum of the array modulo p is 0 then the whole array is divisible by p
        if (sum == 0)
            return 0;

        // required sum to delete form the array to make the sum of the array divisible by p
        int toFind = sum;
        
        // map to store the prefix sum modulo p and its index
        unordered_map<int, int> mp; // {sum, index}
        mp[0] = -1;
        int currSum = 0, n = nums.size();
        
        for (int i = 0; i < nums.size(); i++) {
            // calculating the prefix sum modulo p till index i
            currSum = (currSum + nums[i]) % p;

            // calculating the required sum to find in prefix when added after deleting the subarray till index i sum will divisible by p
            int reqSumToAdd = (currSum - toFind + p) % p;
            
            // if the required sum is found in the map then update the minimum length of the subarray
            if (mp.find(reqSumToAdd) != mp.end()) 
                n = min(n, i - mp[reqSumToAdd]);

            // storing the prefix sum modulo p and its index
            mp[currSum] = i;
        }
        
        // if the minimum length of the subarray is equal to the size of the array then return -1
        return (n == nums.size()) ? -1 : n;
    }
};

auto speedup = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

int main(){
    Solution sol;
    vector<int> nums = {3,1,4,2};
    int p = 6;
    cout << sol.minSubarray(nums, p) << endl;
    return 0;
}