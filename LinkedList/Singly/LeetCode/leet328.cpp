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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* temp = head;
        ListNode* lo = new ListNode();
        ListNode* temp1 = lo;
        ListNode* hi = new ListNode();
        ListNode* temp2 = hi;
        int x = 0;
        while (temp != nullptr) {
            if (x % 2 == 0) {
                temp1->next = temp;
                temp1 = temp;
                temp = temp->next;
                x++;
            } else {
                temp2->next = temp;
                temp2 = temp;
                temp = temp->next;
                x++;
            }
        }
        temp1->next = hi->next;
        temp2->next = nullptr;
        return lo->next;
    }
};