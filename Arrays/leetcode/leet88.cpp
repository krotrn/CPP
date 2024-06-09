#include<iostream>
#include<vector>
using namespace std;
vector<int> merge(vector<int> &v1,vector<int> &v2){
    int a=v1.size(),b=v2.size();
    vector<int> res(a+b);
    int i=0; //arr1
    int j=0; //arr2
    int k=0; //res
    while(i<a && j<b){
        if(v1[i]<=v2[j]){
            res[k]=v1[i];
            i++;
        }
        else {
            res[k]=v2[j];
            j++;
        }
        k++;
    }
    //for remaining
    if(i==a){
        while(j<b){
            res[k]=v2[j];
            k++;
            j++;
        }
    }
    if(j==b){
        while(i<a){
            res[k]=v1[i];
            k++;
            i++;
        }
    }
    return res;
}
int main(){
    int i=0,j=0,k=0;
    vector<int> arr1;
    arr1.push_back(1);
    arr1.push_back(4);
    arr1.push_back(5);
    arr1.push_back(8);

    vector<int> arr2;
    arr2.push_back(2);
    arr2.push_back(3);
    arr2.push_back(6);
    arr2.push_back(7);
    arr2.push_back(10);
    arr2.push_back(12);
    vector<int> v = merge(arr1,arr2);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}