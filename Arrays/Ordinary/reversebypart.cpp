#include<iostream>
#include<vector>
using namespace std;
void display(vector<int>& a){
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void rev(int a,int b,vector<int>& c){
    for(int i=a-1, j=b;i<=j;i++,j--){
        int t=c[i];
        c[i]=c[j];
        c[j]=t;
    }
}
int main(){
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(6);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(7);
    v1.push_back(4);
    display(v1);
    int a,b;
    cout<<"Enter the starting position ";
    cin>>a;
    cout<<"Enter the ending position ";
    cin>>b;
    rev(a,b,v1);
    display(v1);
}