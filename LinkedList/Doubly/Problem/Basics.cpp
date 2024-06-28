#include<iostream>
using namespace std;

class Node{
public:
    Node *prev;
    int val;
    Node *next;
    Node(int val): prev(nullptr), val(val), next(nullptr) {}
    Node(int val, Node *next): prev(nullptr), val(val), next(next) {}
    Node(Node* prev, int val): prev(prev), val(val), next(nullptr) {}
    Node(Node* prev, int val, Node *next): prev(prev), val(val), next(next) {}
};

void display(Node *head){     // S.C = O(1)
    Node *temp = head;
    while(temp){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

void displayRev(Node *head){     // S.C = O(1)
    Node *temp = head;
    while(temp){
        cout << temp->val << " ";
        temp = temp->prev;
    }
    cout << endl;
}



void displayRec(Node *head){    // S.C = O(n)
    if(head == nullptr)
        return;
    cout << head->val << " ";
    displayRec(head->next);
}

void displayRecRev(Node *head){    // S.C = O(n)
    if(head == nullptr)
        return;
    displayRecRev(head->next);
    cout << head->val << " ";
}

int main()
{
    Node *a = new Node(10);
    Node *b = new Node(a, 20);
    Node *c = new Node(b, 30);
    Node *d = new Node(c, 40);
    Node *e = new Node(d, 50);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    display(a);
    displayRev(e);
    displayRec(a);
    cout << endl;
    displayRecRev(a);
}