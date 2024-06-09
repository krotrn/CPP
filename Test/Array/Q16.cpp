#include<iostream>
#include<vector>
using namespace std;
vector<int> common(vector<int>& a,int m,vector<int>& b,int n){
    vector<int> v;
    for(int i=0,j=0;i<m,j<n; ){
        if(a[i]==b[j]) v.push_back(a[i]),i++,j++;
        else if(a[i]<b[j]) i++;
        else j++;
    }
    return v;
}
int main(){
    cout<<"Enter the no. of elements in 1st array : ";
    int m;
    cin>>m;
    cout<<"Enter the elements : "<<endl;
    vector<int> a(m);
    for(int i=0; i<m; i++) cin>>a[i];
    cout<<"Enter the no. of elements in 2nd array : ";
    int n;
    cin>>n;
    cout<<"Enter the elements : "<<endl;
    vector<int> b(n);
    for(int i=0; i<n; i++) cin>>b[i];
    cout<<"Enter the no. of elements in 3rd array : ";
    int l;
    cin>>l;
    cout<<"Enter the elements : "<<endl;
    vector<int> c(l);
    for(int i=0; i<l; i++) cin>>c[i];
    vector<int> v=common(a,m,b,n);
    vector<int> r=common(v,v.size(),c,l);
    cout<<"Common Elements are : ";
    for(int i=0; i<r.size();i++){
        cout<<r[i]<<" ";
    }
}