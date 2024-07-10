#include<iostream>
#include<queue>
#include<stack>
#include<vector>
using namespace std;

class MyQueue {
public:
    stack<int> s1, s2;
    MyQueue() {
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        while(s1.size()){
            s2.push(s1.top());
            s1.pop();
        }
        int ans = s2.top();
        s2.pop();
        while(s2.size()){
            s1.push(s2.top());
            s2.pop();
        }
        return ans;
    }
    
    int peek() {
        while(s1.size()){
            s2.push(s1.top());
            s1.pop();
        }
        int ans = s2.top();
        while(s2.size()){
            s1.push(s2.top());
            s2.pop();
        }
        return ans;
    }
    
    bool empty() {
        return s1.empty();
    }
};

class MyQueue {
public:
    stack<int> s1, s2;
    MyQueue() {
    }
    
    void push(int x) {
        while(s1.size()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(s2.size()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        int ans = s1.top();
        s1.pop();
        return ans;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};