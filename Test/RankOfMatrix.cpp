#include<iostream>
using namespace std;
void mtxin(int a[][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>a[i][j];
        }
        cout<<endl;
    }
}
void mtxout(int a[][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int m[3][3],det;
    cout<<"Enter a Matrix "<<endl;
    mtxin(m);
    cout<<"Your Matrix is "<<endl;
    mtxout(m);
    det=((m[0][0]*((m[1][1]*m[2][2])-m[2][1]*m[1][2]))-(m[0][1]*((m[1][0]*m[2][2])-m[2][0]*m[1][2]))+(m[0][2]*((m[1][0]*m[2][1])-m[1][1]*m[2][0])));
    cout<<"Determinant of this matrix is "<<det<<endl<<"Rank of This Matrix is ";
    if(det==0){
        cout<<"Less Than 3";
    }
    else{
        cout<<"3";
    }
}