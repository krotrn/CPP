#include <iostream>
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val) : val(val), left(NULL), right(NULL) {}
};

Node *predesessor(Node *root)
{
    if(!root)
        return root;
    while (!root->right)
        root = root->right;
    return root;
}

Node *successor(Node *root)
{
    if(!root)
        return root;
    while (!root->left)
        root = root->left;
    return root;
}

Node *searchBST(Node *root, int val)
{
    if (root == NULL)
        return NULL;
    else if (root->val == val)
        return root;
    else if (root->val > val)
        return searchBST(root->left, val);
    else
        return searchBST(root->right, val);
}

void deleteNode(Node *root, int target)
{
    Node *temp = root;
    Node *del = searchBST(root, target);
    Node *pre = predesessor(root->left);
    Node* suc = successor(root->right);

    
}