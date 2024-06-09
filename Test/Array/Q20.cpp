#include<iostream>
using namespace std;
void alter(int a[],int x,int y){
    int t;
    for(int i=x,j=y; i<j; i=i+2,j=j-2){
        t=a[i];
        a[i]=a[j];
        a[j]=t;
    }
}
void display(int a[],int n){
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int main(){
    cout<<"Enter the no. of elements : ";
    int n;
    cin>>n;
    cout<<"Enter the elements : "<<endl;
    int a[n],ne=0,p=0;
    for(int i=0; i<n; i++) {
        cin>>a[i];
        if(a[i]<0) ne++;
        else p++;
    }
    int t;
    for(int i=0,j=n-1;i<j;){
        if(a[i]<0) i++;
        else{
            t=a[i];
            a[i]=a[j];
            a[j]=t;
            j--;
        }
    }
    display(a,n);
    if(ne>p){
        alter(a,1,n-1);
    }
    else if(p>ne){
        alter(a,0,n-2);
    }
    else{
        alter(a,0,n-1);
    }
    display(a,n);
}