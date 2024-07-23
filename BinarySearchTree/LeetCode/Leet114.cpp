#include <iostream>
#include <vector>
#include <stack>
#include <climits>
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

class Solution { // S.C(n) = O(n)
public:
    TreeNode *helper(TreeNode *root){
        if(!root) return NULL;
        TreeNode *left = helper(root->left);
        TreeNode *right = helper(root->right);
        root->left = NULL;
        TreeNode *temp=left;
        while(temp && temp->right){
            temp = temp->right;
        }if(temp){
            temp->right = right;
            root->right = left;
        }
        else{
            root->right = right;
        }
        return root;
    }
    void flatten(TreeNode* root) {
        root = helper(root);
    }
};
class Solution { // S.C(n) = O(1)
public:
    void flatten(TreeNode* root) {
        TreeNode *curr = root;
        TreeNode *pre;
        while(curr){
            if(curr->left){
                // save the right subtree
                TreeNode *r = curr->right;
                // make the left subtree the right subtree
                curr->right = curr->left;
                // find the inorder predecessor
                pre = curr->left;
                while(pre->right) pre = pre->right;
                // make the right subtree the right of the inorder predecessor
                pre->right = r;
                curr = curr->left;
            }
            else{
                // move to the right
                curr = curr->right;
            }
        }
        TreeNode *temp = root;
        while(temp){ // making the left subtree NULL
            temp->left = NULL;
            temp = temp->right;
        }
    }
};

