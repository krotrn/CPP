#include<iostream>
#include<climits>
using namespace std;
int main(){
    cout<<"Enter the no. of elements : ";
    int n;
    cin>>n;
    cout<<"Enter the elements : "<<endl;
    int a[n],pro=1,max=INT_MIN;
    bool t=false;
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            pro *= a[j];
            if(pro>max) max=pro;
            if(pro<1) pro=1;
        }
    }
    cout<<max;
}