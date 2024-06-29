#include<iostream>
#include<stack>
using namespace std;
void pushAtBottom(stack<int> &st, int item){
    stack<int> temp;
    while(st.size()){
        temp.push(st.top());
        st.pop();
    }
    st.push(item);
    while(temp.size()){
        st.push(temp.top());
        temp.pop();
    }
    return;
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

int main(){
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    display(st);
    cout << endl;
    pushAtBottomRec(st,50);
    display(st);
}