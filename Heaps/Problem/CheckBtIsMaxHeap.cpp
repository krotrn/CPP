#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val) : val(val), left(NULL), right(NULL) {}
    Node(int val, Node *right) : val(val), left(NULL), right(right) {}
    Node(Node *left, int val) : val(val), left(left), right(NULL) {}
    Node(Node *left, int val, Node *right) : val(val), left(left), right(right) {}
};

bool checkMaxheap(Node *root)
{
    if (!root)
        return true;
    else if ((root->left && root->val < root->left->val) || (root->right && root->val < root->right->val))
        return false;
    else
        return checkMaxheap(root->left) && checkMaxheap(root->right);
}

int size(Node *root)
{
    if (!root)
        return 0;
    return 1 + size(root->left) + size(root->right);
}

bool checkCompleteBinaryTree(Node *root)
{
    queue<Node *> q;
    q.push(root);
    int s = size(root);
    int count = 0;
    while (count < s)
    {
        Node *temp = q.front();
        q.pop();
        count++; 
        if (temp)
        {
            q.push(temp->left);
            q.push(temp->right);
        }
    }
    while(q.size()){
        Node *temp = q.front();
        if(temp)
            return false;
        q.pop();
    }
    return true;
}

// bool checkCompleteBinaryTree(Node* root){

//     queue<Node *> q;
//     q.push(root);
//     int s = size(root);
//     int count = 0;
//     while(count<s){
//         Node *temp = q.front();
//         q.pop();
//         if(!temp && count<s)
//             return false;
//         count++;
//         q.push(temp->left);
//         q.push(temp->right);
//     }
//     return true;
// }

int main()
{
    Node *g = new Node(6);
    Node *e = new Node(11);
    Node *d = new Node(8);
    Node *c = new Node(10, g);
    Node *b = new Node(d, 15, e);
    Node *a = new Node(b, 20, c);

    if (checkCompleteBinaryTree(a) && checkMaxheap(a))
        cout << "MaxHeap" << endl;
    else
        cout << "No MaxHeap" << endl;
}