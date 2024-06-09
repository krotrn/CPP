#include<iostream>
using namespace std;
int main() {
    int n;
    cout<<"Enter no. of element in array : ";
    cin>>n;
    int a[n];
    cout<<"Enter Elements in array : "<<endl;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=0,j=n-1, t; i<j; i++,j--){
        t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
}