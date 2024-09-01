#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int overlapIntervals(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        int rm = 0;
        if (n == 0)
            return 0;
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b)
             { return a[1] < b[1]; });
        int lastEndTime = intervals[0][1];
        for (int i = 1; i < n; i++)
        {
            if (intervals[i][0] <= lastEndTime)
                rm++;
            else
                lastEndTime = intervals[i][1];
        }
        return rm;
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        return points.size()-overlapIntervals(points);
    }
};