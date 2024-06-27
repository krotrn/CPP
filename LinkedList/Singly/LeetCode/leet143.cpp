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
    ListNode* reverseList(ListNode* head) {
        ListNode* prv = nullptr;
        ListNode* curr = head;
        ListNode* nxt = nullptr;
        while (curr != nullptr) {
            nxt = curr->next;
            curr->next = prv;
            prv = curr;
            curr = nxt;
        }
        return prv;
    }
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr ||
            head->next->next == nullptr)
            return;
        ListNode *slow = head, *fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* b = reverseList(slow->next);
        ListNode* a = head;
        slow->next = nullptr;
        ListNode* c = new ListNode();
        ListNode* tempc = c;
        ListNode* tempa = a;
        ListNode* tempb = b;
        while (tempa && tempb) {
            tempc->next = tempa;
            tempc = tempa;
            tempa = tempa->next;
            if (tempb != nullptr) {
                tempc->next = tempb;
                tempc = tempb;
                tempb = tempb->next;
            }
        }
        tempc->next = nullptr;
        head = c->next;
        return;
    }
};