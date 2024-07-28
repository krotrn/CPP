#include <bits/stdc++.h>
using namespace std;

class MinHeap
{
    vector<int> heap;
    int capacity;

public:
    int idx = 1;
    MinHeap(int cap)
    {
        this->capacity = cap;
        // next element to be inserted
        this->idx = 1;
        heap.resize(cap + 1);
        heap[0] = INT_MIN;
    }
    int top()
    {
        if (idx == 1)
            return -1;
        return heap[1];
    }
    void push(int val)
    {
        if (idx - 1 == capacity)
            return;
        heap[idx] = val;
        int curr = idx;
        int parent = idx / 2;
        while (curr > 1 && heap[curr] < heap[parent])
        {
            swap(heap[curr], heap[parent]);
            curr = parent;
        }
        idx++;
    }
    int size()
    {
        return idx - 1;
    }
    void pop()
    {
        if (idx == 1)
            return;
        idx--;
        heap[1] = heap[idx];
        int curr = 1;
        while (true)
        {
            int left = 2 * curr;
            int right = 2 * curr + 1;
            // if left child is greater than idx, then it means there is no child
            if(left >= idx)
                break;
            // if right child is greater than idx, then it means there is only left child
            if (right >= idx)
            {
                if (heap[curr] > heap[left])
                    swap(heap[curr], heap[left]);
                curr = left;
                break;
            }
            if (heap[left] < heap[right])
            {
                // if current is less than left child, then break
                if (heap[curr] < heap[left])
                    break;
                swap(heap[curr], heap[left]);
                curr = left;
            }
            else
            {
                // if current is less than right child, then break
                if (heap[curr] < heap[right])
                    break;
                swap(heap[curr], heap[right]);
                curr = right;
            }
        }
    }
    void display()
    {
        for (int i = 1; i < idx; i++)
            cout << heap[i] << " ";
        cout << endl;
    }
};

int main()
{
    MinHeap pq(10);
    pq.push(10);
    pq.push(20);
    pq.push(15);
    pq.push(40);
    pq.push(50);
    pq.push(100);
    pq.display();
    cout << pq.size() << endl;
    cout << pq.top() << endl;
    pq.pop();
    pq.display();
    cout << pq.top() << endl;
    pq.pop();
    pq.display();
    cout << pq.top() << endl;
    cout << pq.size() << endl;
    return 0;
}