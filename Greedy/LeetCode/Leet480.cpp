#include<bits/stdc++.h>
using namespace std;

// unsolved

class Solution {
    void balanceHeaps(priority_queue<int> &left, priority_queue<int, vector<int>, greater<int>> &right, int &leftSize, int &rightSize){
        while (leftSize > rightSize + 1) {
            right.push(left.top());
            left.pop();
            leftSize--;
            rightSize++;
        }
        while (rightSize > leftSize) {
            left.push(right.top());
            right.pop();
            rightSize--;
            leftSize++;
        }
    }

    int getMedian(priority_queue<int> &left, priority_queue<int, vector<int>, greater<int>> &right, int &leftSize, int &rightSize){
        if (leftSize > rightSize)
                return left.top();
            else
                return ((double)left.top() + (double)right.top()) / 2.0;
    }

public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> result;
        priority_queue<int> left; 
        priority_queue<int, vector<int>, greater<int>> right; 
        unordered_map<int, int> delay; 
        int leftSize = 0, rightSize = 0;

        for (int i = 0; i < nums.size(); i++) {
            // Add new number
            if (left.empty() || nums[i] <= left.top()) {
                left.push(nums[i]);
                leftSize++;
            } else {
                right.push(nums[i]);
                rightSize++;
            }

            // Balance heaps
            balanceHeaps(left,right,leftSize,rightSize);

            // Remove the number outside the sliding window
            if (i >= k) {
                int toRemove = nums[i - k];
                delay[toRemove]++;

                // Adjust heap sizes for delayed removal
                if (!left.empty() && toRemove <= left.top())
                    leftSize--;
                else
                    rightSize--;

                // Clean up delayed elements in left heap
                while (!left.empty() && delay[left.top()]) {
                    delay[left.top()]--;
                    if (delay[left.top()] == 0)
                        delay.erase(left.top());
                    left.pop();
                }

                // Clean up delayed elements in right heap
                while (!right.empty() && delay[right.top()]) {
                    delay[right.top()]--;
                    if (delay[right.top()] == 0)
                        delay.erase(right.top());
                    right.pop();
                }

                // Rebalance heaps after cleanup
                balanceHeaps(left, right, leftSize, rightSize);
            }

            // Add median to result if window is full
            if (i >= k - 1) {
                result.push_back(round(getMedian(left, right, leftSize, rightSize) * 100000.0) / 100000.0);
            }
        }
        return result;
    }
};



int main(){
    Solution s;
    vector<int> nums = {1,2};
    int k = 1;
    vector<double> ans = s.medianSlidingWindow(nums, k);
    for(auto x: ans)
        cout << x << " ";
    cout << "\n";
    return 0;
}