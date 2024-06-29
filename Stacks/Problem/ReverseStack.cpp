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

void reverse(stack<int> &st){
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
    while(help.size()){
        st.push(help.top());
        help.pop();
    }
}

void pushAtBottomRec(stack<int> &st, int item){
    if(st.size() == 0)
    {
        st.push(item);
        return;
    }
    int x = st.top();
    st.pop();
    pushAtBottomRec(st,item);
    st.push(x);
}

void reverseRec(stack<int> &st){
    if(st.size()==1)
        return;
    int x = st.top();
    st.pop();
    reverseRec(st);
    pushAtBottomRec(st, x);
}

int main(){
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    display(st);
    cout << endl;
    reverseRec(st);
    display(st);
}