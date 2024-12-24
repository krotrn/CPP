#include <bits/stdc++.h>

using namespace std;


class Node {
public:
    Node* left;
    Node* right;
    Node() : left(NULL), right(NULL) {}
};

class Solution {
    int getMaxXOR(Node* head, int num) {
        int curr_xor = 0;
        Node* curr = head;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (bit) {
                if (curr->left) {
                    curr_xor += (1 << i);
                    curr = curr->left;
                } else {
                    curr = curr->right;
                }
            } else {
                if (curr->right) {
                    curr_xor += (1 << i);
                    curr = curr->right;
                } else {
                    curr = curr->left;
                }
            }
        }
        return curr_xor;
    }
    void insert(Node* head, int num) {
        Node* curr = head;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (bit) {
                if (!curr->right) curr->right = new Node();
                curr = curr->right;
            } else {
                if (!curr->left) curr->left = new Node();
                curr = curr->left;
            }
        }
    }
public:
    int findMaximumXOR(vector<int>& nums) {
        if (nums.empty()) return 0;

        Node* root = new Node();
        int max_xor = 0;

        insert(root, nums[0]);

        for (int i = 1; i < nums.size(); i++) {
            max_xor = max(max_xor, getMaxXOR(root, nums[i]));
            insert(root, nums[i]);
        }

        return max_xor;
    }
};

int main() {
    cout << '\0' << endl;
    return 0;
} 