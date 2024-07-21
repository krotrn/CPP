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


class Solution {
public:
    TreeNode* parent(TreeNode* root, int val) {
        if(root == NULL) return NULL;
        else if(root->val == val) return NULL;
        else if(root->val > val) {
            if(root->left == NULL || root->left->val == val) return root;
            return parent(root->left, val);
        }
        else {
            if(root->right == NULL || root->right->val == val) return root;
            return parent(root->right, val);
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* newNode = new TreeNode(val);
        if(root == NULL) return newNode;
        TreeNode* par = parent(root, val);
        if(par == NULL) return root;
        if(par->val > val) par->left = newNode;
        else par->right = newNode;
        return root;
    }
};
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) return new TreeNode(val);
        if(root->val > val) root->left = insertIntoBST(root->left, val);
        else root->right = insertIntoBST(root->right, val);
        return root;
    }
};