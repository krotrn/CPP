#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
    ~Node(){
        delete left;
        delete right;
    }
};


void topView(Node* root){
    queue<pair<Node*, int>> q; // node and its value
    map<int, int> m; // level and value according to accending level
    q.push({root, 0});
    while(q.size()){
        Node* temp = q.front().first;
        if(m.find(q.front().second) == m.end()){ // if level is not present in map then add it
            m[q.front().second] = temp->val;
        }
        if(temp->left){ // if left child is present then add it to queue with level - 1
            q.push({temp->left, q.front().second - 1});
        }
        if(temp->right){ // if right child is present then add it to queue with level + 1
            q.push({temp->right, q.front().second + 1});
        }
        q.pop();
    }
    for(auto i : m){
        cout<<i.second<<" ";
    }
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->right->right = new Node(5);
    root->left->right->right->right = new Node(6);

    topView(root);
    
}