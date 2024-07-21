#include <iostream>
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

class Solution
{
public:
    void sum(TreeNode *root, int &s)
    {
        if (root == NULL)
            return;
        s += root->val;
        sum(root->left, s);
        sum(root->right, s);
        return;
    }

    void helper(TreeNode *root, int &s){
        if(root == NULL) return;
        helper(root->left, s);
        int temp = root->val;
        root->val = s;
        s -= temp;
        helper(root->right, s);
    }

    TreeNode *bstToGst(TreeNode *root)
    {
        int s = 0;
        sum(root, s);
        helper(root, s);
        return root;
    }
};


class Solution
{
public:

    TreeNode *bstToGst(TreeNode *root)
    {
        int s = 0;
        TreeNode *node = root;
        stack<TreeNode *> st;
        while (st.size() || node)
        {
            if(node){
                st.push(node);
                node = node->right;
            }
            else
            {
                node = st.top();
                st.pop();
                s += node->val;
                node->val = s;
                node = node->left;
            }
        }
        return root;
    }
};