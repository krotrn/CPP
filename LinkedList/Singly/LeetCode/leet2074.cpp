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

    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (left == right)
            return head;
        ListNode *temp = head;
        ListNode *a = nullptr;
        ListNode *b = nullptr;
        ListNode *c = nullptr;
        ListNode *d = nullptr;
        int i = 1;
        while (i < right + 2)
        {
            if (i == left - 1)
                a = temp;
            if (i == left)
                b = temp;
            if (i == right)
                c = temp;
            if (i == right + 1)
            {
                d = temp;
                break;
            }
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
        if (left == 1)
            return c;
        return head;
    }

    ListNode *reverseEvenLengthGroups(ListNode *head)
    {
        ListNode *temp = head;
        int gap = 1;
        int rem = 0;
        while (temp->next)
        {
            rem = 0;
            ListNode *t = temp->next;
            for (int i = 0; i < gap && t; i++)
            {
                t = t->next;
                rem++;
            }
            if (rem < gap + 1)
                gap = rem - 1;
            if (gap % 2 != 0)
                reverseBetween(temp, 2, gap + 2);
            gap++;
            for (int i = 0; i < gap; i++)
            {
                temp = temp->next;
            }
        }
        return head;
    }
};
int main() {}

ListNode *reverseEvenLengthGroups(ListNode *head)
{
    ListNode *dummy;
    dummy->next = head;
    ListNode *groupPrev = dummy, *curr = head;
    int groupSize = 1;

    while (curr)
    {
        int count = 0;
        ListNode *groupStart = curr;
        // Move curr to the end of the current group
        while (curr && count < groupSize)
        {
            curr = curr->next;
            count++;
        }
        // If the group size is even, reverse the group
        if (count % 2 == 0)
        {
            ListNode *reversed = reverseList(groupStart, count);
            // Connect the previous group to the reversed group
            groupPrev->next = reversed;
            // Move groupPrev to the end of the reversed group
            groupPrev = groupStart;
            // Connect the reversed group to the rest of the list
            groupStart->next = curr;
        }
        else
        {
            // If the group is not reversed, just move groupPrev to the end of the current group
            groupPrev = groupStart;
            for (int i = 1; i < count; i++)
            {
                groupPrev = groupPrev->next;
            }
        }
        // Increase the group size for the next iteration
        groupSize++;
    }
    return dummy->next;
}

// Helper function to reverse 'count' nodes in the list starting from 'head'
ListNode *reverseList(ListNode *head, int count)
{
    ListNode *prev = nullptr, *curr = head, *next = nullptr;
    int i = 0;
    while (curr && i < count)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        i++;
    }
    head->next = curr; // Connect the end of the reversed part to the next node
    return prev;       // New head of the reversed part
}