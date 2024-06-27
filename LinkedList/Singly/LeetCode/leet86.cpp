#include <iostream>
#include <vector>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *deleteNode(ListNode *head, ListNode *t)
    {
        if (head == nullptr)
            return nullptr;
        if (head->next == nullptr && head == t)
            return nullptr;
        ListNode *temp = head;
        if (temp == t)
        {
            head = head->next;
            temp->next = nullptr;
            temp = head;
        }
        while (temp->next != nullptr)
        {
            if (temp->next == t)
                temp->next = temp->next->next;
            temp = temp->next;
        }
        return head;
    }
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *temp = head;
        ListNode *lo = new ListNode();
        ListNode *temp1 = lo;
        ListNode *hi = new ListNode();
        ListNode *temp2 = hi;
        while (temp != nullptr)
        {
            if (temp->val < x)
            {
                temp1->next = temp;
                temp1 = temp;
                temp = temp->next;
            }
            else
            {
                temp2->next = temp;
                temp2 = temp;
                temp = temp->next;
            }
        }
        temp1->next = hi->next;
        temp2->next = nullptr;
        return lo->next;
    }
};