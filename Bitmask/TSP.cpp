#include <bits/stdc++.h>
using namespace std;

class Solution{
    vector<vector<int>> dp;
    
    int helper(vector<vector<int>> &graph, int curr, int mask) {
        // Base case: if all cities have been visited, return to the starting city
        if(mask == (1 << graph.size()) - 1)
            return graph[curr][0];
        
        // If the result is already computed, return the stored result
        if(dp[curr][mask] != -1)
            return dp[curr][mask];
        
        // Initialize the answer to a very large value
        int ans = INT_MAX;
        
        // Try to visit all unvisited cities
        for (int i = 0; i < graph[curr].size(); i++) {
            // Check if city i is not visited yet and there's a path from curr to i
            if(!(mask & (1 << i)) && graph[curr][i])
                // Recurse to the next city, updating the mask to mark city i as visited
                ans = min(ans, graph[curr][i] + helper(graph, i, mask | (1 << i)));
        }
        
        // Store the result in dp table
        return dp[curr][mask] = ans;
    }
    
public:
    int TSP(vector<vector<int>> &graph) {
        // Initialize the dp table with -1 (indicating uncomputed states)
        dp.assign(graph.size(), vector<int>(1 << graph.size(), -1));
        
        // Start the recursive function from city 0 with no cities visited (mask = 0)
        return helper(graph, 0, 0);
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n, 0));
    
    // Input the graph's adjacency matrix (cost of traveling between cities)
    for (auto &r : graph)
        for (int &ele : r)
            cin >> ele;
    
    // Create an object of Solution and call the TSP function
    Solution s;
    cout << s.TSP(graph) << endl;
    
    return 0;
}
