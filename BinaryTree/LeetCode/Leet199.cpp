#include <iostream>
#include <vector>
#include <queue>
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
    void helper(TreeNode *root, vector<int> &res)
    {
        if (root == nullptr)
            return;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            int temp = 0;
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                temp = node->val;
                if (node->left != nullptr)
                    q.push(node->left);
                if (node->right != nullptr)
                    q.push(node->right);
            }
            res.push_back(temp);
        }
    }
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> v;
        helper(root, v);
        return v;
    }
};

class Solution
{
public:
    int level(TreeNode *root)
    {
        if (!root)
            return 0;
        return 1 + max(level(root->left), level(root->right));
    }
    void preorder(TreeNode *root, vector<int> &v, int level)
    {
        if (!root)
            return;
        v[level] = root->val;
        preorder(root->left, v, level + 1);
        preorder(root->right, v, level + 1);
    }
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> v(level(root), 0);
        preorder(root, v, 0);
        return v;
    }
};
