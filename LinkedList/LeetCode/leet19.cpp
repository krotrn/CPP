#include <iostream>
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *temp = head;
        int len = 0;
        while (temp != nullptr)
        {
            len++;
            temp = temp->next;
        }
        if (n == len)
        {
            head = head->next;
            return head;
        }
        n = len - n;
        temp = head;
        for (int i = 0; i < n - 1; i++)
            temp = temp->next;
        temp->next = temp->next->next;
        return head;
    }
};
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *slow = head, *fast = head;
        for (int i = 0; i <= n;i++)
            fast = fast->next;
        while(fast!=nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return slow;
    }
};