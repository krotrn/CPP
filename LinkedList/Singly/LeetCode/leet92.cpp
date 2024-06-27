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
class Solution {
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prv = nullptr;
        ListNode *curr = head;
        ListNode *nxt = nullptr;
        while (curr != nullptr)
        {
            nxt = curr->next;
            curr->next = prv;
            prv = curr;
            curr = nxt;
        }
        return prv;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right)
            return head;
        ListNode* temp = head;
        ListNode* a = nullptr;
        ListNode* b = nullptr;
        ListNode* c = nullptr;
        ListNode* d = nullptr;
        int i = 1;
        while (temp) {
            if (i == left - 1)
                a = temp;
            if (i == left)
                b = temp;
            if (i == right)
                c = temp;
            if (i == right+1)
                d = temp;
            temp = temp->next;
            i++;
        }
        if (a != nullptr)
            a->next = nullptr;
        c->next = nullptr;
        c = reverseList(b);
        if (a != nullptr)
            a->next = c;
        b->next = d;
        if(left == 1) return c;
        return head;
    }
};