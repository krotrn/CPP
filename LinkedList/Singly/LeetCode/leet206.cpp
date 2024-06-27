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
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr || head->next == nullptr)
            return nullptr;
        ListNode *newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
     }
};
