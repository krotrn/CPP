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
    void inOrder(vector<int>& v, TreeNode* root) {
        if (root == NULL) {
            return;
        }
        inOrder(v, root->left);
        v.push_back(root->val);
        inOrder(v, root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        inOrder(v, root);
        return v;
    }
};