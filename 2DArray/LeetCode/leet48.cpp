#include<iostream>
using namespace std;
int main(){
    int m;
    cout<<"Enter the row colomn of matrix : "<<endl;
    cin>>m;
    
    int a1[m][m];
    cout<<"Enter the of matrix : "<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            cin>>a1[i][j];
        }
    }
    // Transpose of matrix
    for(int i=0;i<m;i++){
        for(int j=i+1;j<m;j++){
            int t = a1[i][j];
            a1[i][j] = a1[j][i];
            a1[j][i] = t;
        }
    }
    // Reverse of matrix
    for (int i = 0; i < n; i++) {
        int start = 0, end = n - 1;
        while (start < end) {
            swap(matrix[i][start], matrix[i][end]);
            start++;
            end--;
        }
    }
    cout<<"The Transpose is : "<<endl;
    for(int i = 0;i<m;i++){
        for(int j=0;j<m;j++){
            cout<<a1[i][j]<<" ";
        }
        cout<<endl;
    }
    /*
        int m = matrix.size();
        for(int i=0;i<m;i++){
        for(int j=i+1;j<m;j++){
            int t = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = t;
        }
    }
        for(int i=0;i<m;i++){
            int t = matrix[i][0];
            matrix[i][0] = matrix[i][m-1];
            matrix[i][m-1] = t;
        }
        return;*/
}