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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *temp1 = list1;
        ListNode *temp2 = list2;
        ListNode *ans = new ListNode();
        ListNode *temp3 = ans;
        while (temp1 != nullptr && temp2 != nullptr)
        {
            if (temp1->val <= temp2->val)
            {
                temp3->next = temp1;
                temp3 = temp1;
                temp1 = temp1->next;
            }
            else
            {
                temp3->next = temp2;
                temp3 = temp2;
                temp2 = temp2->next;
            }
        }
        if (temp1 == nullptr)
        {
            temp3->next = temp2;
        }
        else if (temp2 == nullptr)
        {
            temp3->next = temp1;
        }
        return ans->next;
    }
    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *slow = head, *fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *b = slow->next;
        slow->next = nullptr;
        head = sortList(head);
        b = sortList(b);
        ListNode *c = mergeTwoLists(head, b);
        return c;
    }
};