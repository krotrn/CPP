#include <iostream>
#include <deque>
using namespace std;

class Node
{
public:
    Node *prev;
    int val;
    Node *next;
    Node(int val) : prev(nullptr), val(val), next(nullptr) {}
    Node(int val, Node *next) : prev(nullptr), val(val), next(next) {}
    Node(Node *prev, int val) : prev(prev), val(val), next(nullptr) {}
    Node(Node *prev, int val, Node *next) : prev(prev), val(val), next(next) {}
};

class Deque
{
public:
    Node *head;
    Node *tail;
    int sizef = 0;
    Deque() : head(NULL), tail(NULL) {}

    void display()
    { // S.C = O(1)
        Node *temp = head;
        while (temp)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void pushFront(int item)
    {
        Node *temp = new Node(item);
        if (head == nullptr)
            head = tail = temp;
        else
        {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        sizef++;
        return;
    }

    void pushBack(int item)
    {
        Node *temp = new Node(item);
        if (head == nullptr)
            head = tail = temp;
        else
        {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        sizef++;
        return;
    }

    void popFront()
    {
        if (head == nullptr)
            cout << "empty" << endl;
        else
        {
            head = head->next;
            head->prev = nullptr;
            sizef--;
        }
        return;
    }

    void popBack()
    {
        if (head == nullptr)
            cout << "empty" << endl;
        else
        {
            tail = tail->prev;
            tail->next = nullptr;
            sizef--;
        }
        return;
    }

    int front()
    {
        if (head == nullptr)
        {
            cout << "Deque is Empty" << endl;
            return -1;
        }
        return head->val;
    }

    int back()
    {
        if (head == nullptr)
        {
            cout << "Deque is Empty" << endl;
            return -1;
        }
        return tail->val;
    }

    int size()
    {
        return sizef;
    }
};

int main()
{
    Deque q;
    q.pushFront(10);
    q.pushFront(20);
    q.pushBack(30);
    q.display();
    q.popFront();
    q.display();
    q.popBack();
    q.display();
    cout << q.front() << endl;
    cout << q.back() << endl;
    cout << q.size() << endl;
    return 0;
}