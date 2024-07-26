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
int level(Node* root){
    if(root == NULL) return 0;
    return 1 + max(level(root->left),level(root->right));
}

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
void levelOrder(Node* root){
    int max = level(root);
    for (int i = 1; i <= max; i++){
        printNthLevel(root, i);
        cout<<endl;
    }
    return;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    levelOrder(root);
    return 0;
}