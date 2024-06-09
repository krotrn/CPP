#include<iostream>
using namespace std;
int main(){
    int m,n;
    cout<<"Enter the row and colomn of 1st matrix : "<<endl;
    cin>>m>>n;
    int a[m][n];
    cout<<"Enter the of 1st matrix : "<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }cout<<endl;
    for(int i=m-1;i>=0;i--){
        if(i%2==0){
            for(int j=0;j<n;j++){
                cout<<a[i][j]<<" ";
            }cout<<endl;
        }
        else{
            for(int j=n-1;j>=0;j--){
                cout<<a[i][j]<<" ";
            }cout<<endl;
        }
    }
}
