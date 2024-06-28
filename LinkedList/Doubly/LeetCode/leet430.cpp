#include <iostream>
#include <vector>
using namespace std;
class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};

class Solution
{
public:
    Node *flatten(Node *head)
    {
        Node *t = head;
        while (t)
        {
            Node *a = t->next;
            
            if (t->child)
            {
                a = t->next;
                Node *c = t->child;
                t->child = nullptr;
                c = flatten(c);
                t->next = c;
                c->prev = t;
                while (c->next)
                {
                    c = c->next;
                }
                c->next = a;
                if(a) a->prev = c;
            }
            
            t = a;
        }
        return head;
    }
};