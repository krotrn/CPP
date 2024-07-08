#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void display(queue<int> &q){
    int n=q.size();
    int i = 0;
    while(i<n){
        cout<<q.front()<<" ";
        q.push(q.front());
        q.pop();
        i++;
    }
    cout<<endl;
}

void removeAtEven(queue<int> &q){
    int n = q.size();
    int i = 0;
    while(i<n){
        if(i%2)
            q.push(q.front());
        q.pop();
        i++;
    }
    return;
}

int main(){
    queue<int> q;
    cout<<"Enter the number of elements: ";
    int n;
    cin>>n;
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        q.push(x);
    }
    display(q);
    removeAtEven(q);
    display(q);

}