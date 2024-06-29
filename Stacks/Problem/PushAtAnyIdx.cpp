#include<iostream>
#include<stack>
using namespace std;
void pushAtIdx(stack<int> &st, int idx, int item){
    stack<int> temp;
    while(st.size()>idx){
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

int main(){
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    display(st);
    cout << endl;
    pushAtIdx(st,1,50);
    display(st);
}