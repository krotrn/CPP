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

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (p->val == root->val || q->val == root->val)
            return root;
        if ((p->val < root->val && root->val < q->val) ||
            (q->val < root->val && root->val < p->val)) {
            return root;
        } else {
            if (p->val > root->val) {
                if (!root->right)
                    return root;
                return lowestCommonAncestor(root->right, p, q);
            }
            if (p->val < root->val) {
                if (!root->left)
                    return root;
                return lowestCommonAncestor(root->left, p, q);
            }
        }
        return root;
    }
};
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if(root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->left, p, q);
        else if(root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->right, p, q);
        return root;
    }
};