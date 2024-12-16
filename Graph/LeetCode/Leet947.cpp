#include <bits/stdc++.h>

using namespace std;

class Solution {
    // Function to find the root of element x in the Union-Find structure
    int find(int x, unordered_map<int, int> &parent) {
        // If x is not in the map, initialize it as its own parent
        if (parent.find(x) == parent.end()) parent[x] = x;

        // Path compression: make the parent of x point directly to the root
        if (parent[x] != x) parent[x] = find(parent[x], parent);

        return parent[x];
    }

    // Function to unite two elements x and y in the same connected component
    void Union(int x, int y, unordered_map<int, int> &parent) {
        int rootX = find(x, parent); // Find the root of x
        int rootY = find(y, parent); // Find the root of y

        // If roots are different, make one root the parent of the other
        if (rootX != rootY) parent[rootX] = rootY;
    }

public:
    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int, int> parent; // Union-Find structure using a hash map

        // Union stones based on rows and columns
        for (auto stone : stones) {
            // Combine the row index and column index (with offset) into the same group
            Union(stone[0], stone[1] + 20000, parent); 
            // Adding 20000 ensures no overlap between row and column indices
        }

        // Count unique connected components
        unordered_set<int> unique_roots;
        for (auto stone : stones) {
            // Find the root of each stone's row and add it to the set
            unique_roots.insert(find(stone[0], parent));
        }

        // The maximum stones we can remove = total stones - connected components
        return stones.size() - unique_roots.size();
    }
};


class Solution {
    void dfs(int node, unordered_map<int, vector<int>> &graph, unordered_set<int> &visited){
        visited.insert(node);
        for(auto neighbour : graph[node]){
            if(!visited.count(neighbour)){
                dfs(neighbour, graph, visited);
            }
        }
    }

public:
    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int, vector<int>> graph;
        for(auto stone: stones){
            graph[stone[0]].push_back(stone[1] + 20000);
            graph[stone[1] + 20000].push_back(stone[0]);
        }

        unordered_set<int> visited;
        int connected = 0;
        for(auto stone : stones){
            if(!visited.count(stone[0])){
                dfs(stone[0], graph, visited);
                connected++;
            }
        }
        return stones.size() - connected;
    }
};

static const auto speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};






int main() {
    cout << "" << endl;
    return 0;
}