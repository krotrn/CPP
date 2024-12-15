#include <bits/stdc++.h>

using namespace std;

vector<list<int>> graph; // Adjacency list representation
int v;

void addEdge(int a, int b, bool bidir = true) {
    graph[a].push_back(b);
    if (bidir)
        graph[b].push_back(a); // For undirected graphs
}

void topologicalSortBFS() {
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

    if (topoOrder.size() != v) {
        cout << "The graph contains a cycle. Topological sort is not possible." << endl;
    } else {
        cout << "Topological Order: ";
        for (auto node : topoOrder) {
            cout << node << " ";
        }
        cout << endl;
    }
}

int main() {
    cout << "Enter the number of vertices: ";
    cin >> v;
    graph.resize(v, list<int>());
    int e;
    cout << "Enter the number of edges: ";
    cin >> e;
    cout << "Enter the edges (format: a b):" << endl;
    while (e--) {
        int a, b;
        cin >> a >> b;
        if (a < 0 || a >= v || b < 0 || b >= v) {
            cout << "Invalid edge: (" << a << ", " << b << ")" << endl;
            return 1;
        }
        addEdge(a, b, false);
    }
    topologicalSortBFS();
    return 0;
}
