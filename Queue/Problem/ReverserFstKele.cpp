#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void reverseFirstKElements(queue<int>& q, int k) {
    stack<int> s;
    int n = q.size();
    for(int i = 0; i < k; i++) {
        s.push(q.front());
        q.pop();
    }
    for (int i = 0; i < k; i++)
    {
        q.push(s.top());
        s.pop();
    }
    for (int i = 0; i < n - k; i++)
    {
        q.push(q.front());
        q.pop();
    }
}

int main(){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);
    q.push(90);
    q.push(100);
    int k = 5;
    reverseFirstKElements(q, k);
    int i = 0;
    while(i<q.size()){
        cout << q.front() << " ";
        q.push(q.front());
        q.pop();
        i++;
    }
    return 0;
}