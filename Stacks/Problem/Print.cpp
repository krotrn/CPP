#include<iostream>
#include<stack>
using namespace std;

void display(stack<int> &st){
    if(st.size() == 0)
        return;
    int x = st.top();
    st.pop();
    display(st);
    cout << x << " ";
    st.push(x);
}

int main()
{
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    display(st);
}