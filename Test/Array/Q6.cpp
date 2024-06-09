#include<iostream>
using namespace std;
int main() {
    int n,t;
    cout<<"Enter no. of element in array : ";
    cin>>n;
    int a[n];
    cout<<"Enter the no. : ";
    int p;
    cin>>p;
    cout<<"Enter Elements in array : "<<endl;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=0; i<n; i++){
        if(a[i]==p) t++;
    }
    cout<<"Number of times "<<p<<" occur is : "<<t;
}