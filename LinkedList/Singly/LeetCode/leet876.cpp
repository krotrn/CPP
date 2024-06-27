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
    ListNode *middleNode(ListNode *head)
    {
        ListNode *save = head, *temp = head;
        int c = 0;
        while (temp->next != nullptr)
        {
            temp = temp->next;
            if (c % 2 == 0)
                save->next;
            c++;
        }
        return save;
    }
};
ListNode *middleNode(ListNode *head)
{
    ListNode *save = head, *temp = head;
    while (temp != nullptr && temp->next != nullptr)
    {
        temp = temp->next->next;
        save = save->next;
    }
    return save;
}