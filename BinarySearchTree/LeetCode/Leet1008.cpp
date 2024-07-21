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

class Solution {
public:

    TreeNode* helper(vector<int>& preorder, int start, int end) {
        if(start > end)
            return NULL;
        TreeNode* root = new TreeNode(preorder[start]);
        int i = start+1;
        while(i<=end && preorder[i] < preorder[start])
            i++;
        root->left = helper(preorder, start + 1, i - 1);
        root->right = helper(preorder, i, end);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return helper(preorder, 0, preorder.size()-1);
    }
};