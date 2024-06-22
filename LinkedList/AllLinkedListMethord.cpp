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

    void insertAtTail(int item)
    {
        Node *temp = new Node(item);
        if (size == 0)
            head = tail = temp;
        else
        {
            tail->next = temp;
            tail = temp;
        }
        size++;
        return;
    }

    void insertAtHead(int item)
    {
        Node *temp = new Node(item);
        if (size == 0)
            head = tail = temp;
        else
        {
            temp->next = head;
            head = temp;
        }
        size++;
        return;
    }

    void insertAtIdx(int item, int idx)
    {
        if (idx < 0 || size < idx)
            cout << "Not Possible" << endl;
        else if (idx == 0)
            insertAtHead(item);
        else if (size == idx)
            insertAtTail(item);
        else
        {
            Node *temp = new Node(item);
            int i = 0;
            Node *temp1 = head;
            while (i < idx - 1)
            {
                temp1 = temp1->next;
                i++;
            }
            temp->next = temp1->next;
            temp1->next = temp;
            size++;
        }
        return;
    }

    int getAtIdx(int idx)
    {
        if (idx < 0)
            cout << "Not Possible" << endl;
        else if (size == 0)
            cout << "Empty" << endl;
        else if (size <= idx)
            cout << "Out of Bound" << endl;
        else
        {
            int i = 0;
            Node *temp = head;
            while (i < idx)
            {
                temp = temp->next;
                i++;
            }
            return temp->val;
        }
        return (int)NULL;
    }

    void deleteAtHead()
    {
        if (size == 0)
            cout << "Empty" << endl;
        else if (size == 1)
        {
            head = tail = NULL;
            size--;
        }
        else
        {
            head = head->next;
            size--;
        }
        return;
    }

    void deleteAtTail()
    {
        if (size == 0)
            cout << "Empty" << endl;
        else if (size == 1)
        {
            head = tail = NULL;
            size--;
        }
        else
        {
            Node *temp = head;
            while (temp->next->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = NULL;
            tail = temp;
            size--;
        }
        return;
    }

    void deleteAtIdx(int idx)
    {
        if (idx < 0 || size <= idx)
            cout << "Not Possible" << endl;
        else if (size == 0)
            cout << "empty" << endl;
        else if (size-1 == idx)
            deleteAtTail();
        else if (idx == 0)
        {
            deleteAtHead();
        }
        else
        {
            Node *temp = head;
            int i = 1;
            while (i < idx - 1)
            {
                temp = temp->next;
                i++;
            }
            temp->next = temp->next->next;
            size--;
        }
        return;
    }
};
int main()
{
    LinkedList ll;
    ll.insertAtTail(10);
    ll.display();
    ll.insertAtTail(20);
    ll.display();
    ll.insertAtTail(30);
    ll.display();
    ll.insertAtTail(40);
    ll.display();
    ll.insertAtIdx(50, 2);
    ll.display();
}