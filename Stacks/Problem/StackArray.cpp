#include<iostream>
#include<vector>
using namespace std;

class Stack{
    int arr[5];
    int idx = -1;
public:
    int size() {
        return idx + 1;
    }
    void push(int val) {
        if(idx == 4){
            cout << "Stack Overflow" << endl;
            return;
        }
        idx++;
        arr[idx] = val;
    }
    void pop() {
        if(idx == -1){
            cout << "Stack Underflow" << endl;
            return;
        }
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
        for (int i = 0; i <= idx; i++)
            cout << arr[i] << " ";
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
    st.pop();
    st.display();
    cout << st.size() << endl;
}