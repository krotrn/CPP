#include<iostream>
#include<vector>
int main(){
    //find pivoted index(pivot = first element doesnot follow accending order from last)
    //sort all element after pivot index
    //swap pivot element and just largest then pivit element
    /*class Solution {
        public:
        void nextPermutation(vector<int>& nums) {
            int idx=-1;
            int n = nums.size();
            for(int i = n-2; i>=0; i--){
            if(nums[i]<nums[i+1]){
                    idx = i;
                    break;
                }
            }
            if(idx==-1){
            reverse(nums.begin(),nums.end());
            return;
            }
            reverse(nums.begin()+idx+1,nums.end());
            for(int i=idx+1;i<n;i++){
                if(nums[idx]<nums[i]){
                    n=i;
                }
            }
            int t=nums[idx];
            nums[idx]=nums[n];
            nums[n]=t;
        return;
        }
    };*/
    //https://leetcode.com/media/original_images/31_Next_Permutation.gif
    //use function

    /*class Solution {
    public:
        void nextPermutation(vector<int>& nums) {
            next_permutation(nums.begin(), nums.end());
        }
    };*/
}