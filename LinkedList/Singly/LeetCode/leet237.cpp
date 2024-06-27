#include <iostream>
using namespace std;

// Definition for singly-linked list.
class ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}

public:
    ListNode *head = new ListNode(5);
    void deleteNode(ListNode *node)
    {
        node->val = node->next->val;
        node->val = node->next->val;
    }
};