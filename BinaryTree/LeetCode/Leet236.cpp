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
    bool find(TreeNode* root,TreeNode* p){
        if(root == nullptr){
            return false;
        }
        if(root == p){
            return true;
        }
        return find(root->left, p) || find(root->right, p);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==p || root==q){
            return root;
        }
        bool pInLeft = find(root->left, p);
        bool qInLeft = find(root->left, q);
        if(pInLeft && qInLeft){
            return lowestCommonAncestor(root->left, p, q);
        }
        if(!pInLeft && !qInLeft){
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr || root==p || root==q){
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(left == nullptr && right == nullptr){
            return nullptr;
        }
        else if(left == nullptr){  
            return right;
        }
        else if(right == nullptr){
            return left;
        }
        return root;
    }
};