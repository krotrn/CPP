#include<iostream>
#include<climits>
using namespace std;
int main(){
    cout<<"Enter the no. of elements : ";
    int n;
    cin>>n;
    cout<<"Enter the elements : "<<endl;
    int a[n],sum=0,max=INT_MIN;
    bool t=false;
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            sum+=a[j];
            if(sum>max) max=sum;
            if(sum<0) sum=0;
        }
    }
    cout<<max;
}