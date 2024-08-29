#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool canAttendMeeting(vector<vector<int>> &intervals){
        int n = intervals.size();
        if(!n)
            return true;
        vector<int> start(n);   // S.C:- O(n)
        vector<int> ending(n);     // S.C:- O(n)
        int i = 0;
        for(auto ele: intervals){
            start[i] = ele[0];
            ending[i++] = ele[1];
        }
        sort(start.begin(), start.end()); // O(nlogn)
        sort(ending.begin(), ending.end());     // O(nlogn)
        i = 0;
        int j = 0;
        int meetingRoom = 0;
        int ans = 0;
        while(i < n && j < n){
            if(start[i] < ending[j]){
                meetingRoom++;
                ans = max(ans, meetingRoom);
            }
            else if (start[i] > ending[j]){
                meetingRoom--;
            }
            else{
                i++;
                j++;
            }
        }
        return ans == 1;
    }
};