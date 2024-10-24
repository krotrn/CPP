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
    TreeNode* replaceValueInTree(TreeNode* root) {
        // Base case: If the tree is empty, return nullptr
        if (root == nullptr)
            return root;

        // Vector to store the sum of node values at each level
        vector<int> levelSum;

        // Queue to perform level order traversal (BFS)
        queue<TreeNode*> q;
        q.push(root);

        // First BFS: Calculate the sum of node values at each level
        while (!q.empty()) {
            int n = q.size();
            int sum = 0;

            // Traverse all nodes at the current level
            while (n--) {
                TreeNode* temp = q.front();
                q.pop();
                sum += temp->val; // Add node value to the sum

                // Push left and right children to the queue
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }

            // Store the sum of this level
            levelSum.push_back(sum);
        }

        // Second BFS: Update node values with their cousin sum
        int i = 2; // Start updating from level 2 (since level 0 and 1 are handled separately)
        int level = levelSum.size(); // Total number of levels
        root->val = 0; // Set root value to 0 as per the requirement

        // passing the root node to queue
        q.push(root);

        // Continue BFS to update the values of all remaining nodes
        while (!q.empty()) {
            int n = q.size();

            // Traverse all nodes at the current level
            while (n--) {
                TreeNode* temp = q.front();
                q.pop();

                // Calculate the sum of the sibling node values
                int sibSum = 0;
                if (temp->left)
                    sibSum += temp->left->val;
                if (temp->right)
                    sibSum += temp->right->val;

                // Update the left and right children based on cousin sum
                if (temp->left) {
                    temp->left->val = levelSum[i] - sibSum;
                    q.push(temp->left);
                }
                if (temp->right) {
                    temp->right->val = levelSum[i] - sibSum;
                    q.push(temp->right);
                }
            }

            // Move to the next level
            i++;
        }
        return root;
    }
};
