#include<iostream>
#include<stack>
using namespace std;
stack<int> copy(stack<int> &st){
    stack<int> temp;
    stack<int> help;
    while(st.size()){
        temp.push(st.top());
        st.pop();
    }
    while(temp.size()){
        help.push(temp.top());
        temp.pop();
    }
    return help;
}

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
    cout << endl;
    stack<int> p = copy(st);
    display(p);
}