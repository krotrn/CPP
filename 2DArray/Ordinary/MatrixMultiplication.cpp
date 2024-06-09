#include<iostream>
using namespace std;
int main(){
    int m,n,p,q;
    cout<<"Enter the row and colomn of 1st matrix : "<<endl;
    cin>>m>>n;
    cout<<"Enter the row and colomn of 2nd matrix : "<<endl;
    cin>>p>>q;
    if(n!=p){
        cout<<"Matrix multiplication is not possible";
        return 0;
    }
    int a1[m][n],a2[p][q];
    cout<<"Enter the of 1st matrix : "<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>a1[i][j];
        }
    }
    cout<<endl;
    cout<<"Enter the of 2nd matrix : "<<endl;
    for(int i=0;i<p;i++){
        for(int j=0;j<q;j++){
            cin>>a2[i][j];
        }
    }
    cout<<endl;
    cout<<"The Multiplication is : "<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<q;j++){
            int a=0;
            for(int k=0;k<n;k++){
                a+= a1[i][k]*a2[k][j];
            }
            cout<<a<<" ";
        }
        cout<<endl;
    }
}