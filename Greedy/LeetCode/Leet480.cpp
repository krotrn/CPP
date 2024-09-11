#include<bits/stdc++.h>
using namespace std;

// unsolved

class Solution {
public:
    // Function to get the median from the two heaps
    double getMedian(priority_queue<int>& lft, priority_queue<int, vector<int>, greater<int>>& rgt, int& sz_lft, int& sz_rgt) {
        if (sz_lft > sz_rgt) {
            return round(lft.top() * 100000.0) / 100000.0;
        } else {
            return round(rgt.top() + ((lft.top() - rgt.top()) / 2.0) * 100000.0) / 100000.0;
        }
    }

    // Function to balance the two heaps
    void balanceHeaps(priority_queue<int>& lft, priority_queue<int, vector<int>, greater<int>>& rgt, int& sz_lft, int& sz_rgt) {
        if (sz_lft > sz_rgt + 1) {
            rgt.push(lft.top());
            lft.pop();
            sz_lft--;
            sz_rgt++;
        } else if (sz_rgt > sz_lft) {
            lft.push(rgt.top());
            rgt.pop();
            sz_rgt--;
            sz_lft++;
        }
    }

    // Function to find the median of each sliding window of size k
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        priority_queue<int> lft; // max-heap (left side)
        priority_queue<int, vector<int>, greater<int>> rgt; // min-heap (right side)
        int sz_lft = 0, sz_rgt = 0;
        
        // Initialize the heaps with the first k elements
        for (int i = 0; i < k; i++) {
            if (lft.empty() || nums[i] <= lft.top()) {
                lft.push(nums[i]);
                sz_lft++;
            } else {
                rgt.push(nums[i]);
                sz_rgt++;
            }
            balanceHeaps(lft, rgt, sz_lft, sz_rgt);
        }
        
        // Add the median of the first window to the result
        double median = getMedian(lft, rgt, sz_lft, sz_rgt);
        stringstream ss;
        ss << fixed << setprecision(5) << median;
        double formatted_median;
        ss >> formatted_median;
        ans.push_back(formatted_median);

        unordered_map<int, int> delay; // Map to keep track of elements to be removed
        
        // Process the rest of the elements
        for (int i = k; i < nums.size(); i++) {
            int newEle = nums[i];
            int oldEleToDel = nums[i - k];

            // Add the new element to the appropriate heap
            if (newEle <= lft.top()) {
                lft.push(newEle);
                sz_lft++;
            } else {
                rgt.push(newEle);
                sz_rgt++;
            }
            balanceHeaps(lft, rgt, sz_lft, sz_rgt);

            // Mark the old element for delayed removal
            delay[oldEleToDel]++;

            if(oldEleToDel <= getMedian(lft, rgt, sz_lft, sz_rgt)) {
                sz_lft--;
            } else {
                sz_rgt--;
            }

            // Remove elements from the left heap that are marked for delayed removal
            while (!lft.empty() && delay.count(lft.top())) {
                delay[lft.top()]--;
                if (delay[lft.top()] == 0) {
                    delay.erase(lft.top());
                }
                lft.pop();
            }
            
            // Remove elements from the right heap that are marked for delayed removal
            while (!rgt.empty() && delay.count(rgt.top())) {
                delay[rgt.top()]--;
                if (delay[rgt.top()] == 0) {
                    delay.erase(rgt.top());
                }
                rgt.pop();
            }

            // Balance the heaps again after removals
            balanceHeaps(lft, rgt, sz_lft, sz_rgt);
            // Add the median of the current window to the result
            median = getMedian(lft, rgt, sz_lft, sz_rgt);
            ss << fixed << setprecision(5) << median;
            ss >> formatted_median;
            ans.push_back(formatted_median);
        }
        return ans;
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