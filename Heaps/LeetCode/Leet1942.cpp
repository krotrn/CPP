#include <bits/stdc++.h>
using namespace std;

class Solution{
#define pr pair<int, int>

public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();

        // Create an fr vector to track the original index of friends
        vector<int> fr(n);
        for (int i = 0; i < n; i++) 
            fr[i] = i;

        // Sort fr based on arrival time
        sort(fr.begin(), fr.end(), [&times](int a, int b) { 
            return times[a][0] < times[b][0];
        });

        // Min-heap for available seats and seats currently taken
        priority_queue<int, vector<int>, greater<int>> emptySeats;
        // {leaving, seat no.}
        priority_queue<pr, vector<pr>, greater<pr>> takenSeats;

        // Initialize empty seats
        for (int i = 0; i < n; i++) 
            emptySeats.push(i);

        // Process each friend's arrival and leave times
        for (int i : fr) {
            int arr = times[i][0]; // current time
            int lv = times[i][1];

            // Free up seats for friends who have already left
            while (!takenSeats.empty() && takenSeats.top().first <= arr) {
                emptySeats.push(takenSeats.top().second);
                takenSeats.pop();
            }

            // Assign the smallest available seat
            int seat = emptySeats.top();
            emptySeats.pop();

            // If this is the target friend, return the seat number
            if (i == targetFriend) {
                return seat;
            }

            // Mark the seat as taken until the friend's leave time
            takenSeats.push({lv, seat});
        }

        return -1;
    }
};

static const auto speedup = []()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
};

int main(){
    vector<vector<int>> v = {{1,4},{2,3}, {4,6}};
    Solution s;
    cout << s.smallestChair(v, 1);
}