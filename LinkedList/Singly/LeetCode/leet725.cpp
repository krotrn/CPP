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
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        vector<ListNode *> ans;
        ListNode *temp = head;
        int n = 0;
        while(temp){
            n++;
            temp = temp->next;
        }
        int rem = n % k;
        int len = n / k + 1;
        temp = head;
        while(temp){
            ListNode *c = new ListNode();
            ListNode *tempC = c;
            if(rem>0)
                len++;
            for (int i = 0; i < len; i++){
                tempC->next = temp;
                tempC = tempC->next;
                temp = temp->next;
            }
            rem--;
            tempC->next = nullptr;
            ans.push_back(c->next);
        }
        if(ans.size()<k){
            int ex = k - ans.size();
            for (int i = 0; i < ex; i++){
                ans.push_back(nullptr);
            }
        }
        return ans;
    }
};