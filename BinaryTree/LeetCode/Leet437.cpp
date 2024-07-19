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


class Solution {
public:

    void helper(TreeNode* root, int targetSum, int &count) {
        if (root == nullptr)
            return;
        helper(root->left, targetSum - root->val, count);
        helper(root->right, targetSum - root->val, count);
        if (root->val == targetSum)
            count++;
        return;
    }


    int pathSum(TreeNode* root, int targetSum) {
        int count = 0;
        helper(root, targetSum, count);
        count += pathSum(root->left, targetSum)  + pathSum(root->right, targetSum);
        return count;
    }
};