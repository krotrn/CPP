#include <bits/stdc++.h>
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
    void find(TreeNode* root, int start, TreeNode* &st) {
        if (!root)
            return;
        if (root->val == start){
            st=root;
            return;
        }
        if (root->left)
            find(root->left, start,st);
        if (root->right)
            find(root->right, start,st);
        return;
    }
    void childParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& C_P) {
        if (!root)
            return;
        if (root->left) {
            C_P[root->left] = root;
            childParent(root->left, C_P);
        }
        if (root->right) {
            C_P[root->right] = root;
            childParent(root->right, C_P);
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> C_P;
        // connecting children to parent
        childParent(root, C_P);
        // finding infected element
        TreeNode* st;
        find(root, start,st);
        // mark infected
        unordered_set<TreeNode*> isInfected;
        // node time pairing
        queue<pair<TreeNode*, int>> level;
        level.push({st, 0});
        isInfected.insert(st);
        int time = INT_MIN;
        int lvl;
        while (level.size()) {
            pair<TreeNode*, int> q = level.front();
            level.pop();
            TreeNode* curr = q.first;
            lvl = q.second;
            time = max(time, lvl);
            if (curr && curr->left){
                if (isInfected.find(curr->left) == isInfected.end()) {
                    isInfected.insert(curr->left);
                    level.push({curr->left, lvl + 1});
                }
            }
            if (curr && curr->right) {
                if (isInfected.find(curr->right) == isInfected.end()) {
                    isInfected.insert(curr->right);
                    level.push({curr->right, lvl + 1});
                }
            }
            if (C_P.find(curr) != C_P.end())
            {
                if (isInfected.find(C_P[curr]) == isInfected.end())
                {
                    isInfected.insert(C_P[curr]);
                    level.push({C_P[curr], lvl + 1});
                }
            }
            time = max(time, lvl);
        }
        return time;
    }
};