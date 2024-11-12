#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> dp(n + 1, INT_MAX - 1);
        for (int i = 0; i <= n; i++){
            int start = max(0, i - ranges[i]);
            int end = min(n, i + ranges[i]);
            for (int j = start; j <= end; j++)
                dp[end] = min(dp[end], dp[j] + 1);
        }
        return dp[n] == INT_MAX - 1 ? -1 : dp[n];
    }
};

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        // Step 1: Build maxReach array
        // The maxReach array stores the farthest point that can be watered starting from each index.
        // maxReach[i] = the farthest position that can be watered starting from position i.
        vector<int> maxReach(n + 1, 0);
        
        // Iterate through each tap to calculate its effective range in the garden.
        for (int i = 0; i <= n; i++) {
            // Calculate the start and end of the range this tap can cover.
            int start = max(0, i - ranges[i]);  // The starting index the tap can water (clamped to 0).
            int end = min(n, i + ranges[i]);    // The ending index the tap can water (clamped to n).
            
            // Update the maxReach array: ensure it reflects the farthest range starting from 'start'.
            maxReach[start] = max(maxReach[start], end);
        }

        // Step 2: Greedy approach to find the minimum number of taps needed
        // Variables:
        // taps: Count of taps opened.
        // currentEnd: The farthest point that can be watered with the currently opened taps.
        // farthest: The farthest point that can be reached at the current step.
        int taps = 0, currentEnd = 0, farthest = 0;

        // Traverse the garden from 0 to n.
        for (int i = 0; i <= n; i++) {
            // If the current index is beyond the farthest point reachable, it's impossible to cover the garden.
            if (i > farthest)
                return -1;

            // If the current index exceeds the range covered by the currently opened taps,
            // open a new tap to extend the watering range.
            if (i > currentEnd) {
                taps++;                     // Increment the tap count.
                currentEnd = farthest;      // Update the range covered by the opened taps.
            }

            // Update the farthest point that can be reached.
            farthest = max(farthest, maxReach[i]);
        }

        // Return the total number of taps opened.
        return taps;
    }
};
