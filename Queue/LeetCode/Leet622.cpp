#include <iostream>
#include <vector>
using namespace std;

class MyCircularQueue {
public:
    int f;
    int b;
    int s;
    int c;
    vector<int> arr;
    MyCircularQueue(int k) {
        f = 0;
        b = 0;
        s = 0;
        c = k;
        arr.resize(k);
    }
    
    bool enQueue(int value) {
        if(s == c)
            return false;
        arr[b] = value;
        b++;
        if(b == c)
            b = 0;
        s++;
        return true;
    }
    
    bool deQueue() {
        if(s == 0)
            return false;
        f++;
        if(f == c)
            f = 0;
        s--;
        return true;
    }
    
    int Front() {
        if(s == 0)
            return -1;
        return arr[f];
    }
    
    int Rear() {
        if(s == 0)
            return -1;
        if(b == 0)
            return arr[c-1];
        return arr[f];
    }
    
    bool isEmpty() {
        return s == 0;
    }
    
    bool isFull() {
        return s == c;
    }
};


int main()
{
    MyCircularQueue* obj = new MyCircularQueue(3);
    bool param_1 = obj->enQueue(1);
    bool param_2 = obj->enQueue(2);
    bool param_3 = obj->enQueue(3);
    bool param_4 = obj->enQueue(4);
    bool param_5 = obj->deQueue();
    int param_6 = obj->Front();
    int param_7 = obj->Rear();
    bool param_8 = obj->isEmpty();
    bool param_9 = obj->isFull();
    return 0;
}