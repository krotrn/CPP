#include<iostream>
using namespace std;
int main(){
    cout<<"Enter the no. of elements : ";
    int n;
    cin>>n;
    cout<<"Enter the elements : "<<endl;
    int a[n],o=0,z=0,c=0;
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<n-1; i++){
        for(int j=i; j<n; j++){
            if(a[j]==0) z++;
            if (a[j]==1) o++;
            if (z==o) c++;
        }
        z=0,o=0;
    }
    cout<<c;
}