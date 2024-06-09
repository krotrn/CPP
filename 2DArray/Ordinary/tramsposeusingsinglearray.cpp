#include<iostream>
using namespace std;
int main(){
    int m;
    cout<<"Enter the row colomn of 1st matrix : "<<endl;
    cin>>m;
    
    int a1[m][m];
    cout<<"Enter the of matrix : "<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            cin>>a1[i][j];
        }
    }
    for(int i=0;i<m;i++){
        for(int j=i+1;j<m;j++){
            int t = a1[i][j];
            a1[i][j] = a1[j][i];
            a1[j][i] = t;
        }
    }
    cout<<"The Transpose is : "<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            cout<<a1[i][j]<<" ";
        }
        cout<<endl;
    }
}