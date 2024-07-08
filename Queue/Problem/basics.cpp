#include<iostream>
#include<queue>
#include<stack>
using namespace std;


void display(queue<int> &q){
    int n=q.size();
    int i = 0;
    while(i<n){
        cout<<q.front()<<" ";
        q.push(q.front());
        q.pop();
        i++;
    }
    cout<<endl;
}

void reverse(queue<int> &q){
    stack<int> s;
    // empty the queue and push it to stack
    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }
    // empty the stack and push it to queue
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
}



int main(){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    display(q);
    reverse(q);
    display(q);
    return 0;
}