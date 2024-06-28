#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // create a deep copy
        Node *dummy = new Node(-1);
        Node *tempC = dummy;
        Node *temp = head;
        while(temp){
            Node *a = new Node(temp->val);
            tempC->next = a;
            tempC = tempC->next;
            temp = temp->next;
        }
        Node *dublicate = dummy->next;
        // alternate merge
        Node *a = head;
        Node *b = dublicate;
        dummy = new Node(-1);
        Node *tempD = dummy;
        while(b){
            tempD->next = a;
            a = a->next;
            tempD = tempD->next;
            tempD->next = b;
            b = b->next;
            tempD = tempD->next;
        }
        dummy = dummy->next;
        // assigning random pointer
        Node *t1 = dummy;
        Node *t2;
        while(t1){
            t2 = t1->next;
            if(t1->random)
                t2->random = t1->random->next;
            t1 = t1->next->next;
        }
        // re-connecting

        Node *d1 = new Node(-1);
        t1 = d1;
        Node *d2 = new Node(-1);
        t2 = d2;
        Node *t = dummy;
        while (t)
        {
            t1->next = t;
            t = t->next;
            t1 = t1->next;
            t2->next = t;
            t = t->next;
            t2 = t2->next;
        }
        t1->next = nullptr;
        t2->next = nullptr;
        d1 = d1->next;
        d2 = d2->next;
        return d2;
    }
};