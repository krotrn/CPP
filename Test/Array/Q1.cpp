#include<iostream>
using namespace std;
int main() {
    int n, t = 0, p;
    cout<<"Enter no. of element in array : ";
    cin>>n;
    int a[n];
    cout<<"Enter Elements in array : "<<endl;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=0; i<n; i++){
        if(a[i]>a[i-1] && a[i]>a[i+1] && i-1>=0 && i+1<=n-1){
            if(t<a[i]) t = a[i], p=i;
        }
    }
    if(t ==0 && a[0] > a[n-1] ) t = a[0], p=0;
    else if(t==0 && a[n-1] < a[0]) t = a[n-1], p=n-1;
    cout<<"Peak Element is "<<t<<" And its index is "<<p;
}