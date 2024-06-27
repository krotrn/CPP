#include<iostream>
using namespace std;
 struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *tempA = headA;
        ListNode *tempB = headB;
        int lenA = 0;
        int lenB = 0;
        while(tempA!=nullptr){
            tempA = tempA->next;
            lenA++;
        }
        while(tempB!=nullptr){
            tempB = tempB->next;
            lenA++;
        }
        tempA = headA;
        tempB = headB;
        if(lenA>lenB){
            for (int i = 0; i < lenA - lenB; i++)
                tempA = tempA->next;
        }
        else if(lenA<lenB){
            for (int i = 0; i < lenB - lenA; i++)
                tempB = tempB->next;
        }
        while(tempA!=nullptr){
            if(tempA==tempB)
                return tempA;
            tempA = tempA->next;
            tempB = tempB->next;
        }
        return nullptr;
    }
};