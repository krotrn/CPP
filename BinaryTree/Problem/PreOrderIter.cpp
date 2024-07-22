#include <iostream>
#include <stack>
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


vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> v;
    stack<TreeNode *> st;
    if (root != nullptr)
        st.push(root);
    while (!st.empty())
    {
        TreeNode *temp = st.top();
        st.pop();
        v.push_back(temp->val);
        if (temp->right)
            st.push(temp->right);
        if (temp->left)
            st.push(temp->left);
    }
    return v;
}