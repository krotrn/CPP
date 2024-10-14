#include <bits/stdc++.h>
using namespace std;

class Solution {
#define pr pair<int, int>
public:
    int minGroups(vector<vector<int>>& intervals) {
        priority_queue<pr, vector<pr>, greater<pr>> pq;
        for (int i = 0; i < intervals.size(); i++)
            pq.push({intervals[i][0], intervals[i][1]});
        priority_queue<int, vector<int>, greater<int>> leaving;
        leaving.push(pq.top().second);
        pq.pop();
        while (!pq.empty()) {
            if (pq.top().first > leaving.top())
                leaving.pop();
            leaving.push(pq.top().second);
            pq.pop();
        }
        return leaving.size();
    }
};

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int> start_times, end_times;

        // Extract start and end times
        for (const auto& interval : intervals) {
            start_times.push_back(interval[0]);
            end_times.push_back(interval[1]);
        }

        // Sort start and end times
        sort(start_times.begin(), start_times.end());
        sort(end_times.begin(), end_times.end());

        int end_ptr = 0, group_count = 0;

        // Traverse through the start times
        for (int start : start_times) {
            if (start > end_times[end_ptr]) {
                end_ptr++;
            } else {
                group_count++;
            }
        }

        return group_count;
    }
};
class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        priority_queue<int, vector<int>, greater<int>> pq;

        for(auto &eles : intervals){
            int start = eles[0];
            int end = eles[1];

            if(!pq.empty() && start > pq.top())
                pq.pop();

            pq.push(end);
        }

        return pq.size();
    }
};

static const auto &speedup = []()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
};