#include<bits/stdc++.h>
using namespace std;
int main(){
    priority_queue<int, vector<int>, greater<int>> pq; //(min heap) // T.C. O(nlogn) 
    pq.push(10);// T.C. O(logn)
    pq.push(2);
    pq.push(-6);
    pq.push(81);
    cout<<pq.top()<<endl; // T.C. O(1)
    pq.pop();// T.C. O(logn)
    cout<<pq.top()<<endl;
}