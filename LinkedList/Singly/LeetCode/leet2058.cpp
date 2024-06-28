#include <iostream>
#include <vector>
#include<climits>
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
    vector<int> nodesBetweenCriticalPoints(ListNode *head)
    {
        ListNode* a = head;
        ListNode* b = a->next;
        ListNode* c = b->next;
        if (c == nullptr)
            return {-1,-1};
        int idx = 1;
        int fidx = -1;
        int sidx = -1;
        int mind = INT_MAX;
        int f = -1;
        int s = -1;
        while (c) {
            if ((b->val < a->val && b->val < c->val) ||
                (b->val > a->val && b->val > c->val)) {
                if (fidx == -1) 
                    fidx = idx;
                else
                    sidx = idx;
                f = s;
                s = idx;
                if(f != -1){
                    int d = s - f;
                    mind = min(mind, d);
                }
            }
            a = b;
            b = c;
            c = c->next;
            idx++;
        }
        if(sidx == -1) return {-1,-1};
        int maxd = sidx - fidx;
        return {mind,maxd};
    }
};