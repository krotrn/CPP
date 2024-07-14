#include<iostream>
#include<climits>
using namespace std;
class Node{
    public:
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
    ~Node(){
        delete left;
        delete right;
    }
};

void printTree(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->val<<" ";
    printTree(root->left);
    printTree(root->right);
}


int sum(Node* root){
    if(root == NULL) return 0;
    return root->val + sum(root->left) + sum(root->right);
}
int product(Node* root){
    if(root == NULL) return 1;
    return root->val * product(root->left) * product(root->right);
}

int size(Node* root){
    if(root == NULL) return 0;
    return 1 + size(root->left) + size(root->right);
}
int max1(Node* root){
    if(root == NULL) return INT_MIN;
    return max(root->val,max(max1(root->left),max1(root->right)));
}
int min1(Node* root){
    if(root == NULL) return INT_MAX;
    return min(root->val,min(max1(root->left),max1(root->right)));
}

int level(Node* root){
    if(root == NULL) return 0;
    return 1 + max(level(root->left),level(root->right));
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    printTree(root);
    cout<<endl;
    cout << sum(root) << endl;
    cout << product(root) << endl;
    cout << size(root) << endl;
    cout << max1(root) << endl;
    cout << min1(root) << endl;
    cout << level(root) << endl;
    return 0;
}