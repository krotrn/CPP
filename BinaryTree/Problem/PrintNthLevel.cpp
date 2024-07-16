#include<iostream>

using namespace std;
class Node{
    public:
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val = val;
        left = right = NULL;
    }
};



void printNthLevel(Node* root, int level){
    if(root == nullptr || level < 1){
        return;
    }
    if(level == 1) {
        cout<<root->val<<" ";
        return;
    }
    printNthLevel(root->left, level - 1);
    printNthLevel(root->right, level - 1);
    return;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    printNthLevel(root, 2);
    return 0;
}