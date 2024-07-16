#include <iostream>
#include <vector>
#include<queue>
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
        nthLevel(root->left, level - 1, temp);
        nthLevel(root->right, level - 1, temp);
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

    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        helper(root, res);
        return res;
    }
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

    void helper(TreeNode *root, vector<vector<int>> &res, int level)
    {
        if(root == nullptr) return;
        res[level].push_back(root->val);
        helper(root->left, res, level + 1);
        helper(root->right, res, level + 1);
        return;
    }

    vector<vector<int>> levelOrder(TreeNode *root)
    {
        int max = level(root);
        vector<vector<int>> res(max,vector<int>());
        helper(root, res,0);
        return res;
    }
};



class Solution
{
public:
    void helper(TreeNode *root, vector<vector<int>> &res){
        if(root == nullptr) return;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> temp;
            for (int i = 0; i < size; i++){
                TreeNode *node = q.front();
                q.pop();
                temp.push_back(node->val); 
                if(node->left != nullptr) q.push(node->left);
                if(node->right != nullptr) q.push(node->right);
            }
            res.push_back(temp);
        }
    }

    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        helper(root, res);
        return res;
    }
};