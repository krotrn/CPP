#include <iostream>
#include <vector>
#include<stack>
#include<algorithm>
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
    void postOrder(vector<int>& v, TreeNode* root) {
        if (root == NULL) {
            return;
        }
        postOrder(v, root->left);
        postOrder(v, root->right);
        v.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        postOrder(v, root);
        return v;
    }
};



class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        stack<TreeNode *> st;
        if(root != nullptr)st.push(root);
        while (st.size() > 0)
        {
            TreeNode *temp = st.top();
            st.pop();
            v.push_back(temp->val);
            if (temp->left != nullptr)
                st.push(temp->right);
            if (temp->right != nullptr)
                st.push(temp->right);
            reverse(v.begin(), v.end());
        }
        return v;
    }
};