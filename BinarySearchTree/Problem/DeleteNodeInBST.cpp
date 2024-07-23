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
    if (!root)
        return root;
    while (!root->right)
        root = root->right;
    return root;
}

Node *successor(Node *root)
{
    if (!root)
        return root;
    while (!root->left)
        root = root->left;
    return root;
}

Node *deleteNode(Node *root, int key)
{
    if (!root)
        return NULL;
    if (root->val == key)
    {
        if (root->left == NULL && root->right == NULL)
            return NULL;
        if (root->left == NULL || root->right == NULL)
        {
            if (root->left)
                return root->left;
            else
                return root->right;
        }
        if (root->left && root->right)
        {
            Node *iop = predesessor(root->left);// Inorder Predecessor
            // Node *iop = successor(root->right);// Inorder Successor
            root->val = iop->val;
            root->left = deleteNode(root->left, iop->val);
        }
    }
    else if (root->val > key)
    {
        root->left = deleteNode(root->left, key);
    }
    else
    {
        root->right = deleteNode(root->right, key);
    }
    return root;
}