#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    vector<int> v(8);
    cout<<"Enter elements : "<<endl;
    for(int i=0;i<v.size();i++){
        int n;
        cin>>n;
        v[i]=n;
    }
    int i=0,j=v.size()-1;
    while(i<j){
        if(v[j]>0) j--;            //or use else if in line 22 and 24
        if(v[i]<0) i++;
        if(i>=j) break;             //or line 24 will go to line 21
        if(v[i]>0 && v[j]<0){
            int t=v[i];
            v[i]=v[j];
            v[j]=t;
            i++;
            j--;
        }
    }
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}