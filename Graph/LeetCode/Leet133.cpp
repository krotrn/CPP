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
    vector<Node *> reg;
    void dfs(Node* node, Node* clone){
        for(auto neighbour : node->neighbors){
            Node *temp;
            if(!reg[neighbour->val]){
                temp = new Node(neighbour->val);
                reg[neighbour->val] = temp;
                dfs(neighbour, temp);
            }else{
                temp = reg[neighbour->val];
            }
            clone->neighbors.push_back(temp);
        }
    }
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL)
            return node;
        Node *clone = new Node(node->val);
        reg.resize(110, NULL);
        reg[node->val] = clone;
        dfs(node, clone);
        return clone;
    }
};