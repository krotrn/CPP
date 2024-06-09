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
    for(int i=0; i<n; i++){
        if(a[i] != i+1){
            cout<<i+1;
            return 0;
        }
    }
}