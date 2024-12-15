#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int v = numCourses;
        vector<list<int>> graph(v, list<int>());
        graph.resize;
        int edge = prerequisites.size();
        int i = 0;
        while (i < edge) {
            int a = prerequisites[i][1];
            int b = prerequisites[i][0];
            graph[a].push_back(b);
            i++;
        }
        vector<int> indegree(v, 0);

        for (auto gr : graph) {
            for (auto ele : gr) {
                indegree[ele]++;
            }
        }

        queue<int> q;

        for (int i = 0; i < v; i++) {
            if (!indegree[i]) {
                q.push(i);
            }
        }

        vector<int> topoOrder;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topoOrder.push_back(node);

            for (auto ele : graph[node]) {
                indegree[ele]--;
                if (!indegree[ele]) {
                    q.push(ele);
                }
            }
        }
        vector<int> em;
        return (topoOrder.size() != v) ? em : topoOrder;
    }
};