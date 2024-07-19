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
};

void left(Node *root)
{
    if (!root || (!root->left && !root->right))
        return;
    cout << root->val << " ";
    left(root->left);
    if (!root->left)
        left(root->right);
    return;
}

void right(Node *root)
{
    if (!root || (!root->left && !root->right))
        return;

    if (!root->right)
        right(root->left);
    right(root->right);
    cout << root->val << " ";
    return;
}

void leaf(Node *root)
{
    if (!root)
        return;
    if (!root->left && !root->right)
        cout << root->val << " ";
    leaf(root->left);
    leaf(root->right);
    return;
}

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
void levelOrder(Node *root, int max)
{
    for (int i = 1; i <= max; i++)
    {
        printNthLevel(root, i);
        cout << endl;
    }
    return;
}

Node *construct(vector<int> &arr)
{
    queue<Node *> q;
    Node *root = new Node(arr[0]);
    q.push(root);
    int i = 1;
    int j = i + 1;
    while (!q.empty() && i < arr.size())
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
        if (j == arr.size() || arr[j] == INT_MIN)
            Node *right = NULL;
        else
        {
            Node *right = new Node(arr[j]);
            temp->right = right;
            q.push(right);
        }
        i += 2;
        j += 2;
    }
    return root;
}

int main()
{
    // test code
    vector<int> v = {1, 2, 3, 4, 5, INT_MIN, 6, 7, INT_MIN, 8, INT_MIN, 9, 10, INT_MIN, 11, INT_MIN, 12, INT_MIN, 13, INT_MIN, 14, 15, 16, INT_MIN, 17, INT_MIN, INT_MIN, 18, INT_MIN, 19, INT_MIN, INT_MIN, INT_MIN, 20, 21, 22, 23, INT_MIN, 24, 25, 26, 27, INT_MIN, INT_MIN, 28, INT_MIN, INT_MIN};
    Node *root = construct(v);
    levelOrder(root, level(root));
    left(root);
    leaf(root);
    Node* temp = root;
    while(!temp->right) temp = root->left;
    right(temp->right);
}