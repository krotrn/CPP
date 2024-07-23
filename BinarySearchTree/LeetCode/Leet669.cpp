#include <iostream>
#include <climits>
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

class Solution
{
public:
    TreeNode *trimBST(TreeNode *root, int low, int high)
    {
        if (!root) return NULL;
        else if (root->val < low) return trimBST(root->right, low, high);
        else if (root->val > high) return trimBST(root->left, low, high);
        else
        {
            root->left = trimBST(root->left, low, high);
            root->right = trimBST(root->right, low, high);
            return root;
        }
    }
};




class Solution
{
public:
    void trim(TreeNode *root, int lo, int hi)
    {
        if (!root)
            return;
        while (root->left && root->left->val < lo) 
        {
            if (root->left->val < lo)
            {
                root->left = root->left->right;
            }
            else
            {
                break;
            }
        }
        while (root->right && root->right->val > hi)
        {
            if (root->right->val > hi)
            {
                root->right = root->right->left;
            }
            else
            {
                break;
            }
        }
        trim(root->left, lo, hi);
        trim(root->right, lo, hi);
        return;
    }

    TreeNode *trimBST(TreeNode *root, int low, int high)
    {
        TreeNode* dummy = new TreeNode(INT_MAX,root,NULL);
        trim(dummy, low, high);
        return dummy->left;
    }
};