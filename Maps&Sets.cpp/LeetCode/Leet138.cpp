#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // create a deep copy
        Node *dummy = new Node(-1);
        Node *tempC = dummy;
        Node *temp = head;
        unordered_map<Node*, Node*> m;
        while(temp){
            Node *a = new Node(temp->val);
            tempC->next = a;
            // mapping original node to its copy
            m[temp] = a;
            tempC = tempC->next;
            temp = temp->next;
        }
        for(auto i : m){
            if(m.find(i.first->random) == m.end()) i.second->random;
            else i.second->random = m[i.first->random]; // assigning random pointer         
        }
        return dummy->next;
    }
};