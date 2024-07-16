#include <iostream>
#include <vector>
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
    int level(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        return 1 + max(level(root->left), level(root->right));
    }
    void nthLevel(TreeNode *root, int level, vector<int> &temp)
    {
        if (root == nullptr || level < 0)
            return;
        else if (level == 0)
        {
            temp.push_back(root->val);
        }
        if(level % 2 == 0)
        {
            nthLevel(root->left, level - 1, temp);
            nthLevel(root->right, level - 1, temp);
        }
        else
        {
            nthLevel(root->right, level - 1, temp);
            nthLevel(root->left, level - 1, temp);
        }
        return;
    }

    void helper(TreeNode *root, vector<vector<int>> &res)
    {
        int max = level(root);
        for (int i = 0; i < max; i++)
        {
            vector<int> temp;
            nthLevel(root, i, temp);
            res.push_back(temp);
        }
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        helper(root, res);
        return res;
    }
};