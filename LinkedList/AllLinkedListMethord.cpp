#include <iostream>
using namespace std;
class Node //  user defined data type
{
public:
    int val;
    Node *next;
    Node(int val) : val(val), next(NULL) {}
};

class LinkedList //  user defined data structure
{
public:
    Node *head;
    Node *tail;
    int size = 0;
    LinkedList() : head(NULL), tail(NULL) {}
    void insertAtEnd(int item)
    {
        Node *a = new Node(item);
        if (size == 0)
            head = tail = a;
        else
        {
            tail->next = a;
            tail = a;
        }
        size++;
        return;
    }
    void display() // S.C -> O(n)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main()
{
    LinkedList ll;
    ll.insertAtEnd(10);
    ll.display();
    ll.insertAtEnd(20);
    ll.display();
    ll.insertAtEnd(30);
    ll.display();
    ll.insertAtEnd(50);
    ll.display();
}