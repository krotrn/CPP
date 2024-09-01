#include <bits/stdc++.h>
using namespace std;

/**
 * check out min stack
 */

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
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
            if (intervals[i][0] < lastEndTime)
            {
                rm++;
            }
            else
            {
                lastEndTime = intervals[i][1];
            }
        }
        return rm;
    }
};

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        int rm = 0;
        if (n == 0)
            return 0;
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b)
             { return a[0] < b[0]; });
        int lastEndTime = intervals[0][1];
        for (int i = 1; i < n; i++)
        {
            if (intervals[i][0] < lastEndTime)
            {
                rm++;
                lastEndTime = min(lastEndTime, intervals[i][1]);
            }
            else
            {
                lastEndTime = intervals[i][1];
            }
        }
        return rm;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    cout << s.eraseOverlapIntervals(intervals) << endl;
    return 0;
}
