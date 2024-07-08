#include <iostream>
#include <vector>
using namespace std;

class Queue
{
    int arr[5];
    int f;
    int b;

public:
    Queue()
    {
        f = 0;
        b = 0;
    }
    int size()
    {
        return b - f;
    }
    void push(int val)
    {
        if (b == 5)
        {
            cout << "Queue Overflow" << endl;
            return;
        }
        arr[b] = val;
        b++;
    }
    void pop()
    {
        if (!(b - f))
        {
            cout << "Stack Underflow" << endl;
            return;
        }
        f++;
    }
    int front()
    {
        if (!(b - f))
        {
            cout << "Stack Empty" << endl;
            return -1;
        }
        return arr[f];
    }
    int back()
    {
        if (!(b - f))
        {
            cout << "Stack Empty" << endl;
            return -1;
        }
        return arr[b - 1];
    }
    void display()
    {
        for (int i = f; i < b; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    bool empty()
    {
        if(f==b)
            return true;
        return false;
    }
};

int main()
{
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.display();
    cout << q.size() << endl;
    q.pop();
    q.display();
    cout << q.size() << endl;
    cout <<q.front()<< endl;
    q.display();
    cout << q.size() << endl;
    cout <<q.back()<< endl;
    q.display();
    cout << q.size() << endl;
}