#include<iostream>
#include<vector>
using namespace std;

class Stack{
    vector<int> arr;
    int idx = -1;
public:
    int size() {
        return idx + 1;
    }
    void push(int val) {
        arr.push_back(val);
        idx++;
    }
    void pop() {
        if(idx == -1){
            cout << "Stack Underflow" << endl;
            return;
        }
        arr.pop_back();
        idx--;
    }
    int top() {
        if(idx == -1){
            cout << "Stack Empty" << endl;
            return -1;
        }
        return arr[idx];
    }
    void display(){
        for (int i : arr)
            cout <<i<< " ";
        cout << endl;
    }
};

int main(){
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
    st.display();
    cout << st.size() << endl;
    cout << st.top() << endl;
    st.pop();
    st.display();
    cout << st.size() << endl;
    cout << st.top() << endl;
}