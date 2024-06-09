#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector <int> v;
    for(int i=0;i<5;i++){
        int n;
        cin>>n;
        v.push_back(n);
    }
    for(int i=0;i<5;i++){
        cout<<v[i]<<" ";
    }
    for(int i=0;i<5;i++){
        int n;
        cin>>n;
        v.push_back(n);
    }
}