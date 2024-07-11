// Interleave the first half of the queue with the second half
// Use only one stack 
// even 
#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void interleaave(queue<int> &q){
    stack<int> s;
    int n = q.size();
    // 1 2 3 4 5 6 7 8
    for(int i=0; i<n/2; i++){ // queue -> stack half
        s.push(q.front());
        q.pop();
    }
    // 5 6 7 8 q
    // |1 2 3 4 s
    while(!s.empty()){ // stack -> queue half
        q.push(s.top());
        s.pop();
    }
    // 5 6 7 8 4 3 2 1
    for(int i=0; i<n/2; i++){  // queue -> stack half
        s.push(q.front());
        q.pop();
    }
    
    // 4 3 2 1 q
    // |5 6 7 8 s
    while(!s.empty()){ // stack -> queue(one) and  queue(front) -> queue(back)
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }
    // 8 4 7 3 6 2 5 1
    // make it reverse
    while(q.size()){ // queue -> stack
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){ // stack -> queue
        q.push(s.top());
        s.pop();
    }
}

int main(){
    queue<int> q;
    for(int i=1; i<=8; i++){
        q.push(i);
    }
    interleaave(q);
    while(q.size()){
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}