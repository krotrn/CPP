#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int v = numCourses;
        vector<vector<int>> graph(v);
        int edge = prerequisites.size();
        int i = 0;

        // Build the graph from the prerequisites list
        while (i < edge) {
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            i++;
        }

        // Initialize the indegree vector
        vector<int> indegree(v, 0);

        // Calculate the indegree of each node
        for (auto gr : graph) {
            for (auto ele : gr) {
                indegree[ele]++;
            }
        }

        // Initialize the queue with nodes having zero indegree/prerequisites
        queue<int> q;
        for (int i = 0; i < v; i++) {
            if (!indegree[i]) {
                q.push(i);
            }
        }

        // Perform topological sort
        vector<int> topoOrder;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topoOrder.push_back(node);

            // Decrease the indegree of adjacent nodes
            for (auto ele : graph[node]) {
                indegree[ele]--;
                if (!indegree[ele]) {
                    q.push(ele);
                }
            }
        }

        return (topoOrder.size() == v);
    }
};