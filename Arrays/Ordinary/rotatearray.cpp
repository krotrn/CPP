#include<iostream>
#include<vector>
using namespace std;
void display(vector<int>& a){
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void rev(int a,int b,vector<int>& c){
    for(int i=a, j=b;i<=j;i++,j--){
        int t=c[i];
        c[i]=c[j];
        c[j]=t;
    }
}
int main(){
    vector<int> v;
    cout<<"enter the size of array : ";
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    display(v);
    cout<<"Enter the no. of rotation : ";
    int r;
    cin>>r;
    r=r%(v.size());
    rev(0,n-r-1,v);
    rev(n-r,n-1,v);
    rev(0,n-1,v);
    display(v);
}
