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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        else
        {
            ListNode *slow = head;
            ListNode *fast = head->next;
            while (fast != nullptr)
            {
                while (fast != nullptr && slow->val == fast->val)
                {
                    fast = fast->next;
                    slow->next = fast;
                }
                slow = fast;
                if (fast != nullptr)
                    fast = fast->next;
            }
        }
    }
};