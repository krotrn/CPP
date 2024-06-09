#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> v;
    int x,n;
    cout<<"Enter the target ";
    cin>>x;
    cout<<"Enter the size of array ";
    cin>>n;
    cout<<"Enter the elements ";
    for(int i=0;i<n;i++){
        int p;
        cin>>p;
        v.push_back(p);
    }
    for(int i=0;i<v.size()-1;i++){
        for(int j=i+1;j<v.size();j++){
            if(v[i]+v[j]==x){
                cout<<"("<<i<<","<<j<<")"<<" ";
            }
        }
    }
}