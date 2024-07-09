#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    Node(int val) : val(val), next(nullptr) {}
    Node(Node *next) : val(0), next(next) {}
    Node(int val, Node *next) : val(val), next(next) {}
};

class Queue
{
    Node *head;
    Node *back;
    int sizef = 0;

public:
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
    void push(int item)
    {
        Node *temp = new Node(item);
        if (sizef == 0)
            head = back = temp;
        else
        {
            back->next = temp;
            back = temp;
        }
        sizef++;
        return;
    }
    void pop()
    {
        if (head == nullptr)
        {
            cout << "Queue Empty" << endl;
            return;
        }
        sizef--;
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    int front()
    {
        if (head == nullptr)
        {
            cout << "Queue Empty" << endl;
            return -1;
        }
        return head->val;
    }
    int size()
    {
        return sizef;
    }

    bool empty()
    {
        return (sizef == 0);
    }
};

int main()
{
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.display();
    q.pop();
    q.display();
    cout << q.front() << endl;
    cout << q.size() << endl;
    cout << q.empty() << endl;
    return 0;
}