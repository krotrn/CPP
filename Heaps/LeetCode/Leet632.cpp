#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    typedef pair<int, pair<int, int>> pip;
    vector<int> smallestRange(vector<vector<int>> &nums){ // T.C. O(nklogk) S.C. O(k)
        // for finding min
        priority_queue<pip, vector<pip>, greater<pip>> pq;
        // for finding max
        int mx = INT_MIN;
        // fill pq with first element of each row
        // {value, {row, col}}
        for(int i = 0; i < nums.size(); i++){ // T.C. O(klogk)
            pq.push({nums[i][0], {i, 0}});
            mx = max(mx, nums[i][0]);
        }
        // min of all first elements
        int mn = pq.top().first;
        // range = [start, end]
        int start = mn, end = mx;
        while(true){ // T.C. O(nklogk)
            // {value, {row, col}}
            auto p = pq.top();
            pq.pop(); // T.C. O(logk)
            // row
            int row = p.second.first;
            // col
            int col = p.second.second;
            // if we reach the end of any row
            if(col + 1 == nums[row].size())
                break;
            // push next element of min row
            pq.push({nums[row][col + 1], {row, col + 1}}); // T.C. O(logk)
            // update mx
            mx = max(mx, nums[row][col + 1]);
            // update mn
            mn = pq.top().first;
            // if new range is smaller than previous range
            if(mx - mn < end - start){
                start = mn;
                end = mx;
            }
        }
        return {start, end};
    }
};