#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the no. of elements : ";
    cin>>n;
    cout<<"Enter the elements : "<<endl;
    int a[n];
    bool t=true;
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<n-1; i++){
        t=true;
        for(int j=i+1; j<n;j++){
            if(a[i]==a[j]){
                t=false;
                a[j]=0;
                break;
            }
        }
        if(t=true){
            cout<<a[i];
            break;
        }
    }
}