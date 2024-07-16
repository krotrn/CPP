#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        left = right = NULL;
    }
    Node()
    {
    }
};

int level(Node *root)
{
    if (root == NULL)
        return 0;
    return 1 + max(level(root->left), level(root->right));
}

void printNthLevel(Node *root, int level)
{
    if (root == nullptr || level < 1)
    {
        return;
    }
    if (level == 1)
    {
        cout << root->val << " ";
        return;
    }
    printNthLevel(root->left, level - 1);
    printNthLevel(root->right, level - 1);
    return;
}
void levelOrder(Node *root)
{
    int max = level(root);
    for (int i = 1; i <= max; i++)
    {
        printNthLevel(root, i);
        cout << endl;
    }
    return;
}

Node* construct(vector<int> &arr)
{
    queue<Node *> q;
    Node *root = new Node(arr[0]);
    q.push(root);
    int i = 1;
    int j = i + 1;
    while (!q.empty() && i<arr.size())
    {
        Node *temp = q.front();
        q.pop();
        if (arr[i] == INT_MIN)
            Node *left = NULL;
        else
        {
            Node *left = new Node(arr[i]);
            temp->left = left;
            q.push(left);
        }
        if (j==arr.size() || arr[j] == INT_MIN)
            Node *right = NULL;
        else
        {
            Node *right = new Node(arr[j]);
            temp->right = right;
            q.push(right);
        }
        i+=2;
        j+=2;
    }
    return root;
}

int main(){
    vector<int> v = {3, 9, 20, INT_MIN, INT_MIN, 15, 7};
    Node *root = construct(v);
    levelOrder(root);
}