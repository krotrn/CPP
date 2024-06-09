#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(0);
    v.push_back(1);
    v.push_back(0);
    v.push_back(1);
    v.push_back(1);
    v.push_back(0);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    int noz=0,noo=0;
    for(int i=0;i<v.size();i++){
        if(v[i]==0){
            noz++;
        }
        else{
            noo++;
        }
    }
    for(int i=0;i<v.size();i++){
       if(i<noz) v[i]=0;
       else v[i]=1;
    }
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}