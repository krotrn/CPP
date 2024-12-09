#include <bits/stdc++.h>

using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        queue<Node *> q;
        vector<bool> visited(n, false);
        q.push(0);
        visited[0] = true;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(auto key: rooms[curr]){
                if(!visited[key]){
                    q.push(key);
                    visited[key] = true;
                }
            }
        }
    }
};