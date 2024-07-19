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

    void helper(TreeNode *root, int targetSum, vector<vector<int>> &res, vector<int> path)
    {
        if(root==nullptr || targetSum<0)
            return;
        if (root->left == nullptr && root->right == nullptr && targetSum == 0)
        {
            res.push_back(path);
            return;
        }
        path.push_back(root->val);
        helper(root->left, targetSum - root->val, res, path);
        helper(root->right, targetSum - root->val, res, path);

    }


    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<vector<int>> res;
        vector<int> path;
        helper(root, targetSum, res, {});
        return res;
    }
};