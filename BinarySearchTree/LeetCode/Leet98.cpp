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


// class Solution {
// public:
//     bool helper(TreeNode* root, long long min, long long max) {
//         if(root == NULL) return true;
//         if((long long)root->val <= min || (long long)root->val >= max) return false;
//         return helper(root->left, min, (long long)root->val) && helper(root->right, (long long)root->val, max);
//     }
//     bool isValidBST(TreeNode* root) {
//         return helper(root, LONG_LONG_MIN, LONG_LONG_MAX);
//     }
// };

// inorder traversal
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        long long prev = LLONG_MIN;
        stack<TreeNode*> st;
        TreeNode* node = root;
        while(st.size() || node) {
            if(node){
                st.push(node);
                node = node->left;
            }
            else {
                node = st.top();
                st.pop();
                if(prev >= (long long)node->val) return false;
                prev = (long long)node->val;
                node = node->right;
            }
        }
        return true;
    }
};

int main() {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    Solution sol;
    cout << sol.isValidBST(root) << endl;
    return 0;
}