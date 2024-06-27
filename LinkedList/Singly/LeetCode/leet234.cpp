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

    bool isPalindrome(ListNode* head) {
       ListNode *slow = head, *fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* newHead = reverseList(slow->next);
        ListNode* temp1 = head;
        ListNode* temp2 = newHead;
        while (temp2 != nullptr) {
            if (temp1->val != temp2->val)
                return false;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return true;
    }
};