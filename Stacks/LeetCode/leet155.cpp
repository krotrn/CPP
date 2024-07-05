
#include <bits/stdc++.h>
using namespace std;

class MinStack
{
public:
    stack<int> st;
    stack<int> helper;
    MinStack()
    {
    }

    void push(int val)
    {
        st.push(val);
        if (helper.empty())
            helper.push(val);
        else
            helper.push(min(val, helper.top()));
    }

    void pop()
    {
        helper.pop();
        st.pop();
    }

    int top()
    {
        return st.top();
    }

    int getMin()
    {
        return helper.top();
    }
};


class MinStack {
public:
   stack<long long> st;
   long long mn;
    MinStack()
    {
        mn = LLONG_MAX;
    }

    void push(int val)
    {
        long long x = (long long)val;
        if(st.empty()) {
            mn = x;
            st.push(x);
        }
        else if(mn>x) {
            st.push(2*x-mn);
            mn = x;
        }
        else st.push(x);
       
    }

    void pop()
    {
        if(st.top()<mn) mn = 2*mn-st.top();
        st.pop();
    }

    int top()
    {
        if(st.top()<mn)
            return (int)mn;
        return (int)st.top();
    }

    int getMin()
    {
        return (int)mn;
    }
};