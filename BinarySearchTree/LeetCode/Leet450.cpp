#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode *predesessor(TreeNode *root)
    {
        if (!root)
            return root;
        while (root->right!=NULL)
            root = root->right;
        return root;
    }

    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if(!root)
            return NULL;
        if (root->val == key)
        {
            if (root->left == NULL && root->right == NULL)
                return NULL;
            if (root->left==NULL || root->right==NULL)
            {
                if (root->left)
                    return root->left;
                else
                    return root->right;
            }
            if(root->left && root->right)
            {
                TreeNode *iop = predesessor(root->left);
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
};