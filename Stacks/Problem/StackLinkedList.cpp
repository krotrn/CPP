#include <iostream>
using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node() : val(0), next(nullptr){}
    Node(int val) : val(val), next(nullptr){}
    Node(Node *next) : val(0), next(next){}
    Node(int val, Node *next) : val(val), next(next){}
};

class Stack
{
    Node* head = nullptr;
public:
    void print(Node* temp){
        if(temp == nullptr)
            return;
        print(temp->next);
        cout << temp->val << " ";
    }
    void display(){
        print(head);
        cout << endl;
    }
    void push(int val){
        Node *a = new Node(val);
        if(head == nullptr){
            head = a;
            return;
        }
        a->next = head;
        head = a;
        return;
    }
    void pop(){
        if(head == nullptr){
            cout << "Stack Empty" << endl;
            return;
        }
        head = head->next;
    }
    int top(){
        if(head == nullptr){
            cout << "Stack Empty" << endl;
            return -1;
        }
        return head->val;
    }
    int size(){
        if(head == nullptr){
            cout << "Stack Empty" << endl;
            return -14;
        }
        Node *temp = head;
        int i = 0;
        while(temp){ 
            i++;
            temp = temp->next;
        }
        return i;
    }

};

int main()
{
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