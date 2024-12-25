#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
    vector<ll> dp;  // Memoization array to store results of subproblems
    vector<ll> sum; // Precomputed sum array for each mask

    // Function to calculate the sum of compatibility scores for a given mask
    ll calc(vector<vector<int>> &grid, int mask) {
        ll ans = 0;
        int n = grid.size();
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) { // Rabbit `i` is in the subset
                for (int j = i + 1; j < n; j++) {
                    if (mask & (1 << j)) { // Rabbit `j` is also in the subset
                        ans += grid[i][j];
                    }
                }
            }
        }
        return ans;
    }

    // Function to precompute sums for all possible masks
    void preCompute(vector<vector<int>> &grid) {
        int n = grid.size();
        for (int mask = 1; mask < (1 << n); mask++) {
            sum[mask] = calc(grid, mask);
        }
    }

    // Recursive helper function to find the maximum score for a given mask
    ll helper(vector<vector<int>> &grid, int mask) {
        // Base case: If mask is 0 (no rabbits left), return 0
        if (mask == 0)
            return 0;

        // Return the cached result if it has already been computed
        if (dp[mask] != -1)
            return dp[mask];

        ll ans = INT_MIN; // Initialize the maximum score as a very small value

        // Iterate through all subsets of the current mask
        for (int g = mask; g != 0; g = (g - 1) & mask) {
            // Calculate the maximum score by including the current subset (g)
            // and solving the problem for the remaining rabbits (mask ^ g)
            ans = max(ans, sum[g] + helper(grid, mask ^ g));
        }

        // Store the result in the memoization array and return it
        return dp[mask] = ans;
    }

public:
    // Main function to find the maximum grouping score
    ll Grouping(vector<vector<int>> &grid) {
        int n = grid.size();
        // Initialize dp and sum arrays for all masks
        dp.assign(1 << n, -1); // Initialize dp with -1 (uncomputed)
        sum.assign(1 << n, 0); // Initialize sum with 0

        // Precompute sums for all masks
        preCompute(grid);

        // Solve the problem for the full mask (all rabbits included)
        return helper(grid, (1 << n) - 1);
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for (auto &r : grid)
        for (auto &ele : r)
            cin >> ele;
    Solution s;
    cout << s.Grouping(grid) << endl;
    return 0;
}
