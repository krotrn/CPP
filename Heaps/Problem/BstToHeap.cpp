#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val) : val(val), left(NULL), right(NULL) {}
    Node(int val, Node *right) : val(val), left(NULL), right(right) {}
    Node(Node *left, int val) : val(val), left(left), right(NULL) {}
    Node(Node *left, int val, Node *right) : val(val), left(left), right(right) {}
};

void inorder(Node* root, vector<int> &v){
    if(!root)
        return;
    inorder(root->right, v);
    v.push_back(root->val);
    inorder(root->left, v);
    return;
}

void print(vector<int> &v){
    for(int i: v)
        cout << i << " ";
    cout << endl;
}

void preorder(Node *root, vector<int> &v, int &i){
    if(!root)
        return;
    root->val = v[i++];
    preorder(root->left, v, i);
    preorder(root->right, v, i);
    return;
}

void levelOrder(Node* root){
    queue<Node *> q;
    q.push(root);
    while(q.size()){
        Node *temp = q.front();
        cout << temp->val << " ";
        q.pop();
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
    cout << endl;
}


int main()
{
    Node *g = new Node(20);
    Node *f = new Node(12);
    Node *e = new Node(8);
    Node *d = new Node(1);
    Node *c = new Node(f,16,g);
    Node *b = new Node(d,5,e);
    Node *a = new Node(b,10,c);

    vector<int> v; // rev inorder
    inorder(a, v); // for dec order
    levelOrder(a);
    int i = 0;
    preorder(a, v, i); // replace the value with array
    levelOrder(a);


}