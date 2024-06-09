#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
void swap(int*a ,int* b){
    int t=*a;
    *a=*b;
    *b=t;
}
int main(){
    vector<int> v;
    v.push_back(2);
    v.push_back(0);
    v.push_back(2);
    v.push_back(1);
    v.push_back(1);
    v.push_back(0);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    int n=v.size();
    int l=0,m=0,h=n-1;
    while(m<=h){
        if(v[m]==2){
            swap(&v[m],&v[h]);
            h--;
        }
        if(v[m]==0){
            swap(&v[m],&v[l]);
            l++;
            m++;
        }
        if(v[m]==1){
            m++;
        }
    }
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}