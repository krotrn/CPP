#include <iostream>
#include <vector>
#include <stack>
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        inOrder(v, root);
        return v;
    }
};


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        stack<TreeNode *> st;
        TreeNode *node = root;
        while(st.size() || node){
            if(node){
                st.push(node);
                node = node->left;
            }
            else{
                if(st.empty())
                    break;
                TreeNode *temp = st.top();
                st.pop();
                v.push_back(temp->val);
                node = temp->right;
            }
        }
        return v;
    }
};