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
    int i=0,j=v.size()-1;
    while(i<j){
        if(v[j]==1) j--;            //or use else if in line 22 and 24
        if(v[i]==0) i++;
        if(i>=j) break;             //or line 24 will go to line 21
        if(v[i]==1 && v[j]==0){
            v[i]=0,v[j]=1;
            i++;
            j--;
        }
    }
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}