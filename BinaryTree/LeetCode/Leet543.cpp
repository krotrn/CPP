#include <iostream>
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
    void helper(TreeNode *root, int &maxdia)
    {
        if (root == NULL)
            return;
        maxdia = max(maxdia, level(root->left) + level(root->right));
        helper(root->left, maxdia);
        helper(root->right, maxdia);
    }
    int level(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        return 1 + max(level(root->left), level(root->right));
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        int maxdia = 0;
        helper(root, maxdia);
        return maxdia;
    }
};


class Solution {
private:
    int level(TreeNode* node, int& maxdia) {
        if (node == nullptr)
            return 0;
        int l = level(node->left, maxdia), r = level(node->right, maxdia);
        maxdia = max(maxdia, l + r);
        return 1 + max(l, r);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxdia = 0;
        level(root, maxdia);
        return maxdia;
    }
};
