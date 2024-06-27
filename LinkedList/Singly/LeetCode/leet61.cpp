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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        int len = 0;
        ListNode *temp = head;
        ListNode *tail = nullptr;
        while (temp != nullptr)
        {
            if (temp->next)
                tail = temp;
            temp = temp->next;
            len++;
        }
        if (k == 0)
            return head;
        k = k % len;
        temp = head;
        for (int i = 1; i < len - k - 1; i++)
            temp = temp->next;
        tail->next = head;
        head = temp->next;
        temp->next = nullptr;
        return head;
    }
};

int main()
{
}