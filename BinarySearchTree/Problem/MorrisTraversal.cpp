#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node() : val(0), left(nullptr), right(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : val(x), left(left), right(right) {}
};

void morrisTraversal(Node* root){
    Node *curr = root;
    while(curr){
        if(curr->left){ 
            Node *pre = curr->left;
            while(pre->right && pre->right != curr){ // finding the inorder predecessor
                pre = pre->right;
            }
            if(pre->right == NULL){ // making the thread
                pre->right = curr;
                curr = curr->left;
            }
            else{ // breaking the thread
                pre->right = NULL;
                cout << curr->val << " ";
                curr = curr->right;
            }
        }
        else{
            cout << curr->val << " ";
            curr = curr->right;
        }
    }
}

int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    morrisTraversal(root);
    return 0;
}