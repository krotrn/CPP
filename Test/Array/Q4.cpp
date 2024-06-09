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
    for(int i=0,t; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(a[i]>a[j]){
                t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
    }
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }

}