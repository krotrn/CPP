#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &heap, int st, int end) // minHeap
{
    int curr = st;
    while (true)
    {
        int left = 2 * curr;
        int right = 2 * curr + 1;
        if (left >= end)
            break;
        if (right >= end)
        {
            if (heap[curr] > heap[left])
                swap(heap[curr], heap[left]);
            curr = left;
            break;
        }
        if (heap[left] < heap[right])
        {
            if (heap[curr] < heap[left])
                break;
            swap(heap[curr], heap[left]);
            curr = left;
        }else{
            if (heap[curr] < heap[right])
                break;
            swap(heap[curr], heap[right]);
            curr = right;
        }
    }
}
int main()
{
    vector<int> heap = {INT_MIN,10,2,14,11,1,4};
    for (int i = heap.size() / 2; i >= 1; i--)
        heapify(heap, i, heap.size());
    for (auto i : heap)
        cout << i << " ";
    return 0;
}