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
    TreeNode *build(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd)
    {
        if (preStart > preEnd || inStart > inEnd)
            return nullptr;
        TreeNode *root = new TreeNode(preorder[preStart]);
        int inRoot = 0;
        for (int i = inStart; i <= inEnd; i++)
        {
            if (inorder[i] == root->val)
            {
                inRoot = i;
                break;
            }
        }

        int leftSize = inRoot - inStart;
        
        root->left = build(preorder, preStart + 1, preStart + leftSize, inorder, inStart, inRoot - 1);

        root->right = build(preorder, preStart + leftSize + 1, preEnd, inorder, inRoot + 1, inEnd);

        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int n = preorder.size();
        return build(preorder, 0, n - 1, inorder, 0, n - 1);
    }
};