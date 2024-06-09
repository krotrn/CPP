#include<iostream>
using namespace std;
int main(){
    int m,n,p,q;
    cout<<"Enter the row colomn of 1st matrix : "<<endl;
    cin>>m>>n;
    
    int a1[m][n],a2[n][m];
    cout<<"Enter the of 1st matrix : "<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>a1[i][j];
        }
    }
    cout<<"The Transpose is : "<<endl;
    for(int j=0;j<n;j++){
        for(int i=0;i<m;i++){
            a2[j][i]=a1[i][j];
        }
    }
    for(int j=0;j<n;j++){
        for(int i=0;i<m;i++){
            cout<<a2[j][i]<<" ";
        }
        cout<<endl;
    }
    /*class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> t(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                t[i][j]=matrix[j][i];
            }
        }
        return t;
    }
};*/
}