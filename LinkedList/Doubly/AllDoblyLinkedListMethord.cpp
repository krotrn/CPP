#include <iostream>
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

class LinkedList
{
public:
    Node *head;
    Node *tail;
    int size = 0;
    LinkedList() : head(NULL), tail(NULL) {}

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

    void displayRev()
    { // S.C = O(1)
        Node *temp = head;
        while (temp)
        {
            cout << temp->val << " ";
            temp = temp->prev;
        }
        cout << endl;
    }

    void insertHead(int item)
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
        size++;
        return;
    }

    void insertTail(int item)
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
        size++;
        return;
    }

    void insertIdx(int item, int idx)
    {
        if (idx < 0 || size < idx)
            cout << "Not Possible" << endl;
        else if (idx == 0)
            insertHead(item);
        else if (size - 1 == idx)
            insertTail(item);
        else
        {
            Node *temp = head;
            Node *a = new Node(item);
            int i = 0;
            while (temp)
            {
                if (i == idx)
                {
                    a->prev = temp->prev;
                    a->next = temp;
                    temp->prev->next = a;
                    temp->prev = a;
                    return;
                }
                temp = temp->next;
                i++;
            }
        }
        return;
    }

    int getIdx(int idx)
    {
        if (idx < 0 || size - 1 < idx)
            cout << "Not Possible" << endl;
        else if (idx == 0)
            return head->val;
        else if (size - 1 == idx)
            return tail->val;
        else if (idx <= size / 2)
        {
            Node *temp = head;
            int i = 0;
            while (temp)
            {
                if (i == idx)
                {
                    return temp->val;
                }
                temp = temp->next;
                i++;
            }
        }
        else if (idx > size / 2)
        {
            Node *temp = tail;
            int i = 0;
            while (temp)
            {
                if (i == size - idx - 1)
                {
                    return temp->val;
                }
                temp = temp->prev;
                i++;
            }
        }
        return -1;
    }

    void deleteHead()
    {
        if (head == nullptr)
            cout << "empty" << endl;
        else
        {
            head = head->next;
            head->prev = nullptr;
            size--;
        }
        return;
    }

    void deleteTail()
    {
        if (head == nullptr)
            cout << "empty" << endl;
        else
        {
            tail = tail->prev;
            tail->next = nullptr;
            size--;
        }
        return;
    }

    void deleteIdx(int idx)
    {
        if (idx < 0 || size < idx)
            cout << "Not Possible" << endl;
        else if (idx == 0)
            deleteHead();
        else if (size - 1 == idx)
            deleteTail();
        else
        {
            Node *temp = head;
            int i = 0;
            while (temp)
            {
                if (i == idx)
                {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    return;
                }
                temp = temp->next;
                i++;
            }
            size--;
        }
        return;
    }
};

int main()
{
    LinkedList *list = new LinkedList();
    list->insertTail(10);
    list->insertTail(20);
    list->insertTail(30);
    list->insertTail(40);
    list->insertTail(50);
    list->display();
    list->deleteHead();
    list->display();
    cout << list->getIdx(1) << endl;
    cout << list->getIdx(4) << endl;
    cout << list->size << endl;
}