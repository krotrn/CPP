#include<iostream>
#include<vector>
//https://leetcode.com/media/original_images/31_Next_Permutation.gif
class Solution {
    //sort all element after pivot index
    //swap pivot element and just largest then pivit element
    //find pivoted index(pivot = first element doesnot follow accending order from last)
    public:
    void nextPermutation(vector<int>& nums) {
        int idx=-1;
        int n = nums.size();
        for (int i = n - 2; i >= 0; i--){
            if (nums[i] < nums[i + 1]){
                idx = i;
                break;
            }
        }
        reverse(nums.begin()+idx+1,nums.end());i
        if(idx==-1) return;
        for(int i=idx+1;i<n;i++){
            if(nums[i] > nums[idx]){
                swap(nums[idx], nums[i]);
                return;
            }
        }
        return;
    }
};
    //use function
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    }
};
int main(){

}