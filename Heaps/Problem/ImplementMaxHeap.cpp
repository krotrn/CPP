#include<bits/stdc++.h>
using namespace std;

class MaxHeap{
    int idx;
    vector<int> heap;
    int capacity;
public:
    MaxHeap(int cap){
        this->capacity = cap;
        heap.resize(cap + 1);
        this->idx = 1;
    }

// MaxHeap functions
    int size(){
        return idx - 1;
    }

    int top(){
        if(idx == 1)
            return -1;
        return heap[1];
    }

    void push(int val){
        if(idx == capacity + 1)
            return;
        heap[idx] = val;
        int curr = idx;
        while(curr > 1 && heap[curr] > heap[curr/2]){
            swap(heap[curr], heap[curr / 2]);
            curr = curr / 2;
        }
        idx++;
    }

    void pop(){
        if(idx == 1)
            return;
        idx--;
        heap[1] = heap[idx];
        int curr = 1;
        while(true){
            int left = 2 * curr;
            int right = 2 * curr + 1;
            // if left is greater than idx, then it means there is no child beacuse it is a complete binary tree
            if(left >= idx)
                break;
            // if right is greater than idx, then it means there is only left child because for left is already checked
            else if(right >= idx){
                // if left child is less than current node, then break
                if(heap[curr] > heap[left])
                    break;
                swap(heap[curr], heap[left]);
                curr = left;
            }
            else{
                // if both children are greater than current node, then swap with the greater one
                if(heap[curr] > heap[left] && heap[curr] > heap[right])
                    break;
                if(heap[left] > heap[right]){
                    swap(heap[curr], heap[left]);
                    curr = left;
                }
                else{
                    swap(heap[curr], heap[right]);
                    curr = right;
                }
            }
        }
    }

    void display(){
        for(int i = 1; i < idx; i++)
            cout << heap[i] << " ";
        cout << endl;
    }
};

int main(){
    MaxHeap pq(10);
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